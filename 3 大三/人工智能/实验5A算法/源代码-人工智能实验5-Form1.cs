using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 人工智能实验5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            comboBox_heigh.SelectedIndex = 2;
            comboBox_width.SelectedIndex = 2;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Maze.width = comboBox_width.SelectedIndex + 5;
            Maze.height = comboBox_heigh.SelectedIndex + 5;
            this.Close();
        }
    }
}
