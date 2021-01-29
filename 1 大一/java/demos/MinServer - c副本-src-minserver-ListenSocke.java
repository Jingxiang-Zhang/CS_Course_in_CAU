package minserver;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author xxx
 */
public class ListenSocke extends Thread {

    public static final int SER_PORT = 8889;
    private ServerSocket server;

    public ListenSocke() {
     }

    @Override
    public void run() {
        ClientSocket client;
        Socket socket;
        try {         
            server = new ServerSocket(SER_PORT);
            while (true) {
                System.out.println("Wait...");
                socket = server.accept();
                System.out.println("处理请求!");
                client=new ClientSocket(socket); 
                client.start();
                Thread.sleep(40);
            }
        }catch (IOException e) {
            e.printStackTrace();
        }catch(InterruptedException ie){
            ie.printStackTrace();
        }
    }

}
