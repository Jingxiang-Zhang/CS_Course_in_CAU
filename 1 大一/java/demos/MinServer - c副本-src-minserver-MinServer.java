package minserver;

/**
 *
 * @author xxx
 */
public class MinServer {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ListenSocke listen;
        listen=new ListenSocke();
        listen.start();
    }

}
