import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class teast extends Applet implements ActionListener{
    private Image image;
    private Font font;
    private Button addBot,subBot;
    private int size=300;
    
    @Override
    public void init() {
         image=this.getImage(getCodeBase(),"timg.jpg");
         
         Thread myth=new Thread();
         myth.getPriority();
         myth.start();
   
         
         addBot=new Button("+");
         subBot=new Button("-");
         
         addBot.setActionCommand("Font+");
         subBot.setActionCommand("Font-");
         
         addBot.addActionListener(this);
         subBot.addActionListener(this);
         
         add(addBot);
         add(subBot);
    }


    
    @Override
    public void paint(Graphics g) {
         font=new Font("华文彩云",Font.BOLD,size);
         g.setFont(font);
         g.setColor(Color.black);
         g.drawImage(image, 0, 0, this);
         g.drawString("蓝天白云", 300, 400);
         
         g.setColor(Color.red);
         g.drawString("蓝天白云", 300+2, 400+2);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println(e.getActionCommand());
        if("Font-".equals(e.getActionCommand())==true)
        {
            size-=3;
            this.repaint();
        }
        if("Font+".equals(e.getActionCommand())==true)
        {
            size+=3;
            this.repaint();
        }
    }
}
