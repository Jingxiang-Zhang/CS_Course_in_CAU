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
    public partial class add_form : Form
    {
        public add_form()
        {
            InitializeComponent();
            for(int i = 0;i< Variable.image_form_list.Count; i++)
            {
                comboBox1.Items.Add(Variable.image_form_list[i].img_form.Text);
            }

            
        }

        private void add_form_Load(object sender, EventArgs e)
        {

        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            int val = trackBar1.Value;
            label2.Text = ((double)(val) / 100).ToString();
            label3.Text = ((100-(double)(val)) / 100).ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Variable.confirm = true;
            int val = trackBar1.Value;
            Variable.add_rate = (double)(val) / 100;
            if (comboBox1.SelectedIndex >= 0)
            {
                int index = comboBox1.SelectedIndex;
                string path = System.Diagnostics.Process.GetCurrentProcess().MainModule.FileName;
                path = path.Substring(0, path.Length - 8);
                string source_path = path + "deal2.png";

                Variable.image_form_list[index].pic.Save(source_path);
                this.Close();
            }
            else
            {
                Variable.confirm = false;
                MessageBox.Show("必须选择一项图片2的来源", "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            
        }
    }
}
