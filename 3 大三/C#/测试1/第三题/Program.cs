using System;

namespace 第三题
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入一个四位整数");
            int result = 0;
            try
            {
                string s = Console.ReadLine();
                result = Convert.ToInt32(s);
            }
            catch
            {
                Console.WriteLine("错误！");
            }
            Console.WriteLine("请输入加密还是解密(此步骤可跳过)");
            Console.ReadLine();
            int [] j = new int[4];
            for(int i = 0; i < 4; i++)
            {
                int temp = result % 10;
                temp = (temp + 5) % 10;
                j[i] = temp;
                result = result / 10;
            }
            result = 0;
            result = j[3] + j[2] * 10 + j[1] * 100 + j[0] * 1000;
            Console.WriteLine("加密的结果为：{0}",result);
        }
    }
}
