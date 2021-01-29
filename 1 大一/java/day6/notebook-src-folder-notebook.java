package folder;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.TextArea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 *
 * @author lenovo
 */
public class notebook extends Frame {
    private TextArea textarea;
    
    public notebook(){
        
       super("small notebook");
       
       this.setSize(1200,800);            
       this.setVisible(true);
       
       MenuBar mainbar=new MenuBar();
       this.setMenuBar(mainbar);
       
       Menu fileMenu=new Menu("File");
       
       
       MenuItem openItem=new MenuItem("open");
       fileMenu.add(openItem);
       MenuItem saveItem=new MenuItem("save");
       fileMenu.add(saveItem);
       fileMenu.addSeparator();
       MenuItem exitItem=new MenuItem("exit");
       fileMenu.add(exitItem);
       
       exitItem.setLabel("exit");
       exitItem.addActionListener(new ExitItemEventHandle());
       
       
       Menu editMenu=new Menu("edit");
       Menu fontMenu=new Menu("font");
       mainbar.add(fileMenu);
       mainbar.add(editMenu);
       mainbar.add(fontMenu);
       
       textarea=new TextArea();
       add(textarea,BorderLayout.CENTER);
       
       
        addWindowListener(new WindowAdapter(){
            @Override
            public void windowClosing(WindowEvent e){
                dispose();
                System.exit(0);
            }
        });
    
       
    }
     public static void main(String[] args){
        notebook notebook1 = new notebook();
    }
    
     
    public class ExitItemEventHandle implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getActionCommand().equals("exit")){
                System.out.println("file close");
                dispose();
                System.exit(0);
            }
            
        }
        
    }

    
}
