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
    public partial class face_form : Form
    {
        public face_form()
        {
            InitializeComponent();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            int val = trackBar1.Value;
            this.label2.Text = val.ToString();
            label2.Text = ((double)(val) / 100 + 1).ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Variable.confirm = true;
            int val = trackBar1.Value;

            Variable.face_scale = (double)(val) / 100 + 1;

            this.Close();
        }
    }
}
