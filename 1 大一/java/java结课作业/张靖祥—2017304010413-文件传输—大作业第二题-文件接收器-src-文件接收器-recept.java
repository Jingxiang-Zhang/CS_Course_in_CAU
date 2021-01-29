package 文件接收器;

import java.io.*;
import java.net.*;

public class recept {

    String address;

    ServerSocket server = null;
    Socket client = null;
    boolean flag = true;
    DataInputStream dis;
    DataOutputStream dos;
    FileOutputStream fos;

    public recept() {
        try {
            address = InetAddress.getLocalHost().getHostAddress();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public boolean recept_start() {
        try {
            server = new ServerSocket(9999);
            System.out.println("端口号:" + server.getLocalPort());
            client = server.accept();
            System.out.println("连接完毕");
            dis = new DataInputStream(client.getInputStream());
            dos = new DataOutputStream(client.getOutputStream());
            String answer = "g";
            byte ans[] = answer.getBytes();
            byte b[] = new byte[1000];
            int ti;
            new File("C:\\Users\\lenovo\\Desktop\\目标文件").mkdirs();
            while (flag) {
                ti = dis.read(b);
                dos.write(ans);
                String select = new String(b, 0, ti);
                if (select.contains("/]0f")) {
                    File f = new File("C:\\Users\\lenovo\\Desktop\\目标文件\\" + (select.replace("/]0f", "")));
                    System.out.println("creat directory");
                    f.mkdirs();
                } else if (select.contains("/]0c")) {
                    fos = new FileOutputStream("C:\\Users\\lenovo\\Desktop\\目标文件\\" + (select.replace("/]0c", "")));
                    String cs;
                    boolean cflag = true;
                    int tip = dis.readInt();
                    dos.write(ans);
                    while (tip > 0) {
                        ti = dis.read(b, 0, (tip > 1000 ? 1000 : tip));
                        tip = tip - ti;
                        cs = new String(b, 0, 4);
                        fos.write(b, 0, ti);
                    }
                    fos.flush();
                    fos.close();
                    dos.write(ans);
                } else if (select.contains("/]00")) {
                    flag = false;
                }
            }

            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

    }

    public String get_ip() {
        return address;
    }
}
