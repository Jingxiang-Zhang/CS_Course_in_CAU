using System;

namespace 作业2
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("请输入生日，格式为xxxx.xx.xx");
                string birthday = Console.ReadLine();
                string[] temp = new string[3];
                temp = birthday.Split(".");
                DateTime dt = new DateTime(Convert.ToInt32(temp[0]),
                                            Convert.ToInt32(temp[1]),
                                            Convert.ToInt32(temp[2]));
                int date = dt.DayOfYear;
                Console.WriteLine("您的生日为一年中的第{0}天", date);
            }
            catch
            {
                Console.WriteLine("错误！");
            }
            
        }
    }
}
