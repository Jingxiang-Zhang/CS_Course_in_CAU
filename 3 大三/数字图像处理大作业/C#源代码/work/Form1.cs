using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace work
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            if (!Method.GetPython())
            {
                DialogResult result = MessageBox.Show(
                     "当前未设置python路径，请设置python，并确保python包含OpenCV与numpy包"
                      , "设置python路径", MessageBoxButtons.YesNo, MessageBoxIcon.Information);
                if (result == DialogResult.Yes)
                {
                    if (!Method.SetPython())
                    {
                        this.对比度CToolStripMenuItem.Enabled = false;
                        this.直方图HToolStripMenuItem.Enabled = false;
                        this.图像相加AToolStripMenuItem.Enabled = false;
                        this.图像滤波FToolStripMenuItem.Enabled = false;
                        this.图像锐化ToolStripMenuItem.Enabled = false;
                        this.人脸检测ToolStripMenuItem.Enabled = false;
                    }
                }

            }

        }

        private void 作者介绍ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Author au = new Author();
            au.ShowDialog();
        }

        private void 打开OToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "JPG文件 | *.jpg| PNG 文件 | *.png| BMP 文件 | *.bmp";
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                FileStream fs = File.OpenRead(openFileDialog.FileName);
                int filelength = (int)fs.Length;
                Byte[] image = new Byte[filelength];
                fs.Read(image, 0, filelength);
                System.Drawing.Image result = System.Drawing.Image.FromStream(fs);
                fs.Close();
                Bitmap bit = new Bitmap(result);

                Image_form form = new Image_form(bit);
                form.MdiParent = this;
                form.Show();

            }
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void 保存ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null) 
            {
                Image_form actForm = Variable.last_time_act;
                SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Filter = "JPG文件 | *.jpg| PNG 文件 | *.png| BMP 文件 | *.bmp";
                saveFileDialog.FileName = actForm.Text;
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    string fileName = saveFileDialog.FileName;
                    string strFilExtn = fileName.Remove(0, fileName.Length - 3);

                    switch (strFilExtn)
                    {
                        case "bmp":
                            actForm.bit.Save(fileName, System.Drawing.Imaging.ImageFormat.Bmp);
                            break;
                        case "jpg":
                            actForm.bit.Save(fileName, System.Drawing.Imaging.ImageFormat.Jpeg);
                            break;
                        case "png":
                            actForm.bit.Save(fileName, System.Drawing.Imaging.ImageFormat.Png);
                            break;
                        default:
                            break;
                    }

                }
            }
        }

        private void 复制ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                Image_form actForm = Variable.last_time_act;
                Clipboard.SetImage(actForm.bit);
                timer1.Enabled = true;
                this.Text = "数字图像处理（复制成功）";
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.Text = "数字图像处理";
            timer1.Enabled = false;
        }

        private void 粘贴ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Image img;
            if (System.Windows.Forms.Clipboard.ContainsImage())
            {
                img = System.Windows.Forms.Clipboard.GetImage();
                Bitmap bit = new Bitmap(img);
                Image_form form = new Image_form(bit);
                form.MdiParent = this;
                form.Show();
            }

        }

        private void 二值化VToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                this.Text = "数字图像处理（处理中）";
                string[] str = new string[0];
                Bitmap bit = Method.DealImg(Variable.last_time_act.bit, "otsu", str);
                Image_form form = new Image_form(bit);
                form.MdiParent = this;
                form.Show();
                this.Text = "数字图像处理";
            }
        }

        private void 灰度化GToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                this.Text = "数字图像处理（处理中）";
                string[] str = new string[0];
                Bitmap bit = Method.DealImg(Variable.last_time_act.bit, "gray", str);
                Image_form form = new Image_form(bit);
                form.MdiParent = this;
                form.Show();
                this.Text = "数字图像处理";
            }
        }

        private void 设置python路径ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Method.SetPython())
            {
                this.对比度CToolStripMenuItem.Enabled = true;
                this.直方图HToolStripMenuItem.Enabled = true;
                this.图像相加AToolStripMenuItem.Enabled = true;
                this.图像滤波FToolStripMenuItem.Enabled = true;
                this.图像锐化ToolStripMenuItem.Enabled = true;
                this.人脸检测ToolStripMenuItem.Enabled = true;
            }
        }

        private void 线性变换LToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                linear_change form = new linear_change();
                form.ShowDialog();
                if (Variable.confirm)
                {
                    Variable.confirm = false;
                    this.Text = "数字图像处理（处理中）";
                    string[] str = new string[2];
                    str[0] = Variable.linear_change_range.ToString();
                    str[1] = Variable.linear_change_contrast.ToString();
                    Bitmap bit;
                    if (Variable.linear_change_gray)
                    {
                        bit = Method.DealImg(Variable.last_time_act.bit, "contrastgray", str);
                    }
                    else
                    {
                        bit = Method.DealImg(Variable.last_time_act.bit, "contrastrgb", str);
                    }
                    Image_form form2 = new Image_form(bit);
                    form2.MdiParent = this;
                    form2.Show();
                    this.Text = "数字图像处理";
                }
            }
            
        }

        private void 伽马调整GToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                gamma_form form = new gamma_form();
                form.ShowDialog();
                if (Variable.confirm)
                {
                    Variable.confirm = false;
                    this.Text = "数字图像处理（处理中）";
                    string[] str = new string[1];
                    str[0] = Variable.gamma.ToString();
                    Bitmap bit;
                    if (Variable.gamma_gray)
                    {
                        bit = Method.DealImg(Variable.last_time_act.bit, "gammagray", str);
                    }
                    else
                    {
                        bit = Method.DealImg(Variable.last_time_act.bit, "gammargb", str);
                    }
                    Image_form form2 = new Image_form(bit);
                    form2.MdiParent = this;
                    form2.Show();
                    this.Text = "数字图像处理";
                }
            }
        }

        private void 灰度ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                this.Text = "数字图像处理（处理中）";
                string[] str = new string[0];
                Bitmap bit = Method.DealImg(Variable.last_time_act.bit, "histgray", str);
                Image_form form = new Image_form(bit);
                form.MdiParent = this;
                form.Show();
                this.Text = "数字图像处理";
            }
        }

        private void rGB直方图CToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                this.Text = "数字图像处理（处理中）";
                string[] str = new string[0];
                Bitmap bit = Method.DealImg(Variable.last_time_act.bit, "histrgb", str);
                Image_form form = new Image_form(bit);
                form.MdiParent = this;
                form.Show();
                this.Text = "数字图像处理";
            }
        }

        private void 图像相加AToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                add_form form = new add_form();
                form.ShowDialog();
                if (Variable.confirm)
                {
                    Variable.confirm = false;
                    this.Text = "数字图像处理（处理中）";
                    
                    string[] str = new string[2];
                    string path = System.Diagnostics.Process.GetCurrentProcess().MainModule.FileName;
                    path = path.Substring(0, path.Length - 8);
                    path = path + "deal2.png";
                   
                    str[0] = path;
                    str[1] = Variable.add_rate.ToString();
                    Bitmap bit;
                    bit = Method.DealImg(Variable.last_time_act.bit, "add", str);

                    Image_form form2 = new Image_form(bit);
                    form2.MdiParent = this;
                    form2.Show();
                    
                    this.Text = "数字图像处理";
                }
            }
        }

        private void 图像滤波FToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                filter_form form = new filter_form();
                form.ShowDialog();
                if (Variable.confirm)
                {
                    Variable.confirm = false;
                    this.Text = "数字图像处理（处理中）";
                    
                    string[] str = new string[1];
                    str[0] = Variable.cornel.ToString();
                    Bitmap bit;
                    if (Variable.avg_filt)
                    {
                        bit = Method.DealImg(Variable.last_time_act.bit, "avgfilter", str);
                    }
                    else
                    {
                        bit = Method.DealImg(Variable.last_time_act.bit, "meanfilter", str);
                    }
                    Image_form form2 = new Image_form(bit);
                    form2.MdiParent = this;
                    form2.Show();
                    
                    this.Text = "数字图像处理";
                }
            }
        }

        private void 图像锐化ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                this.Text = "数字图像处理（处理中）";
                string[] str = new string[0];
                Bitmap bit = Method.DealImg(Variable.last_time_act.bit, "acute", str);
                Image_form form = new Image_form(bit);
                form.MdiParent = this;
                form.Show();
                this.Text = "数字图像处理";
            }
        }

        private void 人脸检测ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                face_form form = new face_form();
                form.ShowDialog();
                if (Variable.confirm)
                {
                    Variable.confirm = false;
                    this.Text = "数字图像处理（处理中）";
                    string[] str = new string[2];
                    string path = System.Diagnostics.Process.GetCurrentProcess().MainModule.FileName;
                    path = path.Substring(0, path.Length - 8);
                    path = path + "face.xml";
                    str[0] = path;
                    str[1] = Variable.face_scale.ToString();
                    Bitmap bit;          
                    bit = Method.DealImg(Variable.last_time_act.bit, "facedect", str);
                    Image_form form2 = new Image_form(bit);
                    form2.MdiParent = this;
                    form2.Show();
                    
                    this.Text = "数字图像处理";
                }
            }
        }
    }
}
