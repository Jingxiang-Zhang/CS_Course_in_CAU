using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
           
   
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Pen pen = new Pen(Color.Black);
            g.DrawLine(pen, 100, 100, 500, 500);
            g.DrawLine(pen, 1, 1, 600, 1);
            g.DrawLine(pen, 1, 1, 1, 250);
            g.DrawLine(pen, 1, 1, 1, 250);
        }
    }
}
