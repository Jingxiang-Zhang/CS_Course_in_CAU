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
using System.Drawing.Imaging;

namespace 测试
{
    public partial class Form1 : Form
    {
        

        private void Button1_Click(object sender, EventArgs e)
        {
           
            Bitmap bitmap = new Bitmap(@"C:\Users\lenovo\Pictures\Saved Pictures\timg.jpg");
            MemoryStream memoryStream = new MemoryStream();
            bitmap.Save(memoryStream, ImageFormat.Bmp);

            try {
            byte[] buffer = new byte[memoryStream.Length];
            memoryStream.Read(buffer, 0, buffer.Length);
            memoryStream.Close();
            memoryStream = new MemoryStream(buffer);
                pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
                pictureBox1.Image = Image.FromStream(memoryStream);
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            /*
            byte[] buffer = memoryStream.ToArray();
            memoryStream.Close();
            memoryStream = new MemoryStream(buffer);
            
            */
          
        }


        MemoryStream memoryStream;
        public Form1()
        {
            InitializeComponent();
            FileStream fileStream = new FileStream(@"C:\Users\lenovo\Documents\Diablo III\D3Prefs.txt"
                                                    , FileMode.Open, FileAccess.Read);
            byte[] buffer = new byte[fileStream.Length];
            fileStream.Read(buffer, 0, buffer.Length);

            memoryStream = new MemoryStream(buffer);
        }
        private void Button2_Click(object sender, EventArgs e)
        {
          //  byte[] by = memoryStream.ToArray();
            byte[] by = new byte[memoryStream.Length];
            memoryStream.Read(by, 0, by.Length);
 
            textBox1.Text = Encoding.Default.GetString(by);

         //   memoryStream = new MemoryStream(by);
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            FileStream fileStream = new FileStream(@"C:\Users\lenovo\Documents\Diablo III\D3Prefs.txt"
                                                    , FileMode.Open, FileAccess.Read);
            byte[] buffer = new byte[fileStream.Length];
            fileStream.Read(buffer, 0, buffer.Length);
            MemoryStream memoryStream = new MemoryStream(buffer);

            /*
            byte[] buffer2 = new byte[memoryStream.Length];
            memoryStream.Read(buffer, 0, buffer.Length);
            memoryStream.Close();
            memoryStream = new MemoryStream(buffer);
            */
            /*
            byte[] buffer2 = memoryStream.ToArray();
            memoryStream.Close();
            memoryStream = new MemoryStream(buffer);
            */

            byte[] by = new byte[memoryStream.Length];
            memoryStream.Read(by, 0, by.Length);
            textBox2.Text = Encoding.Default.GetString(by);
        }
    }
}
