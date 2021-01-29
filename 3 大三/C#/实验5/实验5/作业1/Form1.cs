using System;
using System.Collections;
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
    public partial class Form1 : Form
    {
        int num1;
        int num2;
        bool stop;
        public Form1()
        {
            InitializeComponent();
            stop = false;
            label_time.Visible = false;
            label_second.Visible = false;
            label_correct_text.Visible = false;
            label_correct.Visible = false;
            result.Visible = false;
            number1.Visible = false;
            number2.Visible = false;
            label_add.Visible = false;
            label_equal.Visible = false;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            string temp = label_time.Text.Trim();
            int temp2 = Convert.ToInt32(temp) - 1;
            label_time.Text = temp2.ToString();
            if (temp2 == 0)
            {
                string str = "时间到！您一共作对了" + label_correct.Text+ "道题";
                timer.Enabled = false;
                MessageBox.Show(str,"时间到");
                this.Close();
            }
        }
        private void Button_start_Click(object sender, EventArgs e)
        {
            label_time.Visible = true;
            label_second.Visible = true;
            label_correct_text.Visible = true;
            label_correct.Visible = true;
            label_time.Text = "60";
            label_correct.Text = "0";
            timer.Enabled = true;
            button_start.Enabled = false;

            result.Visible = true;
            number1.Visible = true;
            number2.Visible = true;
            label_add.Visible = true;
            label_equal.Visible = true;
            label_stop.Enabled = true;
            timer.Enabled = true;
            label_stop.Text = "暂停";

            while (true)
            {
                Random random = new Random();
                num1 = random.Next(100);
                num2 = random.Next(100);
                if (num1 + num2 <= 100)
                {
                    number1.Text = num1.ToString();
                    number2.Text = num2.ToString();
                    break;
                }
                else continue;
            }
        }
        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
            if (result.Text!="" && Convert.ToInt32(result.Text.Trim()) == num1 + num2)
            {
                string temp = label_correct.Text.Trim();
                int temp2 = Convert.ToInt32(temp) + 1;
                label_correct.Text = temp2.ToString();
                while (true)
                {
                    Random random = new Random();
                    num1 = random.Next(100);
                    num2 = random.Next(100);
                    if (num1 + num2 <= 100)
                    {
                        number1.Text = num1.ToString();
                        number2.Text = num2.ToString();
                        result.Text = "";
                        break;
                    }
                    else continue;
                }
            }
        }
        private void Result_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && e.KeyChar != 8 &&
                e.KeyChar != 1 && e.KeyChar != 3 && e.KeyChar != 22)
            {
                e.Handled = true;
            }
            if (result.Text.Length > 2 && e.KeyChar != 8 &&
                e.KeyChar != 1 && e.KeyChar != 3 && e.KeyChar != 22)
            {
                e.Handled = true;
            }
        }
        private void Label_end_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        private void Label_stop_Click(object sender, EventArgs e)
        {
            button_start.Enabled = true;
            if (stop)
            {
                stop = false;
                label_stop.Text = "暂停"; 
                timer.Enabled = true;
                result.Enabled = true;
            }
            else
            {
                stop = true;
                label_stop.Text = "继续";
                timer.Enabled = false;
                result.Enabled = false;
            }

        }
    }
}
