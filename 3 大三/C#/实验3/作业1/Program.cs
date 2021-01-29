using System;

namespace 作业1
{
    public class Point
    {
        private double x;
        private double y;
        public Point(double x,double y)
        {
            this.x = x;
            this.y = y;
        }
        public Point():this(0,0)
        {
        }
        public static double distant(Point a,Point b)
        {
            return Math.Sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Point p1 = new Point();
            Point p2 = new Point(3, 4);
            Console.WriteLine("两点之间的距离为：{0}", Point.distant(p1, p2));
        }
    }
}

