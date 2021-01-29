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
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                
            }
        }

        protected void register_Click(object sender, EventArgs e)
        {
            //连接数据库
            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            //Response.Write("操作成功！");
            //检测用户是否已经被注册
            string checksql = "SELECT count(*) FROM registers WHERE account ='" + account_TextBox1.Text + "'" + "AND pw = '" + Request.Form["pa"] + "'";
            //Response.Write(checksql);
            SqlCommand cmd = new SqlCommand(checksql, conn);
            int i = Convert.ToInt32(cmd.ExecuteScalar());
            if (i > 0)
            {
                //if already exist
                //记录该病人的账号
                Class1.primary_account = account_TextBox1.Text;

                Response.Write("<script language='javascript'> window.open('AppointmentPage.aspx','_parent')</script>");
            }
            else
            {
                // if not
                remind_info.Text = ("用户名或密码错误！");
            }
            conn.Close();
            //并发量（同一时间 200次/毫秒）、IP访问能量
        }

        protected void new_register_Click(object sender, EventArgs e)
        {
            Response.Redirect("http://localhost:64854/NewRegisterPage.aspx", false);
        }

        

    }
}