using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 实验2作业2
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = @"1.One day, a father and his little son were going home. At this age, the boy was interested in all kinds of things and was always asking questions. 2.Now, he asked, 'What's the meaning of the word 'Drunk', dad?' 'Well, my son,' his father replied, 'look, there are standing two policemen. 3.If I regard the two policemen as four then I am drunk.'"; ;

            int letter = 0;
            int space = 0;
            int number = 0;
            int other = 0;
            for(int i = 0; i < s.Length; i++)
            {
                if (s[i] > '0' && s[i] < '9') number++;
                else if ((s[i] > 'a' && s[i] < 'z') || (s[i] > 'A' && s[i] < 'Z')) letter++;
                else if (s[i] == ' ') space++;
                else other++;
            }
            Console.WriteLine("字母数量为 ：{0}", letter);
            Console.WriteLine("空格数量为 ：{0}", space);
            Console.WriteLine("数字数量为 ：{0}", number);
            Console.WriteLine("其他数量为 ：{0}", other);

        }
    }
}
