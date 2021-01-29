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

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        tools tool;
        public Form1()
        {
            InitializeComponent();
            tools.form = this;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;


            //获取屏幕的宽度和高度

            int w = System.Windows.Forms.SystemInformation.VirtualScreen.Width;
            int h = System.Windows.Forms.SystemInformation.VirtualScreen.Height;

            //设置最大尺寸  和  最小尺寸  （如果没有修改默认值，则不用设置）
            this.MaximumSize = new Size(w, h);
            this.MinimumSize = new Size(w, h);

            //设置窗口位置
            this.Location = new Point(0, 0);

            //设置窗口大小
            this.Width = w;
            this.Height = h;

            //置顶显示

            //this.TopMost = true;
           
            richTextBox1.Width = w - 10;
            richTextBox1.Height = h - 185;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
           // fileDialog.InitialDirectory = "C:\\";    //打开对话框后的初始目录
            fileDialog.Filter = "基因序列文件|*.out";
            fileDialog.RestoreDirectory = false;    //若为false，则打开对话框后为上次的目录。若为true，则为初始目录
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                tools.list.Clear();
                tool = new tools(fileDialog.FileName);
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            
            int index1 = comboBox1.SelectedIndex;
            
            int index2 = comboBox2.SelectedIndex;
            if (index1 < 0)
            {
                index1 = 0;
            }
            if (index2 < 0)
            {
                index2 = 0;
            }
            if (index1 == index2)
            {
                show_same(index1);
            }
            else
            {
                show_different(index1, index2);
            }
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            richTextBox1.Clear();

            int index1 = comboBox1.SelectedIndex;
            int index2 = comboBox2.SelectedIndex;
            if (index1 < 0)
            {
                index1 = 0;
            }
            if (index2 < 0)
            {
                index2 = 0;
            }
            if (index1 == index2)
            {
                show_same(index1);
            }
            else
            {
                show_different(index2, index1);
            }

        }

        private void show_same(int index)
        {
            StringBuilder sb = new StringBuilder();
            ArrayList tempcontent = (ArrayList)tools.list[index];

            for (int i = 0; i < tempcontent.Count; i++)
            {
                sb.Append(tempcontent[i].ToString());
                sb.Append("\n");
            }

            StringBuilder sb2 = new StringBuilder();
            sb2.Append("\n\n001       ");
            int linenum = 1;
            for (int i = 0; i < sb.Length; i++)
            {
                if (sb[i] == '\n')
                {
                    linenum++;
                    sb2.Append("\n\n" + linenum.ToString("D3") + "       ");
                }
                else
                {
                    sb2.Append(sb[i]);
                    sb2.Append(' ');
                }
            }
            richTextBox1.Text = sb2.ToString();
        }


        private void show_different(int index1,int index2)
        {
            ArrayList content1 = (ArrayList)tools.list[index1];
            ArrayList content2 = (ArrayList)tools.list[index2];
            for (int i = 0; i < content1.Count; i++)
            {
                string str1 = content1[i].ToString();
                string str2 = content2[i].ToString();
                bool same = false;
                if(str1 == str2)
                {
                    same = true;
                }
                
                StringBuilder sb = new StringBuilder();
                sb.Append("\n\n" + (i + 1).ToString("D3") + "       ");
                for(int j = 0; j < str1.Length; j++)
                {
                    sb.Append(str1[j]);
                    sb.Append(' ');
                }
                richTextBox1.AppendText(sb.ToString());
                
                if (!same)
                {
                    richTextBox1.SelectionColor = Color.Red;
                    StringBuilder sb2 = new StringBuilder();
                    sb2.Append("\n" + "          ");
                    for (int j = 0; j < str1.Length; j++)
                    {
                        if (str1[j] != str2[j])
                        {
                            sb2.Append(str2[j]);
                        }
                        else
                        {
                            sb2.Append(' ');
                        }
                        sb2.Append(' ');
                    }
                    sb2.Append('\n');
                    richTextBox1.AppendText(sb2.ToString());
                    richTextBox1.SelectionColor = Color.Black;
                }


            }
        }

    }
}
