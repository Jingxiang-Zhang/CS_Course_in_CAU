using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace 图片转换工具
{
    /*
     * 本程序均使用utf-8编码
     * 待完善：
     * 文件夹打包
     * dll制作
     */

    public partial class MainForm : Form
    {
        List<MemoryStream> ImageAndText_List;
        List<string> ImageAndText_name;
        List<FileCatagory> ImageAndText_catagory;

        string[] PictureFormat;
        string[] TextFormat;
        public MainForm()
        {
            InitializeComponent();
            ImageAndText_List = new List<MemoryStream>();
            ImageAndText_name = new List<string>();
            ImageAndText_catagory = new List<FileCatagory>();
            button_delete.Enabled = false;
            PictureFormat = new string[] { "jpg", "jpeg", "png" };
            TextFormat = new string[] { "txt", "c", "cpp" };
        }
        private void Button_save_Click(object sender, EventArgs e)
        {
            //保存按钮
            if (listBox1.Items.Count == 0)
            {
                MessageBox.Show("列表为空", "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            DialogResult dr = MessageBox.Show("是否添加密码？", "提示", MessageBoxButtons.YesNo, MessageBoxIcon.Information);
            if (dr == DialogResult.Yes)
            {
                PassWordForm form = new PassWordForm();
                form.ShowDialog();
            }
            string password = "";
            if(MediumParameter.passWordResult== DialogResult.Yes)
            {
                password = MediumParameter.passWord;
            }
            MediumParameter.passWordResult = DialogResult.No;
            MediumParameter.passWord = "";


            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "二进制图片集|*.data";
            saveFileDialog.FileName = "新图片集";
            saveFileDialog.Title = "保存图片";
            if (saveFileDialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            ImgTextTranformInfo imgTextTranformInfo = new ImgTextTranformInfo();
            imgTextTranformInfo.Password = password;
            imgTextTranformInfo.ImageAndTextList_name = ImageAndText_name;
            imgTextTranformInfo.ImageAndTextList_memory = ImageAndText_List;
            imgTextTranformInfo.ImageAndTextList_catagory = ImageAndText_catagory;
            imgTextTranformInfo.FileName = saveFileDialog.FileName;
            ImgTextTranform.MemoryListToByteFile(imgTextTranformInfo);

        }
        private void Button_open_Click(object sender, EventArgs e)
        {
            //打开一个文件
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            string[] str = new string[1];
            str[0] = openFileDialog.FileName;
            OpenFile(str);
        }
        private void ListBox1_DragDrop(object sender, DragEventArgs e)
        {
            //文件拖入事件
            string[] file_name = (string[])e.Data.GetData(DataFormats.FileDrop);
            OpenFile(file_name);
        }
        private void OpenFile(string[] fileName)
        {
            //打开文件事件
            string password = "";
            if (fileName.Length == 1)
            {
                string filename = fileName[0];
                filename = filename.Substring(filename.LastIndexOf("."));
                if (filename == ".data")
                {
                    PassWordForm passWordForm = new PassWordForm();
                    passWordForm.ShowDialog();
                    password = MediumParameter.passWord;
                    MediumParameter.passWord = "";
                    MediumParameter.passWordResult = DialogResult.No;
                }
            }
            ImgTextTranformInfo imgTextTranformInfo = new ImgTextTranformInfo();
            imgTextTranformInfo.Password = password;
            imgTextTranformInfo.FilenameList = fileName;
            try
            {
                ImgTextTranform.FilenameListToMemoryList(imgTextTranformInfo);
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message, "错误！", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            bool first_show = false;
            
            for (int i = 0; i < imgTextTranformInfo.ImageAndTextList_catagory.Count; i++)
            {
                ImageAndText_List.Add(imgTextTranformInfo.ImageAndTextList_memory[i]);
                ImageAndText_name.Add(imgTextTranformInfo.ImageAndTextList_name[i]);
                ImageAndText_catagory.Add(imgTextTranformInfo.ImageAndTextList_catagory[i]);
                listBox1.Items.Add(imgTextTranformInfo.ImageAndTextList_name[i]);
                if (!first_show)
                {
                    first_show = true;
                    listBox1.SelectedIndex = listBox1.Items.Count - 1;
                }
            }
        }
        private void ListBox1_DragEnter(object sender, DragEventArgs e)
        {
            //有文件拖入的窗体的时候鼠标改变
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Link;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }
        private void Form1_DragEnter(object sender, DragEventArgs e)
        {
            //有文件拖入的窗体的时候鼠标改变
            ListBox1_DragEnter(sender, e);
        }
        private void Button_clear_Click(object sender, EventArgs e)
        {
            //清除列表的事件
            listBox1.Items.Clear();
            ImageAndText_name.Clear();
            ImageAndText_List.Clear();
            ImageAndText_catagory.Clear();
            button_delete.Enabled = false;
            this.pictureBox1.Image=null;
            pictureBox1.Visible = true;
            textBox_text.Visible = false;
            button_down.Enabled = false;
            button_up.Enabled = false;
        }
        private void Form1_DragDrop(object sender, DragEventArgs e)
        {
            //文件拖入到框体的事件
            ListBox1_DragDrop(sender, e);
        }
        private void ListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //列表内容改变，右侧的内容改变的事件
            int selectIndex = listBox1.SelectedIndex;
            if (selectIndex == -1) return;
            button_down.Enabled = true;
            button_up.Enabled = true;
            button_delete.Enabled = true;

            if (ImageAndText_catagory[selectIndex] == FileCatagory.Picture)
            {
                Bitmap bitmap = new Bitmap(ImageAndText_List[selectIndex]);
                MemoryStream memoryStream = new MemoryStream();
                bitmap.Save(memoryStream, ImageFormat.Bmp);

                pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
                pictureBox1.Image = Image.FromStream(memoryStream);
        
                label1.Text = pictureBox1.Image.Height + "*" +
                                    pictureBox1.Image.Width + "像素";
                pictureBox1.Visible = true;
                textBox_text.Visible = false;
            }
            else if(ImageAndText_catagory[selectIndex] == FileCatagory.Text)
            {
                pictureBox1.Visible = false;
                textBox_text.Visible = true;

                byte[] buffer = new byte[ImageAndText_List[selectIndex].Length];
                ImageAndText_List[selectIndex].Read(buffer, 0, buffer.Length);
                ImageAndText_List[selectIndex] = new MemoryStream(buffer);

                textBox_text.Text = Encoding.UTF8.GetString(buffer);
                label1.Text = "文档长度："+textBox_text.Text.Length;
            }
            else if(ImageAndText_catagory[selectIndex] == FileCatagory.others)
            {
                pictureBox1.Visible = false;
                textBox_text.Visible = true;
                textBox_text.Text = ImageAndText_name[selectIndex].Substring(
                            ImageAndText_name[selectIndex].LastIndexOf(".")) + "文件";

                string length = string.Format("{0:N0}", ImageAndText_List[selectIndex].Length);
                label1.Text = "文件大小：" + length + "字节";
            }
        }
        private void Button_delete_Click(object sender, EventArgs e)
        {
            //删除按钮事件，删除列表所有选项
            int selectIndex = listBox1.SelectedIndex;
            if (selectIndex == -1) return;
            listBox1.Items.RemoveAt(selectIndex);

            ImageAndText_List.RemoveAt(selectIndex);
            ImageAndText_name.RemoveAt(selectIndex);
            ImageAndText_catagory.RemoveAt(selectIndex);
            if (listBox1.Items.Count > selectIndex)
            {
                listBox1.SelectedIndex = selectIndex;
            }
            else if (listBox1.Items.Count != 0)
            {
                listBox1.SelectedIndex = selectIndex - 1;
            }
            else
            {
                Button_clear_Click(sender, e);
            }
        }
        private void Button_up_Click(object sender, EventArgs e)
        {
            //向上按钮事件
            int select = listBox1.SelectedIndex;
            if (select <= 0)
            {
                return;
            }
            Exchange(select, select - 1);
            listBox1.SelectedIndex = select - 1;
        }
        private void Button_down_Click(object sender, EventArgs e)
        {
            //向下按钮事件
            int select = listBox1.SelectedIndex;
            if (select >= listBox1.Items.Count - 1)
            {
                return;
            }
            Exchange(select, select + 1);
            listBox1.SelectedIndex = select + 1;
        }
        private void Exchange(int index1,int index2)
        {
            //用于交换列表中的两行，被向上和向下按钮调用
            string name;
            name = (string)listBox1.Items[index1];
            listBox1.Items.RemoveAt(index1);
            listBox1.Items.Insert(index2, name);

            //memory互换
            byte[] buffer1 = ImageAndText_List[index1].ToArray();
            ImageAndText_List[index1].Close();
            byte[] buffer2 = ImageAndText_List[index2].ToArray();
            ImageAndText_List[index2].Close();
            ImageAndText_List[index1] = new MemoryStream(buffer2);
            ImageAndText_List[index2] = new MemoryStream(buffer1);

            //名字互换
            string str = ImageAndText_name[index1];
            string str2 = ImageAndText_name[index2];
            ImageAndText_name[index2] = str;
            ImageAndText_name[index1] = str2;

            //种类互换
            FileCatagory fc1 = ImageAndText_catagory[index1];
            FileCatagory fc2 = ImageAndText_catagory[index2];
            ImageAndText_catagory[index2] = fc1;
            ImageAndText_catagory[index1] = fc2;
            //改变选择
           
        }
        private void Button_help_Click(object sender, EventArgs e)
        {
            //打开帮助菜单
            Form_help form = new Form_help();
            form.ShowDialog();
        }
        private void Button1_Click(object sender, EventArgs e)
        {
            //解包事件
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "data文件|*.data";
            openFileDialog.Title = "请选择解包文件";
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                PassWordForm passwordform = new PassWordForm();
                passwordform.ShowDialog();
                string password = MediumParameter.passWord;

                ImgTextTranformInfo imgTextTranformInfo = new ImgTextTranformInfo();
                imgTextTranformInfo.Password = password;
                imgTextTranformInfo.FileName = openFileDialog.FileName;
                ImgTextTranform.UnpackDataFile(imgTextTranformInfo);
                MessageBox.Show("解包完成！");
            }
        }
    }
}

