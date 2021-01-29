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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Parameter parameter = new Parameter();
            toolStrip4.Visible = false;
            toolStrip5.Visible = false;
            Parameter.this_form = this;
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Parameter.IsTextChange == false)
            {
                this.Close();
            }
        }

        private void Menu_help_Click(object sender, EventArgs e)
        {
            MessageBox.Show("作者 张靖祥 2017304010413", "版权所有");
        }

        private void Menu_new_Click(object sender, EventArgs e)
        {
            son_form new_form = new son_form();
            new_form.MdiParent = this;
            int i;
            for (i = 1; i < 100; i++)
            {
                if (!Parameter.form_number.Contains(i)) break;
            }
            new_form.Text = "新建项目"+i.ToString();
            new_form.Name = "son_form" + i.ToString();
            Parameter.form_file.Add(new_form.Text,"");
            Parameter.form_number.Add(i);
            Parameter.form_is_close.Add(i);
            Parameter.file_name.Add("");
            Parameter.form_change.Add(new_form.Text, false);
            new_form.Show();
        }

        private void Menu_copy_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form != null)
            {
                active_form.richTextBox1.Copy();
            }
        }

        private void Menu_cut_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form != null)
            {
                active_form.richTextBox1.Cut();
            }
        }

        private void Menu_paste_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form != null)
            {
                active_form.richTextBox1.Paste();
            }
        }

        private void Menu_undo_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form != null)
            {
                active_form.richTextBox1.Undo();
            }
        }

        private void Menu_redo_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form != null)
            {
                active_form.richTextBox1.Redo();
            }
        }

        private void ToolStrip_undo_Click(object sender, EventArgs e)
        {
            Menu_undo_Click(sender, e);
        }

        private void ToolStrip_redo_Click(object sender, EventArgs e)
        {
            Menu_redo_Click(sender, e);
        }

        private void Menu_find_Click(object sender, EventArgs e)
        {
            toolStrip4.Visible = true;
            toolStrip5.Visible = true;
            search_text.Focus();

        }

        private void Menu_replace_Click(object sender, EventArgs e)
        {
            toolStrip4.Visible = true;
            toolStrip5.Visible = true;
            search_text.Focus();
            replace_text.Focus();
        }

        private void ToolStripButton1_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form == null)
            {
                return; 
            }
            if (search_text.Text.Length == 0)
            {
                MessageBox.Show("查找字符串不能为空", "提示", MessageBoxButtons.OK);
            }
            else if (Parameter.find_position > active_form.richTextBox1.Text.Length)
            {
                Parameter.find_position = 0;
            }
            else
            {
                int before_position = Parameter.find_position;
                Parameter.find_position = active_form.richTextBox1.Find(search_text.Text,
                            Parameter.find_position, RichTextBoxFinds.MatchCase);
                if (Parameter.find_position==-1 & before_position>=0 )//如已查到文本底部，提示用户
                {
                    MessageBox.Show("已到文本底部,再次查找将从文本开始处查找", "提示",
                                        MessageBoxButtons.OK);
                    Parameter.find_position = 0;//下次查找的开始位置
                    return;
                }
                else//找到匹配字符串
                {
                    active_form.richTextBox1.Select(Parameter.find_position, search_text.Text.Length);
                    Parameter.find_position += search_text.Text.Length;
                }//下次查找的开始位置在此次找到字符串之后

            }
        }

        private void ToolStripButton2_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form == null)
            {
                return;
            }
            if (search_text.Text.Length == 0)
            {
                MessageBox.Show("查找字符串不能为空", "提示", MessageBoxButtons.OK);
            }
            else
            {
                if (active_form.richTextBox1.SelectedText.Length != 0)//如果选定了被替换字符串{
                {
                    active_form.richTextBox1.SelectedText = replace_text.Text;//替换被选定的字符串
                    Parameter.find_position = Parameter.find_position + replace_text.Text.Length - search_text.Text.Length;
                }
            }
        }

        private void Close_findNreplace_Click(object sender, EventArgs e)
        {
            toolStrip4.Visible = false;
            toolStrip5.Visible = false;
        }
            
        private void ToolStrip_search_Click(object sender, EventArgs e)
        {
            this.Menu_find_Click(sender, e);
        }

        private void Menu_open_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter= "RichTextbox格式|*.rtb";
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                Menu_new_Click(sender, e);
                son_form active_form = (son_form)this.ActiveMdiChild;
                active_form.richTextBox1.LoadFile(openFileDialog.FileName,
                                RichTextBoxStreamType.RichText);
                active_form.Text = active_form.Text.Substring(0, active_form.Text.Length - 1);

                string title = active_form.Text;
                
                Parameter.form_file[title] = openFileDialog.FileName;

            }


        }

        public void Menu_save_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form == null)
            {
                return;
            }
            string title = active_form.Text;
            if (title[title.Length - 1] == '*')
            {
                title = title.Substring(0, title.Length - 1);
            }
            else
            {
                return;
            }
            string file_location = Parameter.form_file[title];

            if (file_location == "")
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Filter= "RichTextbox格式|*.rtb";
                saveFileDialog.FileName = active_form.Text.Substring(0, active_form.Text.Length - 1);
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    active_form.richTextBox1.SaveFile(saveFileDialog.FileName, RichTextBoxStreamType.RichText);
                    Parameter.form_file[title] = saveFileDialog.FileName;
                    Parameter.form_change[title] = false;
                    active_form.Text = active_form.Text.Substring(0, active_form.Text.Length - 1);
                }
            }
            else
            {
                Parameter.form_change[title] = false;
                active_form.richTextBox1.SaveFile(file_location, RichTextBoxStreamType.RichText);
                active_form.Text = active_form.Text.Substring(0, active_form.Text.Length - 1);
            }
        }

        private void ToolStrip_save_Click(object sender, EventArgs e)
        {
            Menu_save_Click(sender, e);
        }

        private void Menu_saveother_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form == null)
            {
                return;
            }
            string title = active_form.Text;    
            if (title[title.Length - 1] == '*')
            {
                title = title.Substring(0, title.Length - 1);
            }
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "RichTextbox格式|*.rtb";
            saveFileDialog.FileName = active_form.Text.Substring(0, active_form.Text.Length - 1);
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                active_form.richTextBox1.SaveFile(saveFileDialog.FileName, RichTextBoxStreamType.RichText);
                Parameter.form_file[title] = saveFileDialog.FileName;
                Parameter.form_change[title] = false;
                if(title[title.Length - 1] == '*')
                {
                    active_form.Text = active_form.Text.Substring(0, active_form.Text.Length - 1);
                }
            }
        }

        private void Menu_saveall_Click(object sender, EventArgs e)
        {
            Form[] activate_form = this.MdiChildren;
            foreach(Form form in activate_form)
            {
                form.Focus();
                Menu_save_Click(sender, e);
            }
        }

        private void ToolStrip_saveall_Click(object sender, EventArgs e)
        {
            Menu_saveall_Click(sender, e);
        }

        private void ToolStrip_replace_Click(object sender, EventArgs e)
        {
            Menu_replace_Click(sender, e);
        }

        private void Menu_font_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form == null)
            {
                return;
            }
            FontDialog fontDialog1 = new FontDialog();
            if (fontDialog1.ShowDialog() == DialogResult.OK)
                active_form.richTextBox1.SelectionFont = fontDialog1.Font;

        }

        private void 加粗BToolStripMenuItem_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form == null)
            {
                return;
            }
            if (active_form.richTextBox1.SelectionFont.Bold)
            {
                System.Drawing.Font new_font = new System.Drawing.Font(
                          active_form.richTextBox1.SelectionFont, FontStyle.Regular);
                active_form.richTextBox1.SelectionFont = new_font;
            }
            else
            {
                System.Drawing.Font new_font = new System.Drawing.Font(
                          active_form.richTextBox1.SelectionFont, FontStyle.Bold);
                active_form.richTextBox1.SelectionFont = new_font;
            }
        }
        private void ToolStrip_bold_Click(object sender, EventArgs e)
        {
            加粗BToolStripMenuItem_Click(sender, e);

        }

        private void 斜体IToolStripMenuItem_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form == null)
            {
                return;
            }
            if (active_form.richTextBox1.SelectionFont.Bold)
            {
                System.Drawing.Font new_font = new System.Drawing.Font(
                          active_form.richTextBox1.SelectionFont, FontStyle.Regular);
                active_form.richTextBox1.SelectionFont = new_font;
            }
            else
            {
                System.Drawing.Font new_font = new System.Drawing.Font(
                          active_form.richTextBox1.SelectionFont, FontStyle.Italic);
                active_form.richTextBox1.SelectionFont = new_font;
            }
        }

        private void ToolStrip_italic_Click(object sender, EventArgs e)
        {
            斜体IToolStripMenuItem_Click(sender, e);
        }

        private void 下划线UToolStripMenuItem_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form == null)
            {
                return;
            }
            if (active_form.richTextBox1.SelectionFont.Bold)
            {
                System.Drawing.Font new_font = new System.Drawing.Font(
                          active_form.richTextBox1.SelectionFont, FontStyle.Regular);
                active_form.richTextBox1.SelectionFont = new_font;
            }
            else
            {
                System.Drawing.Font new_font = new System.Drawing.Font(
                          active_form.richTextBox1.SelectionFont, FontStyle.Underline);
                active_form.richTextBox1.SelectionFont = new_font;
            }
        }

        private void ToolStrip_underline_Click(object sender, EventArgs e)
        {
            下划线UToolStripMenuItem_Click(sender, e);
        }

        private void ToolStrip_fontcolor_Click(object sender, EventArgs e)
        {
            son_form active_form = (son_form)this.ActiveMdiChild;
            if (active_form == null)
            {
                return;
            }
            ColorDialog color = new ColorDialog();
            if(DialogResult.OK == color.ShowDialog())
            {
                System.Drawing.Color color1 = new Color();
                color1 = color.Color;
                active_form.richTextBox1.SelectionColor = color1;
            }
        }

        private void Menu_closeall_Click(object sender, EventArgs e)
        {
            Form[] activate_form = this.MdiChildren;
            foreach (Form form in activate_form)
            {
                form.Focus();
                form.Close();
            }
        }

        private void Menu_showall_Click(object sender, EventArgs e)
        {
            Form[] activate_form = this.MdiChildren;
            int number = activate_form.Length;
            int width = this.Width / number;
            int nowx = 0;
            int height = this.Height-100;

            foreach (Form form in activate_form)
            {
                form.Location = new Point(nowx, 0);
                form.Size = new System.Drawing.Size(width,height);
                nowx += width;
            }
        }
    }
}
