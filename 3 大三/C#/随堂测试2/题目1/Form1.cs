using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 题目1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.pictureBox1.Location = new Point(680, 250);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (button1.Text == "Start")
            {
                button1.Text = "Stop";
                timer1.Enabled = true;
            }
            else
            {
                button1.Text = "Start";
                timer1.Enabled = false;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int height = pictureBox1.Location.Y;
            int width = pictureBox1.Location.X;
            width = width - 5;
            if (width <= 0) width = 680;
            pictureBox1.Location = new Point(width, height);
        }
    }
}
