 
package huitu;
import java.awt.*;
public class oval extends shape{
    public oval(int X,int Y,Color bian_color,Color nei_color){
        super(X,Y,bian_color,nei_color);
    }
    
    public void draw(Graphics g,int x,int y){
      
        g.setColor(bian_color);
        g.fillOval(X, Y, x, y); 
        g.setColor(nei_color);
        g.fillOval(X+2, Y+2, x-2, y-2);
    }
}
