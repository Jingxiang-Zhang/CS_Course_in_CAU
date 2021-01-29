using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Collections;
using System.IO;

namespace WindowsFormsApp1
{
    class tools
    {
        public static Form1 form;
        public static ArrayList list = new ArrayList();
        public tools(string filename)
        {
            StreamReader sr = new StreamReader(filename);
            string line;
            // 从文件读取并显示行，直到文件的末尾 
            line = sr.ReadLine();
            while (line!=null)
            {
                ArrayList arraytemp = new ArrayList();
                if (line[0] == '>')
                {
                    form.comboBox1.Items.Add(line.Substring(1));
                    form.comboBox2.Items.Add(line.Substring(1));

                    line = sr.ReadLine();
                    while (line != null && line[0] != '>')
                    {
                        arraytemp.Add(line);
                        line = sr.ReadLine();
                    }
                    list.Add(arraytemp);
                   
                  }
              
            }
            form.comboBox1.SelectedIndex = 0;
            form.comboBox2.SelectedIndex = 0;

        }

    }
}
