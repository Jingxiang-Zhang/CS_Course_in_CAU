
package pkgcatch;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class Catch {

    public static void main(String[] args) {
        Socket socket;
        try{
            for(int i=0;i<20;i++){
            socket=new Socket("10.6.15.136",9090);
            InputStream in=socket.getInputStream();
            DataInputStream din=new DataInputStream(in);
            
            String text=din.readUTF();
            System.out.println(text);
            
            socket.close();}
            
        }catch(IOException e){
           e.printStackTrace();
        }
            
    }
    
}
