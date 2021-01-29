
package window;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Panel;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class Window extends Frame{

    public Window(String title){
        super(title);
     //   this.addWindowListener()
        addWindowListener(new WindowAdapter(){
            @Override
            public void windowClosing(WindowEvent e){
                dispose();
                System.exit(0);
            }
        });
        
        
        FlowLayout layout=new FlowLayout(FlowLayout.LEFT);
        Panel topPanel=new Panel(layout);
        topPanel.add(new Button("shang1"));
        topPanel.add(new Button("shang2"));
        topPanel.add(new Button("shang3"));
        topPanel.add(new Button("shang4-Exit"));
        
        Panel leftPanel=new Panel(layout);
   //     add(new Button("you"),BorderLayout.EAST);
        add(leftPanel,BorderLayout.WEST);
        add(topPanel,BorderLayout.NORTH);
    //    add(new Button("xia"),BorderLayout.SOUTH);
   //     add(new Button("zhong"),BorderLayout.CENTER);
        
    }
    public static void main(String[] args) {
        Window window=new Window("java");
        window.setSize(800,550);
        window.setVisible(true);
    }
    
}
