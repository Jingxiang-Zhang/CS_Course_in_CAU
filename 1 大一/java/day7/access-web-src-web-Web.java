package web;

import java.io.DataOutputStream;
import java.io.OutputStream;
import java.io.IOException;

import java.net.ServerSocket;
import java.net.Socket;

public class Web {
    private  ServerSocket server;
    public static final int SET_PS=9090;
    
    public Web() throws IOException{
    Socket socket;
        try{
            server=new ServerSocket(SET_PS);
            while(true){
            System.out.println("wait");
            socket=server.accept();
            
            OutputStream out=socket.getOutputStream();
            DataOutputStream dout=new DataOutputStream(out);
            
            dout.writeUTF("that is netbeans");
            dout.close();
           
            }
 //           server.close();
 //           server.close();
        }catch(IOException e){
            e.printStackTrace();
        }          
}
    
    public static void main(String[] args) {
        try{
            Web b=new Web();
        }catch(IOException e){
            e.printStackTrace();
        }          
        
        
    }
    
}
