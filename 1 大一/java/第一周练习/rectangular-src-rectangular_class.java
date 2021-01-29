
import java.awt.*;

public class rectangular_class {

    public double x1, x2, x3, x4, y1, y2, y3, y4;

    public rectangular_class() {

    }

    public rectangular_class(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        this.x1 = x1 + 50;
        this.x2 = x2 + 50;
        this.x3 = x3 + 50;
        this.x4 = x4 + 50;
        this.y1 = y1 + 50;
        this.y2 = y2 + 50;
        this.y3 = y3 + 50;
        this.y4 = y4 + 50;
        if (((x1 - x2) != (x4 - x3)) || ((y1 - y2) != (y4 - y3))) {
            System.out.println("error, can not compose a rectangular !");
        }
    }

    public rectangular_class(double width, double high) {
        if (width <= 0 || high <= 0) {
            System.out.println("error, length must not be minus!");
            System.exit(0);
        }
        x1 = 50;
        y1 = 50;
        x2 = width + 50;
        y2 = 50;
        x3 = width + 50;
        y3 = high + 50;
        x4 = 50;
        y4 = high + 50;

    }

    public void draw(Graphics g) {
        g.drawLine((int) x1, (int) y1, (int) x2, (int) y2);
        g.drawLine((int) x2, (int) y2, (int) x3, (int) y3);
        g.drawLine((int) x4, (int) y4, (int) x3, (int) y3);
        g.drawLine((int) x4, (int) y4, (int) x1, (int) y1);
    }

    public double get_Circomference() {
        double r1 = (x2 - x1) * 2;
        double r2 = (y3 - y1) * 2;
        return (r1 + r2) > 0 ? (r1 + r2) : (-r1 - r2);
    }

    public double get_Area() {
        double r1 = x2 - x1;
        double r2 = y3 - y1;
        return (r1 * r2) > 0 ? (r1 * r2) : (-r1 * r2);
    }
}
