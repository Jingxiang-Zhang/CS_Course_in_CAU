import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class Demo16Applet extends Applet {
    private int x,y;

    @Override
    public void init() {
        addMouseListener(new MouseEventHandle() );
    }

    @Override
    public void paint(Graphics g){
        g.setColor(Color.RED);
        g.fillArc(x, y, 7, 7, 0, 360);
        
    }
    
    public class MouseEventHandle extends MouseEventAdapter{
        @Override
        public void mouseClicked(MouseEvent e) {
            x=e.getX();
            y=e.getY();
            repaint();
        }
    }
    
}
