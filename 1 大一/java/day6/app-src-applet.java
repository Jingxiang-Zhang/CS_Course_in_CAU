

import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseEvent;


public class applet extends Applet {
    public int x,y,flag=0;

    @Override
    public void init() {
        this.setSize(800,600);
        this.addMouseListener(new MouseEventHandle());
         
    }
    
    @Override
    public void paint(Graphics g){
        g.setColor(Color.red);
        if(flag==1)
            g.fillArc(x, y, 15, 15, 180, 360);
    }
    
    public class MouseEventHandle extends MouseEventAdapter{
        @Override
        public void mouseClicked(MouseEvent e) {
            System.out.println(e.getX());
            x=e.getX();
            y=e.getY();
            flag=1;
            repaint();            
        }
    }
}
