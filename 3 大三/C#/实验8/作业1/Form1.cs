using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace 作业1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Load_picture_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "图片文件|*.jpg;图片文件|*.png;图片文件|*.gif";
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                FileStream fileStream = new FileStream
                    (openFileDialog.FileName, FileMode.Open, FileAccess.Read);
                Byte[] bt = new Byte[fileStream.Length];
                fileStream.Read(bt, 0, bt.Length);

                MemoryStream memoryStream = new MemoryStream(bt);
                pictureBox1.Image = Image.FromStream(memoryStream);
                fileStream.Close();
                
            }
        }

        private void Save_picture_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "图片文件|*.Jpeg";
            saveFileDialog.FileName = "picture";
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                MemoryStream memoryStream = new MemoryStream();
                pictureBox1.Image.Save(memoryStream, System.Drawing.Imaging.ImageFormat.Jpeg);
                Byte[] bt = new Byte[memoryStream.Length];
                memoryStream.Position = 0;
                memoryStream.Read(bt, 0, (int)memoryStream.Length);
                memoryStream.Close();
                
                FileStream fileStream = new FileStream
                    (saveFileDialog.FileName, FileMode.Create, FileAccess.Write);
                fileStream.Write(bt, 0, bt.Length);
                fileStream.Close();
                MessageBox.Show("图片保存完成");
 
            }
        }
    }
}
