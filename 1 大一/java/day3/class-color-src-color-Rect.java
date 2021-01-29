package color;
import java.awt.Graphics;
import java.awt.Color;

/**
 *
 * @author lenovo
 */
public class Rect extends publ{

    public Rect(){
    }
    public Rect(int x,int y,int size,Color c,Color d ){  
        super(x,y,size,c,d);
    }
    public Rect(int x,int y,int size){
         super(x,y,size);
    }
    
    @Override
    public void draw(Graphics g){
        g.setColor(fcolor);
        g.fill3DRect(x, y, size, size, true);
    }
    
    
}
