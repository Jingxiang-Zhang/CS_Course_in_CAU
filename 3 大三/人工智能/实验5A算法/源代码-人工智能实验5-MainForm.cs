using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 人工智能实验5
{
    
    public partial class MainForm : Form
    {
        //记录所有的图片box
        public List<List<PictureBox>> mazeshow;
        //记录图片box的起点位置
        public static int boxStartX=50;
        public static int boxStartY=180;
        public static int boxGap = 55;
        public static int boxSize = 50;
        //记录起点和终点的位置
        Point startPoint = new Point(-1, -1);
        Point endPoint = new Point(-1, -1);
        //记录迷宫的状态
        public enum state
        {
            none,
            start,
            end,
            wall,
            barricade
        }
        public enum GuessMethod
        {
            ManhattanDistance,
            EuclideanDistance,
            ChebyshevDistance
        }
        //maze为迷宫的位置，barricademaze为如果是障碍，则障碍值为多少
        public state[,] maze;
        public int[,] barricadeMzae;
        public MainForm()
        {
            InitializeComponent();
            pictureBox_asteriskStartX = pictureBox_asterisk.Location.X;
            pictureBox_asteriskStartY = pictureBox_asterisk.Location.Y;
            pictureBox_flagStartX = pictureBox_flag.Location.X;
            pictureBox_flagStartY = pictureBox_flag.Location.Y;
            comboBox1.SelectedIndex = 0;

        }
        private void MainForm_Load(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.StartPosition = FormStartPosition.CenterParent;
            form1.ShowDialog();
            this.Height = Maze.width * 55 + 230;
            this.Width = Maze.height * 55 + 120;
            mazeshow = new List<List<PictureBox>>();
            maze = new state[Maze.height, Maze.width];
            barricadeMzae=new int[Maze.height, Maze.width];
            for (int i = 0; i < Maze.height; i++)
            {
                List<PictureBox> pictures = new List<PictureBox>();
                for(int j = 0; j < Maze.width; j++)
                {
                    //设定一个picturebox
                    PictureBox box = new PictureBox();
                    box.Location = new Point(boxStartX + i * boxGap, boxStartY + j * boxGap);
                    box.Name = i.ToString() + "," + j.ToString();
                    box.Size = new Size(boxSize, boxSize);
                    box.TabStop = false;
                    box.MouseClick += Box_MouseDown;
                    //绘制一个空白图片
                    box.Image = Image.FromStream(getByColor(Color.White, boxBorder.noBorder));
                    //添加picturebox到窗口里
                    box.SizeMode = PictureBoxSizeMode.StretchImage;
                    this.Controls.Add(box);
                    pictures.Add(box);
                    //初始化maze和barricademaze
                    maze[i, j] = state.none;
                }
                mazeshow.Add(pictures);
            }
        }
        private void Box_MouseDown(object sender, MouseEventArgs e)
        {
            PictureBox pic = (PictureBox)sender;
            string[] name = pic.Name.Split(',');
            int boxX = Convert.ToInt32(name[0]);
            int boxY = Convert.ToInt32(name[1]);
            if (radioButton1.Checked)
            {
                pic.Image = Image.FromStream(getByColor(Color.White, boxBorder.noBorder));
                maze[boxX, boxY] = state.none;
            }
            if (radioButton2.Checked)
            {
                pic.Image = Image.FromStream(getByColor(Color.Black, boxBorder.noBorder));
                maze[boxX, boxY] = state.wall;
            }
            if (radioButton3.Checked)
            {
                int val = trackBar_bar.Value;
                Color color = Color.FromArgb(255 - val * 30, 255 - val * 30, 255- val * 30);
                pic.Image = Image.FromStream(getByColor(color, boxBorder.noBorder));
                maze[boxX, boxY] = state.barricade;
                barricadeMzae[boxX, boxY] = val;
            }
        }
        enum boxBorder
        {
            noBorder,
            hasBorder
        }
        private MemoryStream getByColor(Color color, boxBorder border)
        {
            Bitmap bitmap = new Bitmap(boxSize, boxSize);
            SolidBrush b = new SolidBrush(color);
            Graphics g = Graphics.FromImage(bitmap);
            g.FillRectangle(b, 0, 0, boxSize, boxSize);
            if(border== boxBorder.hasBorder)
            {
                Pen pen = new Pen(Color.Green);
                g.DrawRectangle(pen, 1, 1, boxSize - 2, boxSize - 2);
            }
            MemoryStream stream = new MemoryStream();
            bitmap.Save(stream, System.Drawing.Imaging.ImageFormat.Png);
            return stream;
        }
        bool asteriskMouseDown = false;  //鼠标是否点下
        bool asteriskMoveTure = false;   //图片是否移动到了合理位置
        int pictureBox_asteriskStartX;   //在初始化里，设定初始位置，用于图片
        int pictureBox_asteriskStartY;   //    没有移动的时候的从新设的

        private void pictureBox_asterisk_MouseDown(object sender, MouseEventArgs e)
        {
            asteriskMouseDown = true;
        }

        private void pictureBox_asterisk_MouseMove(object sender, MouseEventArgs e)
        {
            if (asteriskMouseDown)
            {
                label_endT.Visible = false;
                label_end.Visible = false;
                int X = this.PointToClient(Control.MousePosition).X - boxSize / 2;
                int Y = this.PointToClient(Control.MousePosition).Y - boxSize / 2;
                if (reCalPosition(ref X, ref Y, BoxSort.end))
                {
                    asteriskMoveTure = true;
                }
                else
                {
                    asteriskMoveTure = false;
                }
                pictureBox_asterisk.Left = X;
                pictureBox_asterisk.Top = Y;
            }
        }

        private void pictureBox_asterisk_MouseUp(object sender, MouseEventArgs e)
        {
            asteriskMouseDown = false;
            if (asteriskMoveTure == false)
            {
                pictureBox_asterisk.Left = pictureBox_asteriskStartX;
                pictureBox_asterisk.Top = pictureBox_asteriskStartY;
                endPoint.X = -1;
                endPoint.Y = -1;
            }
            else
            {
                label_endT.Visible = true;
                label_end.Text = "(" + endPoint.X.ToString() + "," + endPoint.Y.ToString() + ")";
                label_end.Visible = true;
            }
        }
        enum BoxSort
        {
            start,
            end
        }
        private bool reCalPosition(ref int X, ref int Y, BoxSort box)
        {
            //返回值为是否成功
            for(int i = 0; i < Maze.height; i++)
            {
                for(int j = 0; j < Maze.width; j++)
                {
                    if ((Math.Abs(boxStartX + boxGap * i - X) <= 15) &&
                        Math.Abs(boxStartY + boxGap * j - Y) <= 15){
                        X = boxStartX + boxGap * i;
                        Y = boxStartY + boxGap * j;
                        if (box == BoxSort.start) 
                        {
                            startPoint.X = i;
                            startPoint.Y = j;
                        }
                        else if(box == BoxSort.end)
                        {
                            endPoint.X = i;
                            endPoint.Y = j;
                        }
                        return true;
                    }
                }
            }
            return false;
        }

        bool flagMouseDown = false;
        bool flagMoveTure = false;
        int pictureBox_flagStartX;
        int pictureBox_flagStartY;
        private void pictureBox_flag_MouseUp(object sender, MouseEventArgs e)
        {
            flagMouseDown = false;
            if (flagMoveTure == false)
            {
                pictureBox_flag.Left = pictureBox_flagStartX;
                pictureBox_flag.Top = pictureBox_flagStartY;
                startPoint.X = -1;
                startPoint.Y = -1;
            }
            else
            {
                label_startT.Visible = true;
                label_start.Text = "(" + startPoint.X.ToString() + "," + startPoint.Y.ToString() + ")";
                label_start.Visible = true;
            }
        }

        private void pictureBox_flag_MouseMove(object sender, MouseEventArgs e)
        {
            if (flagMouseDown)
            {
                label_startT.Visible = false;
                label_start.Visible = false;
                int X = this.PointToClient(Control.MousePosition).X - boxSize / 2;
                int Y = this.PointToClient(Control.MousePosition).Y - boxSize / 2;
                if (reCalPosition(ref X, ref Y, BoxSort.start))
                {
                    flagMoveTure = true;
                }
                else
                {
                    flagMoveTure = false;
                }
                pictureBox_flag.Left = X;
                pictureBox_flag.Top = Y;
            }
        }

        private void pictureBox_flag_MouseDown(object sender, MouseEventArgs e)
        {
            flagMouseDown = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (startPoint == new Point(-1, -1) || endPoint == new Point(-1, -1) || startPoint == endPoint) 
            {
                
                MessageBox.Show("请正确设置起点和终点", "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            GuessMethod guess = GuessMethod.ManhattanDistance;
            switch (comboBox1.SelectedIndex)
            {
                case 0:
                    guess = GuessMethod.ManhattanDistance;
                    break;
                case 1:
                    guess = GuessMethod.EuclideanDistance;
                    break;
                case 2:
                    guess = GuessMethod.ChebyshevDistance;
                    break;
            }
            PointInfo pointInfo=new PointInfo();
            bool result = Aasterisk.Asterisk(Maze.height, Maze.width, ref maze, ref barricadeMzae,
                    startPoint, endPoint, ref pointInfo, guess, 2000, ref timeSpan, ref sumSteps);
            if (result)
            {
                while (pointInfo.pointInfoPointer != null)
                {
                    pointInfos.Add(pointInfo);
                    pointInfo = pointInfo.pointInfoPointer;
                }
                label_clock.Visible = true;
                timer1.Enabled = true;
                button1.Visible = false;
                locationNow = pointInfos.Count - 1;
            }
            else
            {
                MessageBox.Show("没有路径！", "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        List<PointInfo> pointInfos = new List<PointInfo>();
        public int locationNow = 0;
        public int sumSteps = 0;
        TimeSpan timeSpan = new TimeSpan();
        private void timer1_Tick(object sender, EventArgs e)
        {
            pictureBox_person.Visible = true;
            Point point = pointInfos[locationNow].nowpoint;
            Point location = new Point(boxStartX + point.X * boxGap, boxStartY + point.Y * boxGap);
            pictureBox_person.Location = location;
            label_clock.Text = "周期：" + pointInfos[locationNow].nowStep.ToString();
            locationNow--;
            if (locationNow < 0)
            {
                timer1.Enabled = false;
                DialogResult dialogResult = MessageBox.Show("寻路完毕\n" +
                    "总计探索" + sumSteps.ToString() + "次\n" +
                    "总计用时" + timeSpan.ToString().Split(':')[2] + "秒\n" +
                    "重新观看请单击是，重置请单击否",
                    "", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if(dialogResult== DialogResult.Yes)
                {
                    locationNow = pointInfos.Count - 1;
                    timer1.Enabled = true;
                }
                else
                {
                    pictureBox_person.Visible = false;
                    label_clock.Visible = false;
                    button1.Visible = true;
                    label_clock.Text = "周期：0";
                    pointInfos.Clear();
                }
            }
        }
    }
}
