using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 实验1作业2
{
    class Program
    {
        static void Main(string[] args)
        {
            string i1, i2;
            Console.Write("请输入第一个整数：");
            i1 = Console.ReadLine();
            Console.Write("请输入第二个整数：");
            i2 = Console.ReadLine();
            try
            {
                int num1 = Convert.ToInt32(i1);
                int num2 = Convert.ToInt32(i2);
                if (num1 > 0 && num2 > 0)
                {
                    num1++;
                    Console.WriteLine("结果为：{0}", num1 + num2);
                }
                else if(num1 < 0 && num2 < 0)
                {
                    num1 -= 10;
                    Console.WriteLine("结果为：{0}", num1 * num2);
                }
                else if(num1==0 || num2 == 0)
                {
                    Console.WriteLine("输入有误");
                }
                else
                {
                    Console.WriteLine("结果为：{0}", Math.Abs(num1 * num2));
                }
            }
            catch
            {
                Console.WriteLine("输入有误,不是整数");
            }
        }
    }
}
