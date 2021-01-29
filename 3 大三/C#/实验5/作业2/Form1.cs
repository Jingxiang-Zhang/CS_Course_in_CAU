using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 作业2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            pictureBox1.ImageLocation = "bg.jpg";
            pictureBox1.Visible = false;
        }
        private bool Judge(string str)
        {
            if (str.Length != 18)
            {
                return false;
            }
            string birthday = str.Substring(6, 8);
            DateTime dt = new DateTime(Convert.ToInt32(birthday.Substring(0, 4)),
                                     Convert.ToInt32(birthday.Substring(4, 2)),
                                     Convert.ToInt32(birthday.Substring(6, 2)));
            DateTime odt = new DateTime();
            odt = DateTime.Now;
            TimeSpan sp =odt - dt;
            if (sp.Days <= 365 * 18)
            {
                MessageBox.Show("星空浩瀚无垠，你的年龄太小，看不懂","抱歉");
                return false;
            }
            return true;
        }
        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
            if (Judge(textBox1.Text))
            {
                textBox1.Visible = false;
                label1.Visible = false;
                pictureBox1.Visible = true;
            }
        }
        private void TextBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && e.KeyChar != 8 &&
               e.KeyChar != 1 && e.KeyChar != 3 && e.KeyChar != 22
               && e.KeyChar != 'x')
            {
                e.Handled = true;
            }
            if (textBox1.Text.Length > 17 && e.KeyChar != 8 &&
                e.KeyChar != 1 && e.KeyChar != 3 && e.KeyChar != 22)
            {
                e.Handled = true;
            }
        }
    }
}
