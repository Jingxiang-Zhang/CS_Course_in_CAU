using System;

namespace 作业3
{
    public class Account
    {
        private double saving;
        public Account(double saving)
        {
            if (saving < 100)
            {
                throw new Exception("错误！小于100元钱无法创建账户");
            }
            this.saving = saving;
        }
        public Account():this(100)
        {
        }
        public double MySaving
        {
            get
            {
                return saving;
            }
            set
            {
                this.saving = value;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Account a1 = new Account();
                Console.WriteLine("a1账户当前余额为：{0}", a1.MySaving);
                a1.MySaving = 180;
                Console.WriteLine("经过修改a1账户当前余额为：{0}", a1.MySaving);
                Account a2 = new Account(500);
                Console.WriteLine("a2账户当前余额为：{0}", a2.MySaving);
                Account a3 = new Account(50);
            }
            catch(Exception e)
            {
                Console.WriteLine("Error!{0}", e.Message);
            }
        }
    }
}
