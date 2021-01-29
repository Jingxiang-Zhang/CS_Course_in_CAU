package smallnote;

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
 * @author xxx
 */
public class SmallNote extends Frame {
    private TextArea textArea;
    public SmallNote(){
        super("Simple Note");
        this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                dispose();
                System.exit(0);
            }       
        });

        MenuBar mainbar=new MenuBar();
        this.setMenuBar(mainbar);
        
        Menu fileMenu=new Menu("File");
        MenuItem openItem=new MenuItem("Open");
        fileMenu.add(openItem);
        MenuItem saveItem=new MenuItem("Save");
        fileMenu.add(saveItem);
        fileMenu.addSeparator();
        MenuItem exitItem=new MenuItem("Exit");
        fileMenu.add(exitItem);
        exitItem.addActionListener( new ExitItemEventHandle() );
        
        Menu editMenu=new Menu("Edit");
        Menu fontMenu=new Menu("Font");
        
        mainbar.add(fileMenu);
        mainbar.add(editMenu);
        mainbar.add(fontMenu);
        
        textArea=new TextArea();
        add(textArea, BorderLayout.CENTER);
        
        setSize(600,400);
        this.setVisible(true);        
    }
    
    public static void main(String[] args){
        new SmallNote();
    }
    
    public class ExitItemEventHandle implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e){
            dispose();
            System.exit(0);
        }
    }
    
    
}
