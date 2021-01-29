
package newpackage;
import java.awt.Color;
import java.awt.Graphics;

public class circle extends base{
    public int radius;
    
    circle(int a,int b,int c,int rai,Color co){
        super(a,b,c,co);
        radius=rai;
    }
    
    @Override
    public void draw(Graphics g){
           g.draw3DRect(x, y, radius, radius, true);
    }
    public void setRadius(int radius) {
        this.radius = radius;
    }

    public int getRadius() {
        return radius;
    }
    
    
}
