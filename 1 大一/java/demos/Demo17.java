
import java.sql.*;
import java.util.*;

public class Demo17{
	
	public static void main(String[] args){
		ArrayList<Music> nusicTop;
		Connection conn;
		Statement stmt;
		ResultSet rs;
		
		try{
			
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			
			conn=DriverManager.getConnection("jdbc:odbc:music");
			stmt=conn.createStatement();
			
			String sql="SELECT * FROM music_sort";
			rs=stmt.executeQuery(sql);
			
			nusicTop=new ArrayList();
			
			Music mus;
			double no;
			String n1,n2;
			while(rs.next()){
				no=rs.getDouble(1);
				n1=rs.getString(2);
				n2=rs.getString(3);
				mus=new Music((int)no,n1,n2);
				nusicTop.add(mus);
				
				//System.out.println(no+"  "+n1+"  "+n2);
				
			}
			rs.close();
			stmt.close();
			conn.close();
			
			for(Music m:nusicTop){
				System.out.println(m.getNo()+"  ");
		    }
			
			
		}catch(ClassNotFoundException e){
			e.printStackTrace();
		}catch(SQLException se){
			se.printStackTrace();
		}		
		
	}
}


