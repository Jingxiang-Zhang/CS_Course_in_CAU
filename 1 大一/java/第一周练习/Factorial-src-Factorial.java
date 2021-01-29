import java.util.Scanner;
public class Factorial {

    public static void main(String[] args) {
         Scanner scan=new Scanner(System.in);
         int a=scan.nextInt();     
         math ma=new math();
         int mult=ma.Factorial(a);
         
         
         System.out.print(mult);
    }
    
}
