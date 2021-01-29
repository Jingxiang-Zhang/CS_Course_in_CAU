using System;

namespace 第一题
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = @"1.One day, a father and his little son were going home. At this age, the boy was interested in all kinds of things and was always asking questions. 2.Now, he asked, 'What's the meaning of the word 'Drunk', dad?' 'Well, my son,' his father replied, 'look, there are standing two policemen. 3.If I regard the two policemen as four then I am drunk.'";

            int letter = 0;
            int space = 0;
            int number = 0;
            int other = 0;
            foreach(char i in s)
            {
                if (i >= '0' && i <= '9') number++;
                else if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) letter++;
                else if (i == ' ') space++;
                else other++;
            }
            Console.WriteLine("字母一共：{0}个",letter);
            Console.WriteLine("数字一共：{0}个", number);
            Console.WriteLine("空格一共：{0}个", space);
            Console.WriteLine("其他一共：{0}个", other);

        }
    }
}
