package minserver;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

/**
 *
 * @author xxx
 */
public class ClientSocket  extends Thread {
    private Socket socket;
    public ClientSocket(Socket socket){
        this.socket=socket;
    }
    @Override
    public void run(){
        try{
            InputStream in=socket.getInputStream();
            DataInputStream din=new DataInputStream(in);
            String text=din.readUTF();
            System.out.println("接收："+text);
            
            
            OutputStream out=socket.getOutputStream();
            DataOutputStream dout=new DataOutputStream(out);
            System.out.println("响应...");
            dout.writeUTF("请求收到，OK!");
            dout.close();
            din.close();
            socket.close();
        }catch(IOException e){
            e.printStackTrace();
        }
        
            
        
      
    }
    
    
}
