package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class Webcalcu_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
      out.write("        <title>简单的web计算器</title>\n");
      out.write("    </head>\n");
      out.write("    ");

        double result=0;    
        String snum1,snum2,sop;
        double num1=0,num2=0;
        snum1=request.getParameter("num1");
        snum2=request.getParameter("num2");
        sop=request.getParameter("op");
        if(snum1!=null && snum2!=null &&sop!=null){
            
            num1=Double.parseDouble(snum1);
            num2=Double.parseDouble(snum2);
            switch(sop){
                case"+": 
                    result=num1+num2;
                    break;
                case"-": 
                    result=num1-num2;
                    break;
                case"*": 
                    result=num1*num2;
                    break;
                case"/": 
                    result=num1/num2;
                    break;
            }
            
        }
    
      out.write("\n");
      out.write("    <body>\n");
      out.write("    <center>\n");
      out.write("        <br><br><br>\n");
      out.write("        <b>简单的web计算器</b>\n");
      out.write("        <hr width=\"430\">\n");
      out.write("        <form action=\"\" method=\"get\">\n");
      out.write("            <input type=\"text\" name=\"num1\" value=\"");
      out.print(num1);
      out.write("\">\n");
      out.write("            <select name=\"op\">\n");
      out.write("                <option value=\"+\">＋\n");
      out.write("                <option value=\"-\">－\n");
      out.write("                <option value=\"*\">×\n");
      out.write("                <option value=\"/\">÷\n");
      out.write("                    \n");
      out.write("            </select>\n");
      out.write("            <input type=\"text\" name=\"num2\" value=\"");
      out.print(num2);
      out.write("\">\n");
      out.write("            <input type=\"submit\" name=\"ok\" value=\"计算 \">\n");
      out.write("            \n");
      out.write("        </form>\n");
      out.write("        结果：");
      out.print(result);
      out.write("\n");
      out.write("    </center>\n");
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
