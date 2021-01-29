using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace work
{
    public partial class linear_change : Form
    {
        public linear_change()
        {
            InitializeComponent();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            int val = trackBar1.Value;
            this.label2.Text = ((double)(val) / 10).ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Variable.confirm = true;
            int val = trackBar1.Value;
            Variable.linear_change_contrast= (double)(val) / 10;
            val = trackBar2.Value;
            Variable.linear_change_range = val;

            if (radioButton1.Checked)
            {
                Variable.linear_change_gray = true;
            }
            else
            {
                Variable.linear_change_gray = false;
            }
            this.Close();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            int val = trackBar2.Value;
            this.label3.Text = val.ToString();
        }

        private void linear_change_Load(object sender, EventArgs e)
        {

        }
    }
}
