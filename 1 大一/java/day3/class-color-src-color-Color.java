
package color;
import java.awt.*;
import java.awt.event.*;

public class Color extends Frame{
    private Rect[] rects={new Rect(10,30,50),new Rect(70,30,50),new Rect(130,30,50)};
    private circ[] circs={new circ(100,60,50),new circ(100,160,50),new circ(100,260,50)};
    public Color(){
        
    }

    public static void main(String[] args) {
        Color pain=new Color();
        pain.setTitle("sss");
        pain.setSize(700,650);
        pain.setVisible(true);
    }
    @Override 
    public void paint(Graphics g)
    {  
        for(Rect r:rects){
            r.draw(g);
            
        }
      
         for(circ r:circs){
            r.draw(g);
            
        }
    }
}
