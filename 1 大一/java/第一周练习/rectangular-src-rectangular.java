
import java.awt.Frame;
import java.awt.Graphics;

public class rectangular extends Frame {

    rectangular_class rec = new rectangular_class(0, 0, 200, 0, 200, 100, 0, 100);
    rectangular_class rec2 = new rectangular_class(200, 300);

    public static void main(String[] args) {
        rectangular tr = new rectangular();
        tr.setVisible(true);
        tr.setSize(400, 400);

    }

    @Override
    public void paint(Graphics g) {
        rec.draw(g);
        System.out.println("The Circonference of the triangle is " + rec.get_Circomference());
        System.out.println("The Area of the triangle is " + rec.get_Area());

    }

}
