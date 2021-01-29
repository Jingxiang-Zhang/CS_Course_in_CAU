using System;

namespace 作业3
{
    class Message
    {
        public static void SafeDoorIsSafe(int HP)
        {
            Console.WriteLine("The safe door's HP is {0} .It's safe", HP);
        }
        public static void SafeDoorIsBroke(int HP)
        {
            Console.WriteLine("The safe door's HP is {0} .It's broken", HP);
        }
        public static void DoorIsBroke(int HP)
        {
            Console.WriteLine("The door's HP is {0} .It's broken", HP);
        }
        public static void DoorIsSafe(int HP)
        {
            Console.WriteLine("The door's HP is {0} .It's broken", HP);
        }
        public static void StrangeDoorIsBroken(int HP)
        {
            Console.WriteLine("The strange door's HP is {0} .It's broken", HP);
        }
    }
    interface IApperance
    {
        string Shape { set; get; }
        string Color { set; get; }
    }
    class Door:IApperance
    {
        protected int HP;
        protected string shape;
        protected string color;
        public Door(string shape,string color)
        {
            this.shape = shape;
            this.color = color;
            HP = 100;
        }
        public Door() : this("Rect", "Brown") { }
        public string Shape
        {
            set { shape = value; }
            get { return shape; }
        }
        public string Color
        {
            set { color = value; }
            get { return color; }
        }
        public virtual void CloseTheDoor()
        {
            Console.WriteLine("The door is close");
        }
        public void OpenTheDoor()
        {
            Console.WriteLine("The door is open");
        }
        public delegate void HPEvent(int HP);
        public event HPEvent HPHandler;
        public void Hit()
        {
            HP -= 40;
            if (HP <= 0)
            {
                HPHandler(HP);
            }
            else
            {
                Message.DoorIsSafe(HP);
            }
        }
    }
    class SafeDoor : Door
    {

        public SafeDoor() : base("Round", "White") {  }
        public new void OpenTheDoor()
        {
            Console.WriteLine("The safe door is open");
        }
        public override void CloseTheDoor()
        {
            Console.WriteLine("The safe door is close");
        }
        public new event HPEvent HPHandler;
        public new void Hit()
        {
            HP -= 40;
            if (HP <= 0)
            {
                HPHandler(HP);
            }
            else
            {
                Message.SafeDoorIsSafe(HP);
            }
        }
    }
    
  
    class Program
    {
        static void Main(string[] args)
        {
            Door door = new Door();
            SafeDoor safeDoor = new SafeDoor();
            Console.WriteLine("Door:");
            door.OpenTheDoor();
            door.CloseTheDoor();

            Console.WriteLine("\nsafe door:");
            safeDoor.OpenTheDoor();
            safeDoor.CloseTheDoor();

            Console.WriteLine("\nstrange door(动态绑定):");
            Door strangeDoor = new SafeDoor();
            strangeDoor.OpenTheDoor();
            strangeDoor.CloseTheDoor();

            Console.WriteLine("\ntest event:\n");
            safeDoor.HPHandler += Message.SafeDoorIsBroke;
            safeDoor.Hit();
            safeDoor.Hit();
            safeDoor.Hit();
            Console.WriteLine();
            door.HPHandler += Message.DoorIsBroke;
            door.Hit();
            door.Hit();
            door.Hit();
            strangeDoor.HPHandler+= Message.StrangeDoorIsBroken;
            Console.WriteLine();
            strangeDoor.Hit();
            strangeDoor.Hit();
            strangeDoor.Hit();
        }
    }
}
