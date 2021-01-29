using System;

namespace 第二题
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = 1, b = 2;
            double sum = 0;
            for(int i = 0; i < 20; i++)
            {
                sum += b / a;
                double temp = a;
                a = b;
                b = temp + b;
            }
            Console.WriteLine("和为{0}", sum);
        }
    }
}
