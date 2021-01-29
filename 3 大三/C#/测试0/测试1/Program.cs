using System;

namespace 测试1
{
    class Program
    {
        static void Main(string[] args)
        {
            double num = 1;
            double s = 0;
            for(int i = 1; i <= 13; i++)
            {
                s += ((i % 2 == 0) ? -1 : 1) / num;
                num++;
            }
            Console.WriteLine("值为：{0}", s);
        }
    }
}
