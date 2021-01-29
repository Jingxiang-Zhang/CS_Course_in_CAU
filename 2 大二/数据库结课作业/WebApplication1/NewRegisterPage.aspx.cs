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
    public partial class new_register : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void already_register(object sender, EventArgs e)
        {
            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            //Response.Write("操作成功！");
            //检测用户是否已经被注册
            string checksql = "SELECT count(*) FROM registers WHERE account ='" + re_account.Text + "'";
            //Response.Write(checksql);
            SqlCommand cmd = new SqlCommand(checksql, conn);
            int i = Convert.ToInt32(cmd.ExecuteScalar());
            if (i > 0)
            {
                //if already exist
                remind_info.Text = ("该用户名已经被注册！");
            }
            else
            {
                // if not
                remind_info.Text = ("该用户名可以使用。");
                //操作：insert update  delete  select 记录的操作
                string sql = "insert into registers(account,pw,phone)values('" + re_account.Text + "','" + Request.Form["re_pa"] + "','" + ph_num.Text + "')";
                SqlCommand comm = new SqlCommand(sql, conn);
                comm.ExecuteNonQuery();
                Response.Redirect("http://localhost:64854/BeginPage.aspx", false);
                //关闭链接
            }
            conn.Close();
        }
    }
}