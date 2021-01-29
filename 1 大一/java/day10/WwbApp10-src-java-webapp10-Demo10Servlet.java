package webapp10;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Demo10Servlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        String value = request.getParameter("name");
    //    response.setCharacterEncoding("UTF-8");

        out.print("<html>");
        out.print("<head>");
        out.print("<title>" + value+"</title>");
        out.print("<meta charset=\"UTF-8\">");
        out.print("</head>");

        out.print("<body bgcolor=#0000f0>");
        out.print("<center>");
        out.print("<h1>" + value + "Servlet Demol</h1>");
        out.print("<hr width=\"90%\" color=\"#00ff00\">");
        out.print(" </center>");
        out.print("  </body>");

        out.print("</html>");

    }

    @Override
    public String getServletInfo() {
        return "Short description";
    }

}
