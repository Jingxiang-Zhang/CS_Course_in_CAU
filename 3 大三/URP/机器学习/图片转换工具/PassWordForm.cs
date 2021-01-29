using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 图片转换工具
{
    public partial class PassWordForm : Form
    {
        public PassWordForm()
        {
            InitializeComponent();
        }

        private void Button_no_Click(object sender, EventArgs e)
        {
            MediumParameter.passWordResult = DialogResult.No;
            this.Close();
        }

        private void Button_yes_Click(object sender, EventArgs e)
        {
            string pwd1 = textBox_pwd.Text;
            string pwd2 = textBox_pwd2.Text;
            if (pwd1 == pwd2)
            {
                MediumParameter.passWordResult = DialogResult.Yes;
                MediumParameter.passWord = pwd1;
                this.Close();
            }
            else
            {
                MessageBox.Show("两次密码不一致！", "错误", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}
