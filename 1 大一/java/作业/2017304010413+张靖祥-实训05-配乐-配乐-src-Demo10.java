import java.applet.Applet;
import java.awt.*;
import java.applet.* ;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Demo10 extends Applet implements ActionListener{
    private Image image;
    private Font font;
    private  int fontsize=100;
    
    
    @Override
    public void init(){
        image=this.getImage(getCodeBase(),"preview.jpg");
        this.setSize(800,600);
    }  
    @Override
    public void paint(Graphics g){
     
        g.drawImage(image, 0, 0, this);
        g.setFont(font);
    
        AudioClip a=getAudioClip(getCodeBase(),"Hans.wav");
        a.play(); 
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getActionCommand().equals("Font+")==true){
            fontsize+=5;
            repaint();
        }
        if(e.getActionCommand().equals("Font-")==true){
            fontsize-=5;
            repaint();
        }
      }
    
}
