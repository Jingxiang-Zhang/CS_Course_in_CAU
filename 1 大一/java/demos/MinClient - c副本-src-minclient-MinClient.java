package minclient;

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
public class MinClient {

    public static void main(String[] args) {
        Socket socket;
        String msg;
        try{
            socket=new Socket("10.6.15.136",8889);  
            OutputStream out=socket.getOutputStream();
            DataOutputStream dout=new DataOutputStream(out);
            msg="我是"+socket.toString();
            System.out.println("发送消息："+msg);
            dout.writeUTF(msg);
            
            InputStream in=socket.getInputStream();
            DataInputStream din=new DataInputStream(in);                     
            String text=din.readUTF();
            din.close();
            //dout.close();
            System.out.println(text);
            
            socket.close();
            
        }catch(IOException e){
            e.printStackTrace();
        }
        
        
    }
    
}
