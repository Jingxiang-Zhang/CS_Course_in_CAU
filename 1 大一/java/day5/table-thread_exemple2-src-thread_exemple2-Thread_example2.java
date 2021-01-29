
package thread_exemple2;


public class Thread_example2 implements Runnable{
    private String title;
    public Thread_example2(String title){
        this.title=title;
    }
      
    public static void main(String[] args) {
        
        Thread d1,d2,d3;
        d1=new Thread(new Thread_example2("red"));
        d2=new Thread(new Thread_example2("red"));
        d3=new Thread(new Thread_example2("red"));
        
        d1.start();
        d2.start();
        d3.start();
    }
    
    @Override
    public void run(){
         try{
            while(true){
                System.out.println("2");
                Thread.sleep(500);
            }
        }
        catch(InterruptedException t){
            
        }
    }
    
}
