using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 实验2作业1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("所有的水仙花为：");
            for(int index = 100; index < 1000; index++)
            {
                int temp = index;
                int i1 = temp % 10;
                temp /= 10;
                int i2 = temp % 10;
                temp /= 10;
                int i3 = temp % 10;
                int num = i1 * i1 * i1 + i2 * i2 * i2 + i3 * i3 * i3;
                if (index == num)
                {
                    Console.WriteLine("{0}", index);
                }

            }
        }
    }
}
