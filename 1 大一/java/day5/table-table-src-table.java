
import java.awt.*;
import java.awt.event.*;

public class table extends Frame implements ActionListener {

    Button start = new Button("start");
    Marble marbles[]= new Marble[5];
    int y=2;
    public  table(){
        super("taiqiu");
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e){
                dispose();
                System.exit(0);
            }
        });
            
        
                
    }
    
    class windowClosing extends WindowAdapter{
        public void windowCloing(windowEvent e){
            
    }
        
            
    public void run() {
        while (true) {
            if (x > table.getSize().width - 25 || x < 0) {
                xdir *= (-1);
            }

            if (y > table.getSize().width - 25 || y < 0) {
                ydir *= (-1);
            }

            x += xdir;
            y += ydir;
            try {
                sleep(100);
            } catch (InterruptedException e) {
            }

            table.repaint();

        }
    }

    public void draw(Graphics g) {
        g.setColor(new Color(0, 0, 0));
        g.fillOval(x, y, 30, 30);
        g.setColor(new Color(255, 255, 255));
        g.fillOval(x + 5, y + 5, 8, 6);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
    }
}

}
