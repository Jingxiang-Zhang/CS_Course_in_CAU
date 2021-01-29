using System;

namespace 第6题
{
    public class Area
    {
        public static double Calculation(double radius)
        {
            return Math.PI * radius * radius;
        }
        public static double Calculation(double length, double height)
        {
            return length * height;
        }
        public static double Calculation(double a, double b, double c)
        {
            double p = (a + b + c) / 2;
            double S = Math.Sqrt(p * (p - a) * (p - b) * (p - c));
            return S;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("圆形的面积为：{0}", Area.Calculation(7));
            Console.WriteLine("矩形的面积为：{0}", Area.Calculation(16, 8));
            Console.WriteLine("三角形的面积为：{0}", Area.Calculation(6, 8, 11));
        }
    }
}
