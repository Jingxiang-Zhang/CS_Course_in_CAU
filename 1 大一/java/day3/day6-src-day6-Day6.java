package day6;

public class Day6 
{
    public static class mycl          //基类
    {
        public int a,b;
        public mycl(int x,int y)
        {
            a=x;b=y;
        }
        public int all()
        {
            return a+b;
        }
    }
    public  class mycltwo extends mycl
    {
        public int c,d;
        public mycltwo(int w,int x,int y,int z)
        {
            super(w,x);              //调用父类的构造函数
            c=x;z=y;
        }
        public int all()
        {
            return super.all()+c+d;   //用super调用父类的函数
        }
    }
    
  /*  public boolean equal(Object o)     //运用非强制类型转化的方法比较是否相等
    {
       
    } */
    public static void main(String[] args) 
    {
        Object ac=new Object();
      
    }
    
}
