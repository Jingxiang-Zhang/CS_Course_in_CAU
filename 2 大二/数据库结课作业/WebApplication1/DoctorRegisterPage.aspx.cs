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
    public partial class DoctorRegisterPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Doctor_Click(object sender, EventArgs e)
        {
            //连接数据库
            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            //Response.Write("操作成功！");
            //检测用户是否已经被注册
            string checksql = "SELECT count(*) FROM doctors WHERE Daccount ='" + account_TextBox1.Text + "'" + "AND Dpw = '" + Request.Form["pa"] + "'";
            //Response.Write(checksql);
            SqlCommand cmd = new SqlCommand(checksql, conn);
            int i = Convert.ToInt32(cmd.ExecuteScalar());
            if (i > 0)
            {
                //if already exist
                //记录该大夫的账号
                Class1.primary_account = account_TextBox1.Text;
                string sql = "SELECT Dno FROM doctors WHERE Daccount ='" + account_TextBox1.Text + "'" + "AND Dpw = '" + Request.Form["pa"] + "'";
                cmd = new SqlCommand(sql, conn);
                Class1.primary_Dno = cmd.ExecuteScalar().ToString();
                Response.Redirect("http://localhost:64854/ConsultationPage.aspx", false);

            }
            else
            {
                // if not
                remind_info.Text = ("用户名或密码错误！");
            }
            conn.Close();
            //并发量（同一时间 200次/毫秒）、IP访问能量
        }
    }
}