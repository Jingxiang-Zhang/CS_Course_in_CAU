using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 实验1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("请输入一个数：");
            string s = Console.ReadLine();
            int max = 0, flag = 0;
            while(s != "q")
            {
                try
                {
                    int temp = Convert.ToInt32(s);
                    if (flag == 0)
                    {
                        flag = 1;
                        max = temp;
                    }
                    else
                    {
                        if (max <= temp) max = temp;
                    }
                    Console.Write("请输入一个数：");
                    s = Console.ReadLine();
                }
                catch
                {
                    Console.WriteLine("无法转化为int，请重新输入");
                    Console.Write("请输入一个数：");
                    s = Console.ReadLine();
                }
            }
            Console.WriteLine("最大的值为：{0}", max);
        }
    }
}
