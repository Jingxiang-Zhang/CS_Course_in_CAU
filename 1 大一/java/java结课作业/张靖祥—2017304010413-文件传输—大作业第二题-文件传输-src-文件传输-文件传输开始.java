 
package 文件传输;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

 
public class 文件传输开始 extends javax.swing.JFrame implements MouseListener{

    String ip_location;
    String ip_sockett;
    String file_location;
    public 文件传输开始() {
       
       initComponents();
 
    }
 
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        label_ip = new javax.swing.JLabel();
        ip_socktext = new javax.swing.JLabel();
        ip_socket = new javax.swing.JTextField();
        ip_name = new javax.swing.JTextField();
        start = new javax.swing.JButton();
        loction = new javax.swing.JTextField();
        location_text = new javax.swing.JLabel();
        tatle = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        label_ip.setText("jLabel1");
        label_ip.setText("请输入需要传入文件的ip地址");
        label_ip.setFont(new Font("宋体",20,20));

        ip_socktext.setText("jLabel1");
        ip_socktext.setText("请输入端口号");
        ip_socktext.setFont(new Font("宋体",20,20));

        ip_socket.setText("jTextField1");
        ip_socket.setText("9999");
        ip_socket.setFont(new Font("宋体",20,20));

        ip_name.setText("jTextField2");
        ip_name.setText("127.0.0.1");
        ip_name.setFont(new Font("宋体",20,20));

        start.setText("jButton1");
        start.setText("开始传输");
        start.setFont(new Font("宋体",30,30));
        start.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                startMouseClicked(evt);
            }
        });

        loction.setText("jTextField1");
        loction.setText("C:\\Users\\enovo\\Desktop\\java作业\\");
            loction.setFont(new Font("宋体",20,20));

            location_text.setText("jLabel1");
            location_text.setText("请输文件夹位置");
            location_text.setFont(new Font("宋体",20,20));

            tatle.setText("jLabel1");
            tatle.setText("本程序应用于向已知端口的另一台电脑进行文件传输，默认位置为桌面");
            tatle.setFont(new Font("宋体",15,15));

            javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
            getContentPane().setLayout(layout);
            layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                    .addGap(38, 38, 38)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addComponent(ip_socktext, javax.swing.GroupLayout.DEFAULT_SIZE, 277, Short.MAX_VALUE)
                        .addComponent(label_ip, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(location_text, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGap(14, 14, 14)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(ip_socket)
                                .addComponent(ip_name))
                            .addGap(27, 27, 27))
                        .addComponent(loction)))
                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                    .addContainerGap(21, Short.MAX_VALUE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                            .addComponent(tatle, javax.swing.GroupLayout.PREFERRED_SIZE, 545, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addContainerGap())
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                            .addComponent(start, javax.swing.GroupLayout.PREFERRED_SIZE, 165, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGap(200, 200, 200))))
            );
            layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(23, 23, 23)
                    .addComponent(tatle, javax.swing.GroupLayout.PREFERRED_SIZE, 41, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(47, 47, 47)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addComponent(label_ip, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(ip_name, javax.swing.GroupLayout.DEFAULT_SIZE, 37, Short.MAX_VALUE))
                    .addGap(40, 40, 40)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(ip_socktext, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(ip_socket, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGap(44, 44, 44)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addComponent(loction, javax.swing.GroupLayout.DEFAULT_SIZE, 42, Short.MAX_VALUE)
                        .addComponent(location_text, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 76, Short.MAX_VALUE)
                    .addComponent(start, javax.swing.GroupLayout.PREFERRED_SIZE, 48, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(61, 61, 61))
            );

            pack();
        }// </editor-fold>//GEN-END:initComponents

    private void startMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_startMouseClicked
        ip_location=ip_name.getText();
        ip_sockett=ip_socket.getText();
        file_location=loction.getText();
        javax.swing.JLabel wait = new javax.swing.JLabel();
        boolean done=false;
        if(start.isVisible()==true){
            start.setVisible(false);
            Point po=start.getLocation();
            wait.setSize(400,80);
            wait.setText("请耐心等待");
            wait.setFont(new Font("宋体",20,20));
            wait.setLocation(po.x,po.y);
            wait.setVisible(true);      
            this.add(wait);
            tranmit trm=new tranmit(ip_location,ip_sockett,file_location);
            done=trm.do_it();
        }
        if(done){
            JOptionPane.showMessageDialog(new JFrame().getContentPane(), 
        "文件传输成功！ ", "信息", JOptionPane.INFORMATION_MESSAGE); 
        }
        else{
             JOptionPane.showMessageDialog(new JFrame().getContentPane(), 
        "文件传输失败，请检查将要传入方的ip地址，端口，本地文件位置是否正确，传入方需要提前打开接受应用 ", 
        "错误", JOptionPane.INFORMATION_MESSAGE); 
        }
         wait.setVisible(false);
        start.setVisible(true);
    }//GEN-LAST:event_startMouseClicked

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(文件传输开始.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(文件传输开始.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(文件传输开始.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(文件传输开始.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new 文件传输开始().setVisible(true);
                
            }
        });
    }

    @Override
    public void mouseClicked(MouseEvent e) {
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
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField ip_name;
    private javax.swing.JTextField ip_socket;
    private javax.swing.JLabel ip_socktext;
    private javax.swing.JLabel label_ip;
    private javax.swing.JLabel location_text;
    private javax.swing.JTextField loction;
    private javax.swing.JButton start;
    private javax.swing.JLabel tatle;
    // End of variables declaration//GEN-END:variables
}
