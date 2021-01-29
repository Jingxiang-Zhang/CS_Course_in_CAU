import java.awt.*;

import java.awt.event.*;

public class wenben extends Frame {
    private TextArea textarea;
    
    public wenben(){
        
       super("small notebook");
       
       this.setSize(1200,800);            
       this.setVisible(true);
       
       MenuBar mainbar=new MenuBar();
       this.setMenuBar(mainbar);
       mainbar.setFont(new Font("宋体",20,20));
       Menu fileMenu=new Menu("File");
       
       
       MenuItem openItem=new MenuItem("open");
       fileMenu.add(openItem);
       MenuItem saveItem=new MenuItem("save");
       fileMenu.add(saveItem);
       fileMenu.addSeparator();
       MenuItem exitItem=new MenuItem("exit");
       fileMenu.add(exitItem);
       
       exitItem.setLabel("exit");
       exitItem.addActionListener(new ItemEventHandle());
       
       
       Menu editMenu=new Menu("edit");
       Menu fontMenu=new Menu("font");
       mainbar.add(fileMenu);
       mainbar.add(editMenu);
       mainbar.add(fontMenu);
       
      
       textarea=new TextArea("这个弹出能保存的复杂窗口实在不会");
       textarea.setFont(new Font("宋体",40,40));
       add(textarea,BorderLayout.CENTER);
       
       
        addWindowListener(new WindowAdapter(){
            @Override
            public void windowClosing(WindowEvent e){
             
                System.exit(0);
            }
        });
    
       
    }
     public static void main(String[] args){
        wenben notebook1 = new wenben();
    }
    
     
    public class ItemEventHandle implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getActionCommand().equals("exit")){
                System.out.println("file close");
               
                System.exit(0);
            }
            
        }
        
    }

    
}
