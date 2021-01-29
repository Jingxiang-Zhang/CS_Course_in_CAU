
package newpackage;
import java.awt.Color;
import java.awt.Graphics;

public class squire extends base{
    public int lon;
    
    squire(int a,int b,int c,int rai,Color co){
        super(a,b,c,co);
        lon=rai;
    }
    
    @Override
    public void draw(Graphics g){
        g.draw3DRect(x, y, lon, lon, true);
    }
    public void setRadius(int lon) {
        this.lon = lon;
    }

    public int getRadius() {
        return lon;
    }
    
    
}
