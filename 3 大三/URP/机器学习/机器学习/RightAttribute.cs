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
    public partial class RightAttribute : Form
    {
        public RightAttribute()
        {
            InitializeComponent();

        }
        public void RightAttribute_SizeChanged(object sender, EventArgs e)
        {
            this.ClientSize = new Size(this.Width, SourceData.MainForm.Height - 105);
            this.Location = new Point(SourceData.MainForm.Width - this.Width, 55);
            Graphics g = this.CreateGraphics();
            Pen pen = new Pen(Color.Gray, 2);
            g.DrawRectangle(pen, new Rectangle(0, 0, this.Width - 1, this.Height + 1));
        }
        private void RightAttribute_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                SourceData.MouthDown = false;
            }
        }

        private void RightAttribute_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.X <= 10)
            {
                this.Cursor = Cursors.SizeWE;
            }
            else
            {
                this.Cursor = Cursors.Default;
            }
            if (SourceData.MouthDown)
            {
                int index = SourceData.MouseX - e.X;
                this.Location = new Point(SourceData.MainForm.Width - this.Width - index, 55);
                this.ClientSize = new Size(this.Width + index, SourceData.MainForm.Height - 105);
            }
        }

        private void RightAttribute_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.X <= 10)
            {
                SourceData.MouthDown = true;
                SourceData.MouseX = e.X;
                SourceData.MouseY = e.Y;
            }
            else
            {
                SourceData.MouthDown = false;
            }
        }

        private void RightAttribute_Load(object sender, EventArgs e)
        {

        }
        int timer_time = 1;
        private void timer_load_Tick(object sender, EventArgs e)
        {
            if (timer_time-- == 0)
                timer_load.Enabled = false;
            RightAttribute_SizeChanged(sender, e);

        }
    }
}
