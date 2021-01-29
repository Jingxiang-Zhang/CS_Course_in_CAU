import java.util.Scanner;
import java.math.MathContext;

public class cc 
{
    public static class cal
    {
        private double radius,hei;
        public cal(double r,double h)
        {
            radius=r;
            hei=h;
        }
        public double get()
        {
            return (radius*radius*hei*3.1415926)/3;
        }
    }
   
    static void draw1()
    {
        System.out.println("+-----+");
        System.out.println("|     |");
        System.out.println("|     |");
        System.out.println("+-----+");
    }
    public static  final double CFIN=5;  //构造一个静态常量  
    
    public static double change(double a,double b)          
    {
        double c=a;
        a=b;b=c;
        return a>b?a:b;
    }
    public static int change(int a,int b)       //函数重载 
        {
        int c=a;
        a=b;b=c;
        return a>b?a:b;
    }
    
    public static void main(String[] args)
    {
        cal cc=new cal(10.0,20.0);    //tast 1 调用一个类
        double v;
        v=cc.get();
        System.out.print(v+"\n");
    
        cc=new cal(15,20);
        v=cc.get();
        System.out.println(v);
        
        draw1();          //调用函数
        double cd=10.2;   //强制类型转化
        int dc=(int)cd;
          
        System.out.println(3+5+"hello"+5+8);   //print的测试
        
       double cs=10,ds=20;            //函数依然是传递的复制品
       change(cs,ds);
       System.out.println(cs);
       
      String astr="hello world";      //string对象的构建
      String astr2=astr.substring(1,5);
      int clen=astr.length();
      System.out.println(astr);
      
    
       Scanner scan=new Scanner(System.in);   //输入测试
       String stt=scan.next();
       System.out.println(stt);
      
    }
    
  
}
