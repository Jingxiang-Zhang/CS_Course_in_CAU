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
    public class EmailException : ApplicationException
    {
        public EmailException(string str) : base(str) { }
    }
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Button1_Click(object sender, EventArgs e)
        {
            string email = textBox1.Text.Trim();
            try
            {//1967527237@qq.com
                int index = email.IndexOf("@");
                int lindex = email.LastIndexOf("@");
                if(email=="") throw new EmailException("不能为空");
                if (index != lindex) throw new EmailException("存在多个@");
                if (index == -1) throw new EmailException("无@");
                if((char)email[0]=='_') throw new EmailException("_不能在开头");
                index = email.IndexOf(".");
                lindex = email.LastIndexOf(".");
                if (index != lindex) throw new EmailException("存在多个.");
                if (index == -1) throw new EmailException("无.");
                MessageBox.Show("邮箱验证通过！", "成功！");
            }
            catch(EmailException ex)
            {
                MessageBox.Show("错误为：" + ex.Message, "错误！");
            }
        }
    }
}
