import java.applet.Applet;
import java.awt.Button;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;


public class First extends Applet {
    
    @Override
    public void init() {
       
        Button button=new Button("T");
        button.setSize(200, 200);
        
        add(button);
       
     }
    
    @Override
    public void paint(Graphics g){ 
        First fir=new First();
        fir.setSize(300, 300);
        
        Font font;
        font=new Font("华文彩云",Font.ITALIC,89);
        
        g.setFont(font);
        g.setColor(Color.green);
        g.drawString("First Applet", 30, 150);
    }

    @Override
    public void stop() {
        
        super.stop(); 
    }

    @Override
    public void start() {
        super.start(); 
    }
    
}
