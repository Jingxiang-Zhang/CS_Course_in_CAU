using System;

namespace 测验3
{
    public class Car
    {
        private int fuel_consume;
        private int container;
        private int current_fuel;
        private int mile;
        public int Mile
        {
            get { return mile; }
            set { mile = value; }
        }
        public int Fuel_has
        {
            get { return Fuel_has; }
            set { current_fuel = value; }
        }   
        public Car()
        {
            container = 55;
            fuel_consume = 8;
            current_fuel = 55;
            mile = 0;
        }
        public Car(int current_fuel):this()
        {
            this.current_fuel = current_fuel;
        }
        public Car(int current_fuel,int mile) : this(current_fuel)
        {
            this.mile = mile;
        }
        private int Fuel_consume(int mile)
        {
            return mile / fuel_consume;
        }
        public delegate void CarRunHandler(int mile);
        public event CarRunHandler CarRunEvent;
        public bool CarRun(int mile)
        {
            if (mile / fuel_consume > current_fuel) return false;
            CarRunEvent(mile);
            return true;
        }
        public void Run(int mile)
        {
            Console.WriteLine("Trigger car run event, car run for {0} miles", mile);
            this.mile += mile;
            current_fuel -= mile / fuel_consume;
        }
        public int Refuel()
        {
            int temp = container - current_fuel;
            current_fuel = container;
            return temp;
        }
        public bool Refuel(int gasoline)
        {
            if (gasoline + current_fuel > container) return false;
            current_fuel += gasoline;
            return true;
        }
        public void Get_message(ref int current_fuel,ref int mile)
        {
            current_fuel = this.current_fuel;
            mile = this.mile;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Car newcar = new Car();
            newcar.CarRunEvent += newcar.Run;
            newcar.CarRun(75);
            int miles = 0, current_fuel = 0;
            newcar.Get_message(ref current_fuel, ref miles);
            Console.WriteLine("This car has {0}L gasoline. It has already run for {1} miles",
                                current_fuel, miles);
            Console.WriteLine();
            newcar.CarRun(300);
            newcar.Get_message(ref current_fuel, ref miles);
            Console.WriteLine("This car has {0}L gasoline. It has already run for {1} miles",
                               current_fuel, miles);
            Console.WriteLine();
            newcar.Refuel(20);
            newcar.Get_message(ref current_fuel, ref miles);
            Console.WriteLine("This car has {0}L gasoline. It has already run for {1} miles",
                               current_fuel, miles);
        }
    }
}
