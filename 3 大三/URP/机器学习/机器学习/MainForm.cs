using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 机器学习
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            Load_Form();
        }

        public void Load_Form()
        {
            SourceData.MainForm = this;
            FormLoadWaiting formLoadWaiting = new FormLoadWaiting();
            formLoadWaiting.ShowDialog();
        }

        private void Menu_File_exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void MainForm_SizeChanged(object sender, EventArgs e)
        {
            SourceData.LeftToolTipNet.LeftToolTipNet_SizeChanged(sender, e);
            SourceData.RightAttribute.RightAttribute_SizeChanged(sender, e);
        }

        int load_times = 2;
        private void timer1_load_Tick(object sender, EventArgs e)
        {
          
        }

        private void Menu_File_newfile_Click(object sender, EventArgs e)
        {
            MainFormFunc.Menu_File_newfile_Click();
        }
    }
}
