using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Filepack;
namespace 机器学习
{
    public partial class FormLoadWaiting : Form
    {
        public FormLoadWaiting()
        {
            GraphicsPath oPath = new GraphicsPath();
            oPath.AddEllipse(new Rectangle(0, 0, 500, 354));

            this.Region = new Region(oPath);
            try
            {
                InitializeComponent();
                Filepack.ImgTextTranformInfo imgTextTranformInfo = new Filepack.ImgTextTranformInfo();
                imgTextTranformInfo.Password = SourceData.password;
                imgTextTranformInfo.FileName = SourceData.load_picture_loaction;
                Filepack.ImgTextTranform.SingleFileToMemoryList(imgTextTranformInfo);
                bgimage.Image = Image.FromStream(imgTextTranformInfo.ImageAndTextList_memory[0]);
                this.StartPosition = FormStartPosition.CenterScreen;
                Load_Location = 0;

                //加载左侧工具栏
                Load_tooltip_net();
                //加载右侧属性栏
                Load_Attribute();
                //加载图标
                Load_Icon();
                //初始化SourceData中的对象数据
                InitSourceData();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误！", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        private void InitSourceData()
        {
            SourceData.ObjectList = new List<List<object> >();
        }
        private void Load_Icon()
        {
        }
        private void Load_Attribute()
        {
            RightAttribute rightAttribute = new RightAttribute();
            rightAttribute.TopLevel = false;
            rightAttribute.Parent = SourceData.MainForm;
            rightAttribute.Location = new Point(910, 55);
            SourceData.RightAttribute = rightAttribute;
            rightAttribute.Show();
        }
        private void Load_tooltip_net()
        {
            LeftToolTipNet leftToolTipNet = new LeftToolTipNet();
            leftToolTipNet.TopLevel = false;
            leftToolTipNet.Parent = SourceData.MainForm;
            leftToolTipNet.Location = new Point(0, 55);
            SourceData.LeftToolTipNet = leftToolTipNet;
            leftToolTipNet.Show();
        
        }
        private int Load_Location;
        private void Load_time_Tick(object sender, EventArgs e)
        {
            Load_time.Enabled = false;
            bool flag = false;
            switch (Load_Location)
            {
                case 0:
                    //File list check
                    FileListCheck();
                    Load_time.Enabled = true;
                    break;
                case 1:
                    //File init setting
                    LoadSetting();
                    Load_time.Enabled = true;
                    break;
                case 2: 
                    //File text and image load
                    LoadTextImage();
                    Load_time.Enabled = true;
                    break;
                case 3:
                    System.Threading.Thread.Sleep(200);
                    Load_time.Enabled = true;
                    break;
                default:
                    flag = true;
                    break;
            }
            if (flag)
            {
                Load_time.Enabled = false;
                this.Close();
            }
            Load_Location++;

        }
        public void FileListCheck()
        {
            this.label_LoadContent.Text = "正在检测文件完整性";
        }
        public void LoadSetting()
        {

            this.label_LoadContent.Text = "正在加载配置";
            System.Threading.Thread.Sleep(200);
        }
        public void LoadTextImage()
        {
            this.label_LoadContent.Text = "正在载入图片";
            System.Threading.Thread.Sleep(200);
        }

    }
}
