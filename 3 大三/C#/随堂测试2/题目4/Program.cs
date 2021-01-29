using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace 题目4
{
    class Program
    {
        static void Main(string[] args)
        {
            Program program = new Program();
            program.txt_write();
            program.txt_read();
            program.bt_write();
        }
        public void txt_write()
        {
            FileStream file = new FileStream(@"C:\Users\lenovo\Desktop\test.txt",
               FileMode.Create, FileAccess.Write);
            string str = "123、4.75、5、'A'、0.8、”北京”";
            byte[] bt= Encoding.UTF8.GetBytes(str);
            file.Write(bt, 0, bt.Length);
            file.Close();
        }
        public void txt_read()
        {
            FileStream file = new FileStream(@"C:\Users\lenovo\Desktop\test.txt",
               FileMode.Open, FileAccess.Read);
            byte[] bt = new byte[file.Length];
            file.Read(bt, 0, bt.Length);
            string str = Encoding.UTF8.GetString(bt);
            Console.WriteLine(str);
            file.Close();
        }
        public void bt_write()
        {
            FileStream file = new FileStream(@"C:\Users\lenovo\Desktop\test2.txt",
            FileMode.Create, FileAccess.Write);
            string str = "123、4.75、5、'A'、0.8、”北京”";
            BinaryWriter binaryWriter = new BinaryWriter(file);
            byte[] bt = Encoding.UTF8.GetBytes(str);
            binaryWriter.Write(bt);
            file.Close();
        }
 
    }
}
