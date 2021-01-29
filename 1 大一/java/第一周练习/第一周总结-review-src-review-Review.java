
package review;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.Button;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 *
 * @author lenovo
 */
public class Review extends Frame implements MouseListener,ActionListener,Runnable{
    public int flag=0;
    public boolean stop=true;
    circle round=new circle(100,200);
    Button button=new Button("draw a line");
    Button button2=new Button("draw a circle");
    Button button_run=new Button("run");
    Thread th = null;
    
    public Review(){
        setLayout(null);
        button.setSize(100,50);
        button.setVisible(true);
        button.setLocation(100, 100);
        button.setName("line");
        button2.setSize(100,50);
        button2.setVisible(true);
        button2.setLocation(300, 100);
        button2.setName("circle");
        button_run.setSize(100,50);
        button_run.setVisible(true);
        button_run.setLocation(200, 400);
        button_run.setName("button_run");
        
        this.add(button);
        this.add(button2);
        this.add(button_run);
        this.addMouseListener(this);
        button.addActionListener(this);
        button2.addActionListener(this);
        button_run.addActionListener(this);
    }

   static Review  myreview =new Review();
    
      
    public static void main(String[] args) {
        
        myreview.setVisible(true);
    myreview.setSize(600,600);
       
      
    }
    @Override
    public void paint(Graphics g){
        button.setVisible(true);
        if(flag%2==0){
            round.draw(g);
        }
        else {
            round.draw_a_line(g);
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        flag+=1;
        this.repaint();
        System.out.println(e.getX());
    }

    @Override
    public void mousePressed(MouseEvent e) {
    }

    @Override
    public void mouseReleased(MouseEvent e) {
    }

    @Override
    public void mouseEntered(MouseEvent e) {
    }

    @Override
    public void mouseExited(MouseEvent e) {
    }

    
    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "draw a line":
                flag=1;
                break;
            case "draw a circle":
                flag=0;
                break;
            case "run":
            case "stop":
                if(stop==true){
                    
                    th=new Thread(myreview);
                    stop=false;
                    button_run.setLabel("stop");
                    th.start();
                    
                }
                else{
                    button_run.setLabel("run");
                    th.interrupt();
                    stop=true;
                    
                }   break;
            default:
                break;
        }
        System.out.println(e.getActionCommand());
        this.repaint();
        
    }

    @Override
    public void run() { 
            try  {       
                while(true){
                    round.set(round.locate+8);
                    this.repaint();
                    System.out.println(round.locate);
                    Thread.sleep(200);
                }
            }
            catch(InterruptedException t){
                
            }
    }
    
    
}
