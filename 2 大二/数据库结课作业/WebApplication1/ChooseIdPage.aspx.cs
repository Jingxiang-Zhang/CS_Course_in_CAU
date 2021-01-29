using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class ChooseIdPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Patient_Click(object sender, EventArgs e)
        {
            Response.Redirect("http://localhost:64854/BeginPage.aspx", false);
        }
        protected void Doctor_Click(object sender, EventArgs e)
        {
            Response.Redirect("http://localhost:64854/DoctorRegisterPage.aspx", false); 
        }
    }
}