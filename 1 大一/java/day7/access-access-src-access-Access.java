package access;

import java.sql.*;

public class Access {

    public static void main(String[] args) {
        try {
            Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
            Connection con = DriverManager.getConnection("jdbc:ucanaccess://C:\\Users\\lenovo\\Desktop\\java作业\\公益报名表.accdb", "", "");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from [table]");
            
            int time = 0;
            int time2 = 0;
            String[] name = new String[50];
            String[] gender = new String[50];
            String[] home = new String[50];
            String[] date = new String[50];
            while (rs.next()) {
                name[time] = rs.getString("姓名");
                gender[time] = rs.getString("性别");
                home[time] = rs.getString("居住地");
                date[time] = rs.getString("报名日期");
                time = time+1;        
            }
            System.out.println(name[0]);
            System.out.println(name[1]);
            rs.close();
            stmt.close();
            con.close();

        } catch (Exception e) {
            e.printStackTrace();
        }

    }
