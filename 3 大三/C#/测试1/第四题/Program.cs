using System;

namespace 第四题
{
    public class Method
    {
        public static void tRevser(string [] str)
        {
            int length = str.Length;
            for(int i = 0; i < length / 2; i++)
            {
                string temp = str[i];
                str[i] = str[length - 1 - i];
                str[length - 1 - i] = temp;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = new string[4] { "3", "a", "8", "haha" };
            Method.tRevser(str);
            Console.WriteLine("翻转结果为：");
            for (int i = 0; i < str.Length; i++)
            {
                Console.WriteLine("{0}",str[i]);
            }
           
        }
    }
}
