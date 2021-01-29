using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace work
{
    class Method
    {
        public static bool GetPython()
        {
            if (System.IO.File.Exists("config.txt"))
            {
                StreamReader streamReader = new StreamReader("config.txt", Encoding.Default);
                string file = streamReader.ReadLine();
                streamReader.Close();
                Variable.python_loc = file.Trim();
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool SetPython()
        {
            bool succ = false;
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "python程序|*.exe";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                string name = dialog.FileName;
                string[] re = name.Split('\\');
                if (re[re.Length - 1] == "python.exe")
                {
                    succ = true;
                    Variable.python_loc = name;
                    MessageBox.Show("设置成功", "成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    MessageBox.Show("必须是python程序", "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }

            if (succ)
            {
                StreamWriter streamWriter = new StreamWriter("config.txt");
                streamWriter.Write(Variable.python_loc);
                streamWriter.Close();
            }
            return succ;
        }   

        public static Bitmap DealImg(Bitmap bitmap ,string command,string[] args)
        {
            string path = System.Diagnostics.Process.GetCurrentProcess().MainModule.FileName;
            path = path.Substring(0, path.Length - 8);
            string py_path = path + "pycode.py";
            string source_path = path + "deal.png";
            string dest_path = path + "dest.png";
            bitmap.Save(source_path);

            string fullcommand = py_path + " " + source_path + " " + dest_path + " " + command + " ";
            for(int i = 0; i < args.Length; i++){
                fullcommand = fullcommand + args[i];
                if (i != args.Length - 1)
                {
                    fullcommand = fullcommand + " ";
                }
            }
            System.Diagnostics.Process p = new System.Diagnostics.Process();
            p.StartInfo.FileName = Variable.python_loc;
            p.StartInfo.UseShellExecute = false;
            p.StartInfo.Arguments = fullcommand;
            p.StartInfo.RedirectStandardInput = true;
            p.StartInfo.RedirectStandardOutput = true;
            p.StartInfo.RedirectStandardError = true;
            p.StartInfo.CreateNoWindow = true;

            p.Start();//启动程序
            p.WaitForExit();
            p.Close();
            FileStream fs = File.OpenRead(dest_path);
            int filelength = (int)fs.Length;
            Byte[] image = new Byte[filelength];
            fs.Read(image, 0, filelength);
            System.Drawing.Image result = System.Drawing.Image.FromStream(fs);
            fs.Close();
            Bitmap bit = new Bitmap(result);
            return bit;
        }
    }
}
