using System;

namespace 作业4
{
    public class Auto
    {
        protected int TyreNumber;
        protected string Color;
        protected int Weight;
        protected int Velocity;
        protected string[] colorlist = { "crimson","modena","biege","emerald","sapphire" };
        public string this[int i]
        {
            get
            {
                return colorlist[i];
            }
        }
        public void SetColor(string Color)
        {
            this.Color = Color;
        }   
        public string getColor()
        {
            return Color;
        }
        public Auto(int TyreNumber,string Color,int Weight,int velocity)
        {
            this.TyreNumber = TyreNumber;
            this.Color = Color;
            this.Weight = Weight;
            this.Velocity = velocity;
        }
        public Auto():this(4,"dull biege", 1800, 100)
        {
        }
        public int getVelocity()
        {
            return Velocity;
        }
        public void accelerate(int speed)
        {
            Velocity += speed;
        }
        public void decelerate(int speed)
        {
            Velocity -= speed;
        }
        public void PullOver()
        {
            Velocity = 0;
        }
    }
    class Autocar : Auto
    {
        public string AirCondition;
        public string CD;
        public Autocar(int TyreNumber, string Color, int Weight, int velocity,
                       string AirCondition,string CD):base(TyreNumber,Color,Weight,velocity)
        {
            this.AirCondition = AirCondition;
            this.CD = CD;
        }
        new public void accelerate(int speed)
        {
            Velocity += speed;
        }
        new public void decelerate(int speed)
        {
            Velocity -= speed;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Autocar mycar = new Autocar(4, "indigo strewn violet", 1800, 160, 
                                            "midea", "Burmester");
            Console.WriteLine("当前车速为：{0}", mycar.getVelocity());
            mycar.accelerate(10);
            Console.WriteLine("当前车速为：{0}", mycar.getVelocity());
            mycar.decelerate(100);
            Console.WriteLine("当前车速为：{0}", mycar.getVelocity());
            mycar.PullOver();
            Console.WriteLine("当前车速为：{0}", mycar.getVelocity());


            Console.WriteLine("当前汽车的颜色为：{0}", mycar.getColor());
            mycar.SetColor(mycar[2]);
            Console.WriteLine("当前汽车的颜色为：{0}", mycar.getColor());



        }
    }
}
