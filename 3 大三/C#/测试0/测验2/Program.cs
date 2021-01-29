using System;

namespace 测验2
{
    class Program
    {
        static void Main(string[] args)
        {
            Random random = new Random();
            int[] dice = new int[6] { 0, 0, 0, 0, 0, 0 };
            for(int i = 0; i < 10000; i++)
            {
                dice[random.Next(6)]++;
            }
            for(int i = 0; i < 6; i++)
            {
                Console.WriteLine("{0}出现的次数为：{1}，所占的比例为：{2}",
                                    i+1, dice[i], (double)dice[i] / 10000);
            }
        }
    }
}
