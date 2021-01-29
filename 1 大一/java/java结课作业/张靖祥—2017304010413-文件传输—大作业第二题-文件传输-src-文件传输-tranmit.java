package 文件传输;

import java.io.*;
import java.net.*;

public class tranmit {

    String ip_config;
    String soc;
    String location;

    Socket client;
    boolean flag = true;
    FileInputStream fis;//此输入流负责读取本机上要传输的文件
    DataOutputStream dos;//此输出流负责向另一台电脑(服务器端)传输数据
    DataInputStream dis;//此输入流负责读取另一台电脑的回应信息
    
    
    tranmit(String ip_config, String soc, String locationt) {
        this.ip_config = ip_config;
        ip_config="\""+ip_config+"\"";
        
        this.soc = soc;
        this.location = locationt.replace("\\","\\\\");
    //   File fe=new File(location);
    //   System.out.println(fe.getPath()+"\\");
   //     System.out.println(location);
  //      System.out.println( );
    //    this.location="\""+this.location+"\"";
        
    }

    boolean do_it() {
        try {  
            client = new Socket(ip_config, Integer.valueOf(soc));
            dos = new DataOutputStream(client.getOutputStream());
            dis = new DataInputStream(client.getInputStream());
            System.out.println("已连接");
          
            transmit(new File( location));
            
            String s = "/]00";//提示传输完毕的标记
            byte b[] = s.getBytes();
            dos.write(b, 0, s.length());//将传输完毕的标志发送出去
            dos.flush();
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }
    
     public void transmit(File f) throws IOException//这是传输的核心,而且将被递归
    {
        byte b[];
        String ts;
        int ti;
        for (File f1 : f.listFiles()) { //首先通过if语句判断f1是文件还是文件夹 
            if (f1.isDirectory()) //fi是文件夹,则向服务器端传送一条信息
            {
                ts = "/]0f" + ((f1.getPath()+"\\").replace(location.replace("\\\\", "\\"), ""));//"/]0f"用于表示这条信息的内容是文件夹名称
                b = ts.getBytes();
                dos.write(b);
                dos.flush();
                dis.read();
                transmit(f1);//由于f1是文件夹(即目录),所以它里面很有可能还有文件或者文件夹,所以进行递归
            } else {
                fis = new FileInputStream(f1);
                ts = "/]0c" + ((f1.getPath()+"\\").replace(location.replace("\\\\", "\\"), ""));//同上,表示这是一个文件的名称
                b = ts.getBytes();
                dos.write(b);
                dos.flush();
                dis.read();
                dos.writeInt(fis.available());//传输一个整型值,指明将要传输的文件的大小
                dos.flush();
                dis.read();
                b = new byte[10000];
                while (fis.available() > 0)//开始传送文件
                {
                    ti = fis.read(b);
                    dos.write(b, 0, ti);
                    dos.flush();
                }
                dos.flush();
                fis.close();
                dis.read();
            }
        }

    }
}
