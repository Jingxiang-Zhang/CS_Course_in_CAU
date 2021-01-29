package demo13;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Panel;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Demo13  extends Frame{
      
    public Demo13(String title){
        super(title);
        this.addWindowListener(new WindowCloseHandle());
        
        FlowLayout layout=new FlowLayout(FlowLayout.LEFT);
        Panel topPane=new Panel(layout);
        
        topPane.add(new Button("1"));
        topPane.add(new Button("2"));
        topPane.add(new Button("3"));
        topPane.add(new Button("4"));
        
        Panel leftPanel=new Panel();
        
        add(leftPanel, BorderLayout.WEST);
        add(topPane, BorderLayout.NORTH);
     
    }


    public static void main(String[] args) {
        Demo13 demo13=new Demo13("GUI Demo");
        demo13.setSize(800, 550);
        demo13.setVisible(true);
        
    }
    
    public class WindowCloseHandle extends WindowAdapter{
        public void windowClosing(WindowEvent e){
            dispose();
            System.exit(0);
        }
    }
    
}
