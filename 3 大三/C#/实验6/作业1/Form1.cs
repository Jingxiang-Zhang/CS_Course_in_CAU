using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 作业1
{
    public class BankException : ApplicationException
    {
        public BankException(string reason) : base(reason)
        {
        }
    }
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Button1_Click(object sender, EventArgs e)
        {
            double number1 = Convert.ToDouble(textBox1.Text.Trim());
            double number2 = Convert.ToDouble(textBox2.Text.Trim());
            try
            {
                if (number1 - number2 < 0)
                {
                    throw new BankException("金钱不足！");
                }
                MessageBox.Show("操作成功！", "成功！");
            }
            catch (BankException ex)
            {
                MessageBox.Show("错误原因："+ex.Message,"错误！");
            }
        }
    }
}
