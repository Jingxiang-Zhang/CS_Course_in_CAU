package minserver;

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
        //??????
    }
    
    
}
