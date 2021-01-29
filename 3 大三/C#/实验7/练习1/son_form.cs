using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 练习1
{
    public partial class son_form : Form
    {
        public son_form()
        {
            InitializeComponent();
        }

        private void Son_form_Resize(object sender, EventArgs e)
        {
            
            richTextBox1.Size = this.Size;
        }

        private void Son_form_Load(object sender, EventArgs e)
        {
            richTextBox1.Size = this.Size;
        }

        private void RichTextBox1_TextChanged(object sender, EventArgs e)
        {
            bool is_change = Parameter.form_change[this.Text];
            if (!is_change)
            {
                this.Text = this.Text + "*";
                Parameter.form_change[this.Text] = true;
            }
        }

        private void Son_form_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (this.Text[this.Text.Length - 1] == '*')
            {
                DialogResult dr = MessageBox.Show("您的文件："+ this.Text.Substring(0, this.Text.Length - 1) + "尚未保存，是否保存？", "是否保存",MessageBoxButtons.YesNo);
                if(dr== DialogResult.Yes)
                {
                    Parameter.this_form.Menu_save_Click(sender, e);
                }
                this.Text = this.Text.Substring(0, this.Text.Length - 1);
            }
            Parameter.form_file.Remove(this.Text);
            Parameter.form_change.Remove(this.Text);
            
        }
    }
}
