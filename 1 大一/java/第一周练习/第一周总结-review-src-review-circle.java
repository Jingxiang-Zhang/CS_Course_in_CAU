
package review;

import java.awt.Graphics;


public class circle extends Aclass implements implement{
    public int locate;
    public circle(int size,int locate){
        super(size);
        this.locate=locate;
    }
    public void draw(Graphics g){
       g.drawOval(locate, locate, size, size);
    }
    public void set(int locate){
        this.locate=locate;
    }
    @Override
    public void draw_a_line(Graphics g) {
        g.drawLine(locate, locate, locate+size, locate+size);
    }
    
}
