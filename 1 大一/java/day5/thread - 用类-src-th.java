/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author lenovo
 */
public class th extends Thread{
    private 新建Applet test;
    
    
    public th(新建Applet app){
        this.test=app;
    }
    @Override
    public void run()
    {
        int x;
        while(true){
            x=test.getV();
            x=x+2;
            test.setV(x);
            test.repaint();
            try{
                th.sleep(100);
            }
            catch(InterruptedException t){
                
            }
        }
        
        
    }
    
}
