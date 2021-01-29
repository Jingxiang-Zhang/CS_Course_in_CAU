using System;
using System.Collections;

namespace 作业1
{
    abstract class Vehicle
    {
        protected string number;
        public Vehicle(string number)
        {
            this.number = number;
        }
        public abstract string NoOfWheels();
    }
    class Car : Vehicle
    {
        public Car() : base("Four wheels car") { }
        public override string NoOfWheels()
        {
            return base.number;
        }
    }
    class Motorbike : Vehicle
    {
        public Motorbike() : base("Two wheels motorbike") { }
        public override string NoOfWheels()
        {
            return base.number;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Car car = new Car();
            Motorbike motorbike = new Motorbike();
            Console.WriteLine("汽车的名称为：{0}", car.NoOfWheels());
            Console.WriteLine("摩托车的名称为：{0}", motorbike.NoOfWheels());
        }
    }
}
