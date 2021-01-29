using System;

namespace 第5题
{
    public class TestDate
    {
        public static int GetDate(string s)
        {
            int[] i = new int[3];
            string[] temp = s.Split("-");
            i[0] = Convert.ToInt32(temp[0]);
            i[1] = Convert.ToInt32(temp[1]);
            i[2] = Convert.ToInt32(temp[2]);
            DateTime dateTime = new DateTime(i[0], i[1], i[2]);
            return dateTime.DayOfYear;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            
            Console.WriteLine("请输入一个日期，以\"-\"分割");
            string s = Console.ReadLine();
            Console.WriteLine("这一天是一年中的第{0}天", TestDate.GetDate(s));
        }
    }
}
