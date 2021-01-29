using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;//tql
using Microsoft.VisualBasic;

namespace WebApplication1
{
    public partial class infomationpage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Literal1.Text = "请先就诊、取药后交费。";
        }
        protected void BackTo_Click(object sender, EventArgs e)
        {
            Response.Redirect("http://localhost:64854/waitpage.aspx", false);
        }
    }
}