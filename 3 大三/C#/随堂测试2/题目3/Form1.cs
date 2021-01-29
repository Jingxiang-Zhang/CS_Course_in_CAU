using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 题目3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            listBox1.SelectedIndex = 0;
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (listBox1.SelectedIndex)
            {
                case 0:
                    label2.Text = "大象";
                    break;
                case 1:
                    label2.Text = "狗";
                    break;
                case 2:
                    label2.Text = "猫";
                    break;
                case 3:
                    label2.Text = "青蛙";
                    break;
                case 4:
                    label2.Text = "蛇";
                    break;
                case 5:
                    label2.Text = "兔子";
                    break;
                case 6:
                    label2.Text = "乌龟";
                    break;
            }
        }
    }
}
