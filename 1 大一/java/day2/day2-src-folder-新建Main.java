import java.util.*;
import java.io.*;
import folder.pingfang;
public class 新建Main 
{
    public static void open()throws FileNotFoundException    //open a file
    {
        Scanner input=new Scanner(new File("C:\\Users\\lenovo\\Desktop\\java\\test.txt"));
        while(input.hasNext())
        {
            String word= input.nextLine();
            System.out.println(word);
        }
        input.close();
    }
    public static void shuzu(int[] cc)
    {
        int a=cc[0];
        cc[0]=cc[1];
        cc[1]=a;
    }
    public static class Point
    {
        double  x,y;
        Point(double a,double b)
        {  
            x=a;y=b;
        }
    }
   
        
    public static void main(String[] args) //命令行参数
             throws FileNotFoundException
    {
       double s=Math.sin(50);         //math库的使用
       Scanner scan=new Scanner(System.in);
       System.out.printf("%8.2f\n", s);     //print format 控制格式
       System.out.printf("%8.2f\n", Math.random());
       Random ran=new Random();           //使用随机数

       System.out.printf("%d\n",ran.nextInt(10));    //区随机数
       
       open();
       double[] cdo=new double[10];          //构建一个数组并且输出其值
       for(double i=0;i<10;i++)
           cdo[(int)i]=i;
       for(double i:cdo)
           System.out.println(i);         //for-each的使用方法
       double[] cde=Arrays.copyOf(cdo, cdo.length*2);   //arrays复制数组
       System.out.println(Arrays.toString(cdo));          //Arrays的操作
       System.out.println(Arrays.toString(cde));
       Arrays.equals(cdo, cde);           //判断是否相等
       Arrays.sort(cde);                //排序
       System.out.println(cde);          //这种方法输出的结果是错误的
    
       
       int[] cc=new int[2];
       cc[0]=1;cc[1]=5;
       shuzu(cc);
       System.out.println(cc[0]);
       int d=cc.length;       //求数组长度
       
       int[] dd=cc;                //公用一个内存
       dd[0]=100;
       System.out.println(cc[0]);
      
       Point ppo=new Point(10,20);
       ppo.x=10;
       
       
       pingfang ping=new pingfang();
       System.out.printf("%.2f",ping.sqrt(10));
       
   //    circle ccir=new circle();
       
    }
    
    
    
    
}
