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

    public partial class waitpage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Class1.tp != "")
                Literal1.Text = "请耐心等待，您的序号为< " + Class1.tp + " >请您听到叫号时前往相应科室就诊。";
            else
                Literal1.Text = "预约失败，请重试！";
        }

        protected void Arrive_Click(object sender, EventArgs e)
        {
            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            string sql = "Insert Into arrive(Dno,Pno,Cdate,Ctime)VALUES('" + Class1.primary_Dno + "','" + Class1.primary_Pno + "','" + DateTime.Now.Date.ToString() + "','" + DateTime.Now.TimeOfDay.ToString() + "')";
            SqlCommand cmd = new SqlCommand(sql, conn);
            cmd.ExecuteNonQuery();
            Class1.primary_register_time = DateTime.Now.ToLocalTime().ToString();
            conn.Close();
            Literal2.Text = "登记成功，请等候叫号。";
        }

        protected void return_Click(object sender, EventArgs e)
        {
            Response.Redirect("http://localhost:64854/BeginPage.aspx", false);
        }
        
        protected void pay_Click(object sender, EventArgs e)
        {
            //连接数据库
            if(Class1.primary_Pno=="" || Class1.primary_Dno == "" || Class1.primary_register_time == ""){
                Response.Redirect("http://localhost:64854/InformationPage.aspx", false);
            }
            else
            {
                string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
                SqlConnection conn = new SqlConnection(strconn);
                conn.Open();
                string sql = "SELECT Vregister FROM consultation WHERE Vno = '" + Class1.primary_Pno + "' AND Dno = '" + Class1.primary_Dno + "'";
                SqlCommand cmd = new SqlCommand(sql, conn);
                int i = Convert.ToInt32(cmd.ExecuteScalar());
                if (i != 0)
                {
                    Class1.primary_can_pay = true;
                    conn.Close();
                    Response.Redirect("http://localhost:64854/PayPage.aspx", false);
                }
                else
                {
                    conn.Close();
                    Response.Redirect("http://localhost:64854/InformationPage.aspx", false);
                }
            }
            
            
        }
    }
}