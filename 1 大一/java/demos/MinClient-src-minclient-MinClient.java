package minclient;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

/**
 *
 * @author xxx
 */
public class MinClient {

    public static void main(String[] args) {
        Socket socket;
        try{
            socket=new Socket("10.2.208.121",8889);
            InputStream in=socket.getInputStream();
            DataInputStream din=new DataInputStream(in);
            
            String text=din.readUTF();
            din.close();
            System.out.println(text);
            
            socket.close();
            
        }catch(IOException e){
            e.printStackTrace();
        }
        
        
    }
    
}
