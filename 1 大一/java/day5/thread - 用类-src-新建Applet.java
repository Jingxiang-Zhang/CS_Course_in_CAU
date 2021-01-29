

import java.awt.*;
import java.applet.Applet;


public class 新建Applet extends Applet {
    Font font;
    private int v=10;
    private th cth;
   
    @Override
    public void init() {
        
        cth=new th(this);
    }
    
    @Override
    public void start(){
        cth.start();
    }
    
    @Override
    public void paint(Graphics g){
        font=new Font("仿宋",100,50);
        g.setColor(Color.red);
        g.setFont(font);
        g.drawString("thread ripper",v,40);

    }

    public void setV(int v) {
        this.v = v;
    }

    

    public int getV() {
        return v;
    }
    
    
}
