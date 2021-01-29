
package newpackage;
import java.awt.Color;
import java.awt.Graphics;
public abstract class base {
    public Color cor;
    public int x,y;
    public int width;
    
    base(){
        x=100;y=100;width=100;
        cor=new Color(125,125,125);
    }
    base(int a,int b,int c,Color co){
        x=a;y=b;width=c;
        cor=co;
    }
    
    public void draw(Graphics g){
        
    }

    public void setCor(Color cor) {
        this.cor = cor;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public Color getCor() {
        return cor;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getWidth() {
        return width;
    }
    
}
