
import java.awt.*;
import java.applet.Applet;

public class 新建Applet extends Applet {
    
    Font font;
    private int v = 10;
    private th cth;
    
    
    public class th extends Thread {
        private 新建Applet test;
        public th(新建Applet app) {
            this.test = app;
        }
        @Override
        public void run() {
            int x;
            while (true) {
                x = v;
                x = x + 2;
                v=x;
                test.repaint();
                try {
                    th.sleep(100);
                } catch (InterruptedException t) {

                }
            }
        }
    }



    @Override
    public void init() {

        cth = new th(this);
    }

    @Override
    public void start() {
        cth.start();
    }

    @Override
    public void paint(Graphics g) {
        font = new Font("仿宋", 100, 50);
        g.setColor(Color.red);
        g.setFont(font);
        g.drawString("thread ripper", v, 40);

    }



}
