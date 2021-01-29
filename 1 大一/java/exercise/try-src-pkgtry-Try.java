package pkgtry;

import java.util.Scanner;
import java.io.*;

/**
 *
 * @author lenovo
 */
public class Try {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        FileInputStream input;

        try {
            input = new FileInputStream("C:\\Users\\lenovo\\Desktop\\java\\day3\\day6\\src\\day6\\Day6.java"
                    + "");
            byte[] buffer = new byte[2048];
            int n;
            do {
                n = input.read(buffer);
                System.out.println(new String(buffer));
            } while (n > -1);
            /*
            String st="  t  s ";
           st=st.trim();
            System.out.println(st);
             */

            input.close();

        } catch (FileNotFoundException t) {

        } catch (IOException t) {
        }
    }

}
