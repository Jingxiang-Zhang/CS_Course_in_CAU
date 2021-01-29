
import java.awt.*;

public class triangle_class {

    public double x1, x2, x3, y1, y2, y3;

    //构造函数
    public triangle_class() {

    }

    public triangle_class(double x1, double y1, double x2, double y2, double x3, double y3) {
        this.x1 = x1+50;
        this.x2 = x2+50;
        this.x3 = x3+50;
        this.y1 = y1+50;
        this.y2 = y2+50;
        this.y3 = y3+50;
    }

    public triangle_class(double width, double high) {
        x1 = 50;
        y1 = 50;
        x2 = width+50;
        y2 = 50;
        x3 = width / 2+50;
        y3 = high+50;
    }

    public triangle_class(double bian1, double bian2, double bian3) {
        double xita = (bian1 * bian1 + bian2 * bian2 - bian3 * bian3) / 2 / bian1 / bian2;
        double x_3 = bian1 * xita;
        double y_3 = Math.sqrt(bian1 * bian1 - x_3 * x_3);
        x1 = 50;
        y1 = 50;
        x2 = bian2+50;
        y2 = 50;
        x3 = x_3+50;
        y3 = y_3+50;
    }

    public void set_triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        this.x1 = x1;
        this.x2 = x2;
        this.x3 = x3;
        this.y1 = y1;
        this.y2 = y2;
        this.y3 = y3;
        double r1 = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        double r2 = Math.sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        double r3 = Math.sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        if (r1 + r2 <= r3 && r1 + r3 <= r2 && r2 + r3 <= r1) {
            System.out.println("error!");
            System.exit(0);
        }

    }

    public void draw(Graphics g) {
        g.drawLine((int) x1, (int) y1, (int) x2, (int) y2);
        g.drawLine((int) x2, (int) y2, (int) x3, (int) y3);
        g.drawLine((int) x1, (int) y1, (int) x3, (int) y3);
    }
    public double get_Circomference(){
        double r1 = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        double r2 = Math.sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        double r3 = Math.sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        return r1+r2+r3;
    }
    public double get_Area(){
        double r1 = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        double r2 = Math.sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        double r3 = Math.sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        double xita = (r1 * r1 + r2 * r2 - r3 * r3) / 2 / r1 / r2;
        double x_3 = r1 * xita;
        double high = Math.sqrt(r1 * r1 - x_3 * x_3);
        double width = r2;
        return width*high/2;

    }
}
