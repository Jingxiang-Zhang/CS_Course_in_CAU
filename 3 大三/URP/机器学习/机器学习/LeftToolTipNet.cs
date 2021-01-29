using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 机器学习
{
    public partial class LeftToolTipNet : Form
    {
        public LeftToolTipNet()
        {
            InitializeComponent();
        }

        int width = 250;
        int height = 565;

        public void LeftToolTipNet_SizeChanged(object sender, EventArgs e)
        {
            this.treeView_net.Size = new Size(this.Width - 13, this.Height + 65);
            this.ClientSize = new Size(this.Width, SourceData.MainForm.Height - 105);
            Graphics g = this.CreateGraphics();
            Pen pen = new Pen(System.Drawing.SystemColors.ButtonFace, 2);
            g.DrawRectangle(pen, new Rectangle(0, 0, width - 1, height + 1));
            pen = new Pen(Color.Gray, 2);
            g.DrawRectangle(pen, new Rectangle(0, 0, this.Width - 1, this.Height + 1));
            width = this.Width;
            height = this.Height;
        }


        private void LeftToolTipNet_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.X >= this.Width - 10)
            {
                this.Cursor = Cursors.SizeWE;
            }
            else
            {
                this.Cursor = Cursors.Default;
            }
            if (SourceData.MouthDown)
            {
                this.Width = e.X;
            }
        }
        private void LeftToolTipNet_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.X >= this.Width - 10 || e.Button== MouseButtons.Left)
            {
                SourceData.MouthDown = true;
            }
            else
            {
                SourceData.MouthDown = false;
            }
        }
        private void treeView_net_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void LeftToolTipNet_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                SourceData.MouthDown = false;
            }
        }
        int timer_time = 1;
        private void timer_load_Tick(object sender, EventArgs e)
        {
            if (timer_time-- == 0)
                timer_load.Enabled = false;
            LeftToolTipNet_SizeChanged(sender, e);
        }
    }
}
