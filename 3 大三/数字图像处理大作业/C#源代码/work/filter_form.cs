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
    public partial class filter_form : Form
    {
        public filter_form()
        {
            InitializeComponent();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            int val = trackBar1.Value;
            this.label2.Text = val.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Variable.confirm = true;
            int val = trackBar1.Value;
            Variable.cornel = val;
            if (radioButton1.Checked)
            {
                Variable.avg_filt = true;
            }
            else
            {
                Variable.avg_filt = false;
            }
            this.Close();
        }
    }
}
