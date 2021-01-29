package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;

public final class first_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.List<String> _jspx_dependants;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public java.util.List<String> getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;

    try {
      response.setContentType("text/html;charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <title>绿色地球公益活动报名</title>\n");
      out.write("        <meta charset=\"UTF-8\">\n");
      out.write("        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
      out.write("    </head>\n");
      out.write("    <body background=\"bgp.jpg\" >\n");
      out.write("        <h1 align=\"center\"><font size=\"7\">绿色地球公益活动报名表</font></h1>\n");
      out.write("            ");

                int time = 0;
                String[] name = new String[50];
                String[] gender = new String[50];
                String[] home = new String[50];
                String[] date = new String[50];
                Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
                Connection con = DriverManager.getConnection("jdbc:ucanaccess://C:\\Users\\lenovo\\Desktop\\java作业\\公益报名表.accdb", "", "");
                Statement stmt = con.createStatement();
               
                ResultSet rs = stmt.executeQuery("select * from [table]");
                while (rs.next()) {
                    name[time] = rs.getString("姓名");
                    gender[time] = rs.getString("性别");
                    home[time] = rs.getString("居住地");
                    date[time] = rs.getString("报名日期");
                    time = time + 1;
                }

                rs.close();
                stmt.close();
                con.close();


            
      out.write("\n");
      out.write("        <form action=\"recept.jsp\" method=\"get\">\n");
      out.write("            <table border=\"1\" align=\"center\">\n");
      out.write("                <tr>\n");
      out.write("                    <th width=\"100\"><font size=\"5\" style=\"center\">序号</font></th>\n");
      out.write("                    <th width=\"120\"><font size=\"5\" style=\"center\">姓名</font></th>\n");
      out.write("                    <th width=\"50\"><font size=\"5\" style=\"center\">性别</font></th>\n");
      out.write("                    <th width=\"300\"><font size=\"5\" style=\"center\">居住地</font></th>\n");
      out.write("                    <th width=\"300\"><font size=\"5\" style=\"center\">报名日期</font></th>\n");
      out.write("                </tr>\n");
      out.write("                ");
 for(int i=0;i<time;i++){ 
      out.write("\n");
      out.write("                <tr>\n");
      out.write("                   <th width=\"100\"><font size=\"5\" style=\"center\">");
      out.print( i);
      out.write("</font></th>\n");
      out.write("                    <th width=\"120\"><font size=\"5\" style=\"center\">");
      out.print( name[i]);
      out.write("</font></th>\n");
      out.write("                    <th width=\"50\"><font size=\"5\" style=\"center\">");
      out.print( gender[i]);
      out.write("</font></th>\n");
      out.write("                    <th width=\"300\"><font size=\"5\" style=\"center\">");
      out.print( home[i]);
      out.write("</font></th>\n");
      out.write("                    <th width=\"300\"><font size=\"5\" style=\"center\">");
      out.print( date[i]);
      out.write("</font></th>\n");
      out.write("                </tr>    \n");
      out.write("                ");
 } 
      out.write("\n");
      out.write("            </tr>              \n");
      out.write("                    <th colspan=\"5\"><a href=\"recept.jsp\">点击此处进行报名</font></th>\n");
      out.write("                <tr>\n");
      out.write("            </table>\n");
      out.write("        </form>\n");
      out.write("    </body>\n");
      out.write("</html>\n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
