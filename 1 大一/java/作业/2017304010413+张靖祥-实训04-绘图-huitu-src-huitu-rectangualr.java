 
package huitu;

import java.awt.*;

 
public class rectangualr extends shape{
    
    public rectangualr(int X, int Y, Color bian_color, Color nei_color) {
        super(X, Y, bian_color, nei_color);
    }
    
    public void draw(Graphics g,int x){
        
        g.setColor(bian_color);
        g.fillRect(X, Y, x, x);
        g.setColor(nei_color);
        g.fillRect(X+2, Y+2, x-4, x-4);
    }
    
}
