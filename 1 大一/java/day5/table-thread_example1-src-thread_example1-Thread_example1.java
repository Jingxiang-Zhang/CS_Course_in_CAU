
package thread_example1;

/**
 *
 * @author lenovo
 */
public class Thread_example1 extends Thread{
    public Thread_example1(String title){
        super(title); 
    }
      
    public static void main(String[] args) {
        Thread_example1 d1,d2,d3,d4,d5,d6;
        d1=new Thread_example1("red");
        d2=new Thread_example1("blact");
        d3=new Thread_example1("green");
        d4=new Thread_example1("red");
        d5=new Thread_example1("blact");
        d6=new Thread_example1("green");
        // TODO code application logic here
        
        d1.start();
        d3.start();
        d5.start();
        d2.start();
        d4.start();
        d6.start();
    }
    
    @Override
    public void run(){
         try{
            while(true){
                System.out.println(this.getName());
                Thread.sleep(500);
            }
        }
        catch(InterruptedException t){
            
        }
    }
    
}
