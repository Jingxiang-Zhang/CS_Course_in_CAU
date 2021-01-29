using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 人工智能实验5
{   
    public class InformationReturn
    {

    }
    public class PointInfo
    {
        public Point nowpoint;
        public Point fatherPoint;
        public int nowStep;
        public int futureStep;
        public int sumStep;
        public PointInfo pointInfoPointer;
    }
    public static class Aasterisk
    {

        public static bool Asterisk(int height, int width, ref MainForm.state[,] state,
            ref int[,] barricade, Point startPoint, Point endPoint,
            ref PointInfo information, MainForm.GuessMethod guessMethod, int limit
            , ref TimeSpan timeConsume, ref int sumStep)
        {
            DateTime AsteriskBeginTime = DateTime.Now; 
            PointInfo endPointInfo = null;
            //加入第一个节点
            List<PointInfo> openList = new List<PointInfo>();
            List<PointInfo> closeList = new List<PointInfo>();
            PointInfo firstPoint = new PointInfo();
            firstPoint.nowpoint = startPoint;
            firstPoint.fatherPoint = new Point(-1, -1);
            firstPoint.pointInfoPointer = null;
            firstPoint.nowStep = 0;
            firstPoint.futureStep = GuessFutureStep(startPoint,endPoint, 
                ref state, ref barricade, guessMethod);
            firstPoint.sumStep = firstPoint.nowStep + firstPoint.futureStep;
            openList.Add(firstPoint);
            //定义4个方向
            Point[] direction = new Point[4] { new Point(0, 1) , new Point(0, -1) ,
                new Point(1, 0) , new Point(-1, 0) };
            bool successful = false;
            int sumPointExtend = 0;
            while (openList.Count != 0)
            {
                sumPointExtend++;
                if (limit-- == 0) return false;
                //找到最小位置的索引
                int minPointIndex = -1;
                int minPointValue = 1000000;
                for(int i = 0; i < openList.Count; i++)
                {
                    if (openList[i].sumStep < minPointValue)
                    {
                        minPointValue = openList[i].sumStep;
                        minPointIndex = i;
                    }
                }
                //去出并删除openlist的结点
                PointInfo subtractPoint = openList[minPointIndex];
                openList.RemoveAt(minPointIndex);
                //等于结束结点，退出循环
                if (subtractPoint.nowpoint == endPoint)
                {
                    successful = true;
                    endPointInfo = subtractPoint;
                    break;
                }
                //扩展4个结点
                for(int i = 0; i < 4; i++)
                {
                    //计算新节点的全部状态
                    Point extendPoint = new Point(subtractPoint.nowpoint.X + direction[i].X,
                        subtractPoint.nowpoint.Y + direction[i].Y);
                    int extendPointFutureStep = GuessFutureStep(extendPoint, endPoint,
                        ref state, ref barricade, guessMethod);
                    int extendPointNowStep = subtractPoint.nowStep + 1;
                    int extendPointSumStep = extendPointFutureStep + extendPointNowStep;
                    if (extendPoint.X < 0 || extendPoint.X >= width ||
                        extendPoint.Y < 0 || extendPoint.Y >= height)
                        continue;
                    if (state[extendPoint.X, extendPoint.Y] == MainForm.state.wall)
                        continue;
                    if (state[extendPoint.X, extendPoint.Y] == MainForm.state.barricade)
                    {
                        extendPointNowStep += barricade[extendPoint.X, extendPoint.Y];
                    }


                    bool extendPointFinished = false;
                    //如果在open表中找到子状态，并且子状态的步数>新的结点，则改变子状态
                    for(int j = 0; j < openList.Count; j++)
                    {
                        if (openList[j].nowpoint == extendPoint)
                        {
                            if (extendPointNowStep < openList[j].nowStep)
                            {
                                openList[j].nowStep = extendPointNowStep;
                                openList[j].sumStep = extendPointSumStep;
                                openList[j].fatherPoint = subtractPoint.nowpoint;
                                openList[j].pointInfoPointer = subtractPoint;
                            }
                            extendPointFinished = true;
                            break;
                        }
                    }
                    //如果在close表中找到了子状态，并且状态步数>新的结点，则改变close表状态并加入
                    //open表中
                    if (extendPointFinished == false)
                    {
                        for (int j = 0; j < closeList.Count; j++)
                        {
                            if (closeList[j].nowpoint == extendPoint)
                            {
                                if (extendPointNowStep < closeList[j].nowStep)
                                {
                                    closeList.RemoveAt(j);
                                    PointInfo tempPoint = new PointInfo();
                                    tempPoint.nowpoint = extendPoint;
                                    tempPoint.fatherPoint = subtractPoint.nowpoint;
                                    tempPoint.pointInfoPointer = subtractPoint;
                                    tempPoint.nowStep=extendPointNowStep;
                                    tempPoint.futureStep = extendPointFutureStep;
                                    tempPoint.sumStep = extendPointSumStep;
                                    openList.Add(tempPoint);
                                }
                                extendPointFinished = true;
                                break;
                            }
                        }
                    }
                    //如果都没有，则直接加入到open表中
                    if (extendPointFinished == false)
                    {
                        PointInfo tempPoint = new PointInfo();
                        tempPoint.nowpoint = extendPoint;
                        tempPoint.fatherPoint = subtractPoint.nowpoint;
                        tempPoint.pointInfoPointer = subtractPoint;
                        tempPoint.nowStep = extendPointNowStep;
                        tempPoint.futureStep = extendPointFutureStep;
                        tempPoint.sumStep = extendPointSumStep;
                        openList.Add(tempPoint);
                    }
                }
            }
            DateTime AsteriskEndTime = DateTime.Now;
            TimeSpan timeSpen = AsteriskEndTime - AsteriskBeginTime;
            timeConsume = timeSpen;
            sumStep = sumPointExtend;
            if (successful == false)
            {
                return false;
            }
            information = endPointInfo;
            return true;
        }
        public static int GuessFutureStep(Point point1, Point point2,
            ref MainForm.state[,] state, ref int[,] barricade, MainForm.GuessMethod guessMethod)
        {
            if (guessMethod == MainForm.GuessMethod.ManhattanDistance)
            {
                return Math.Abs(point1.X - point2.X) + Math.Abs(point1.Y - point2.Y);
            }
            else if(guessMethod == MainForm.GuessMethod.EuclideanDistance)
            {
                return (int)Math.Sqrt((point1.X - point2.X) * (point1.X - point2.X) +
                                        (point1.Y - point2.Y) * (point1.Y - point2.Y));
            }
            else if(guessMethod == MainForm.GuessMethod.ChebyshevDistance)
            {
                return Math.Max(Math.Abs(point1.X - point2.X), Math.Abs(point1.Y - point2.Y));
            }
            else return 0;
        }
    }
}
