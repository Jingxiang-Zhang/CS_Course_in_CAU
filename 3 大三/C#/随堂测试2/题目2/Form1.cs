using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 题目2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            listBox1.SelectedIndex = 0;
            radioButton_man.Checked = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            
            if (openFileDialog.ShowDialog()== DialogResult.OK)
            {
                this.pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
                this.pictureBox1.Image = Image.FromFile(openFileDialog.FileName);
                location_ = openFileDialog.FileName;
            }
        }
        string location_;
        private void button1_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.label_name.Text = textBox1.Text;
            string sex;
            if (radioButton_man.Checked) sex = "男";
            else sex = "女";
            form2.label_sex.Text = sex;
            form2.label_loc.Text = comboBox1.SelectedText;
            switch (listBox1.SelectedIndex)
            {
                case 0:
                    form2.label_degree.Text = "大学";
                    break;
            }
            
            string interest = "";
            if (checkBox1.Checked)
                interest += "运动";
            if (checkBox2.Checked)
                interest += "音乐";
            if (checkBox3.Checked)
                interest += "旅游";
            form2.label_int.Text = interest;
            form2.label_loc.Text = location_;
            form2.label_other.Text = textBox2.Text;
            form2.ShowDialog();
        }
    }
}
