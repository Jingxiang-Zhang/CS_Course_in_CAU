using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 作业1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Timer1_Tick(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            g.SmoothingMode = SmoothingMode.AntiAlias;
            RePaint(g);
            timer1.Enabled = false;
        }
        private void RePaint(Graphics g)
        {
            Pen pen = new Pen(Color.Red);
            pen.Width = 10;
            
            g.DrawLine(pen, 20, 15, 20, 700);
            g.DrawBezier(pen, new Point(20, 20),
                new Point(250, 40),
                new Point(250, 0),
                new Point(500, 50));
            g.DrawBezier(pen, new Point(20, 270),
               new Point(250, 290),
               new Point(250, 250),
               new Point(500, 300));
            g.DrawLine(pen, 500, 45, 500, 305);
            pen.Width = 5;
            g.DrawEllipse(new Pen(Color.Red, 5), 80, 50, 120, 120);
            g.DrawEllipse(new Pen(Color.Blue, 5), 200, 50, 120, 120);
            g.DrawEllipse(new Pen(Color.Black, 5), 320, 50, 120, 120);
            g.DrawEllipse(new Pen(Color.Yellow, 5), 140, 130, 120, 120);
            g.DrawEllipse(new Pen(Color.Green, 5), 260, 130, 120, 120);
        }

        private void Form1_Move(object sender, EventArgs e)
        {
            timer1.Enabled = true;
                
        }
    }
}
