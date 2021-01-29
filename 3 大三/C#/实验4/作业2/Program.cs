using System;

namespace 作业2
{
    interface IHabit
    {
        string sleep { get; set; }
        string food { get; set; }
        string region { get; set; }
    }
    class Cat : IHabit
    {
        protected string Sleep;
        protected string Food;
        protected string Region;
        public Cat()
        {
            Sleep = "night";
            Food = "fish";
            Region = "China";
        }
        public string sleep
        {
            get { return Sleep; }
            set { Sleep = value; }
        }
        public string food
        {
            get { return Food; }
            set { Food = value; }
        }
        public string region
        {
            get { return Region; }
            set { Region = value; }
        }
    }
    class Tiger : IHabit
    {
        protected string Sleep;
        protected string Food;
        protected string Region;
        public Tiger()
        {
            Sleep = "night";
            Food = "meat";
            Region = "Africa";
        }
        string IHabit.sleep
        {
            get { return Sleep; }
            set { Sleep = value; }
        }
        string IHabit.food
        {
            get { return Food; }
            set { Food = value; }
        }
        string IHabit.region
        {
            get { return Region; }
            set { Region = value; }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Cat cat = new Cat();
            Tiger tiger = new Tiger();
            Console.WriteLine("Cat live in {0}", cat.region);
            Console.WriteLine("Cat's food is {0}", cat.food);
            IHabit habit = (IHabit)cat;
            Console.WriteLine("Cat sleep at {0}", habit.sleep);

            habit = (IHabit)tiger;
            Console.WriteLine("Tiger live in {0}", habit.region);
            Console.WriteLine("Tiger's food is {0}", habit.food);
            Console.WriteLine("Tiger sleep at {0}", habit.sleep);
        }
    }
}
