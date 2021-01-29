package color;
import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author lenovo
 */
public class circ extends publ {

    public circ(){
    }
    public circ(int x,int y,int size,Color c,Color d ){
        super(x,y,size,c,d);
    }
    public circ(int x,int y,int size){
        super(x,y,size);
    }

    @Override
    public void draw(Graphics g){
        int csize;
        csize=x-size;
        g.setColor(fcolor);
        g.fillArc(x, y, size, csize, 0, 360);
        g.setColor(bcolor);
        g.drawArc(x, y, size, csize, 0, 360);
    }
    
    
}
