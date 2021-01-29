using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace work
{
    public partial class Image_form : Form
    {
        public Bitmap bit;
        public Image_form(Bitmap bit)
        {
            this.bit = bit;
            InitializeComponent();
            int width = 800;
            int height = (int)((double)(bit.Height) / (double)bit.Width * 800);
            
            pictureBox1.Width = width;
            pictureBox1.Height = height;
            this.Width = width + 15;
            this.Height = height + 35;

            this.pictureBox1.Image = bit;
            this.pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;

            Variable.Image_list imgt = new Variable.Image_list();
            imgt.img_form = this;
            imgt.pic = bit;

            this.Text = "Image" + Variable.now_count.ToString();
            Variable.now_count += 1;
            Variable.image_form_list.Add(imgt);

        }

        private void Image_form_Resize(object sender, EventArgs e)
        {
            pictureBox1.Width = this.Width - 15;
            pictureBox1.Height = this.Height - 35;
           
        }

        private void Image_form_Activated(object sender, EventArgs e)
        {
            Variable.last_time_act = this;
        }

        private void Image_form_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (Variable.last_time_act != null)
            {
                if (Variable.last_time_act.Text == this.Text)
                {
                    Variable.last_time_act = null;
                }
            }
            for(int i = 0; i < Variable.image_form_list.Count; i++)
            {
                if (this.Text == Variable.image_form_list[i].img_form.Text)
                {
                    Variable.image_form_list.RemoveAt(i);
                    break;
                }
            }

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Image_form_Load(object sender, EventArgs e)
        {

        }
    }
}
