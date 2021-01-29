
import java.awt.Color;
import java.awt.Graphics;

public class sss {

    public int x, y;
    public int r;
    public Color cor;

    public sss() {

    }

    public sss(int x, int y, int n, Color cor) {
        this.r = n;
        this.x = x;
        this.y = y;
        this.cor = cor;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getR() {
        return r;
    }

    public void setR(int r) {
        this.r = r;
    }

    public Color getCor() {
        return cor;
    }


    public void setCor(Color cor) {
        this.cor = cor;
    }

    public void draw(Graphics g) {
        int x0, y0;
        g.setColor(cor);
        x0 = x - r;
        y0 = y - r;
        g.drawArc(x0, y0, 2 * r, 2 * r, 0, 360);
    }
}
