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
    public partial class gamma_form : Form
    {
        public gamma_form()
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
            Variable.gamma = (double)(val) / 10;
            if (radioButton1.Checked)
            {
                Variable.gamma_gray = true;
            }
            else
            {
                Variable.gamma_gray = false;
            }
            this.Close();
        }
    }
}
