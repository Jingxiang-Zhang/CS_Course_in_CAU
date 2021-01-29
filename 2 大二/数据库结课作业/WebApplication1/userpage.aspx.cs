using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class userpage : System.Web.UI.Page
    {
        string username2 = "";
        string shenfenzhenghao = "";
        string yonghuxingming = "";
        string shifouyuyue = "";
        string shifouguahao = "";
        static string jiuzhendanhao2 = "";
        static string shifoukanwanbing = "";

        protected void Page_Load(object sender, EventArgs e)
        {
            username2 = Request.QueryString["username"];
            shenfenzhenghao = Request.QueryString["shenfenzhenghao"];
            yonghuxingming = Request.QueryString["yonghuxingming"];

        }
        protected string get_shifoukanwanbing()
        {
            return shifoukanwanbing;
        }
        protected string get_yonghuxingming()
        {
            return yonghuxingming;
        }
        protected int tableresult(string[] jiuzhendanhao, string[] shifouyuyue, string[] shifouguahao, string[] jiuzhenriqi, string[] shifoujiaofei)
        {

            string strconn = "server=.\\sqlexpress ;user ID=sa;pwd=sa;database=database no.9;";
            System.Data.SqlClient.SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            //创建一个sql命令
            SqlCommand cmd = conn.CreateCommand();
            string sql2 = "SELECT * FROM [dbo].[就诊表] where 身份证号='" + shenfenzhenghao + "';";
            cmd.CommandText = sql2;

            DataTable dt = new DataTable();
            SqlDataAdapter sda = new SqlDataAdapter(cmd);
            sda.Fill(dt);
            int i = 0;
            try
            {
                while (true)
                {
                    jiuzhendanhao[i] = dt.Rows[i]["就诊单号"].ToString().Trim();
                    shifouyuyue[i] = dt.Rows[i]["是否预约"].ToString().Trim();
                    shifouguahao[i] = dt.Rows[i]["是否挂号"].ToString().Trim();
                    jiuzhenriqi[i] = dt.Rows[i]["就诊日期"].ToString().Trim();
                    shifoujiaofei[i] = dt.Rows[i]["是否缴费"].ToString().Trim();
                    jiuzhendanhao2 = jiuzhendanhao[i];
                    shifoukanwanbing= dt.Rows[i]["是否看完病"].ToString().Trim();
                    i++;
                }
            }
            catch
            {
                
            }
            conn.Close();
            return i;
        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            string date1 = Calendar1.SelectedDate.ToString().Trim().Substring(0, 8);
            string strconn = "server=.\\sqlexpress ;user ID=sa;pwd=sa;database=database no.9;";
            System.Data.SqlClient.SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            //创建一个sql命令
            SqlCommand cmd = conn.CreateCommand();
            string count_jiuzhendan_no_sql = "SELECT COUNT(*) result FROM [dbo].[就诊表] ";
            cmd.CommandText = count_jiuzhendan_no_sql;
            DataTable dt = new DataTable();
            dt = new DataTable();
            SqlDataAdapter sda = new SqlDataAdapter(cmd);
            sda.Fill(dt);
            int jiuzhendanno = int.Parse(dt.Rows[0]["result"].ToString().Trim());
            jiuzhendanno += 1;
            //将结果输入到数据库


            string sql = "INSERT INTO[dbo].[就诊表] VALUES(N'" + jiuzhendanno + " " +
                 "',N'" + shenfenzhenghao +
                 "', N'" + "Y" +
                 "', N'" + "N" +
                 "', N'" + date1 +
                 "', N'" + yonghuxingming +
                 "', N'" + "N" +
                 "', N'" + "N" +
                 "')";
            SqlCommand comm = new SqlCommand(sql, conn);
            comm.ExecuteNonQuery();
            Response.Write("<script language = 'javascript'> window.open('userpage?username=" +
                           username2 + "&shenfenzhenghao=" +
                           shenfenzhenghao + "&yonghuxingming=" +
                           yonghuxingming + "','_parent')</script>");            //关闭链接
        }
        protected void jiaofei_Click(object sender, EventArgs e)
        {
            string strconn = "server=.\\sqlexpress ;user ID=sa;pwd=sa;database=database no.9;";
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            //计算一共有多少条记录
            //创建一个sql命令
            SqlCommand cmd = conn.CreateCommand();
            string sql = "UPDATE [dbo].[就诊表] set 是否缴费='Y' where 就诊单号=N'" + jiuzhendanhao2 + "';";
            SqlCommand comm = new SqlCommand(sql, conn);
            comm.ExecuteNonQuery();
            //关闭链接
            conn.Close();
           
             Response.Write("<script language = 'javascript'> window.open('userpage?username=" +
                username2 + "&shenfenzhenghao=" +
                shenfenzhenghao + "&yonghuxingming=" +
                yonghuxingming + "','_parent')</script>");
        }
        protected void guahao_Click(object sender, EventArgs e)
        {
            Response.Write(jiuzhendanhao2);
            string strconn = "server=.\\sqlexpress ;user ID=sa;pwd=sa;database=database no.9;";
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            //计算一共有多少条记录
            //创建一个sql命令
            SqlCommand cmd = conn.CreateCommand();
            string sql = "UPDATE [dbo].[就诊表] set 是否挂号='Y' where 就诊单号=N'" + jiuzhendanhao2 + "';";
            SqlCommand comm = new SqlCommand(sql, conn);
            comm.ExecuteNonQuery();
            //关闭链接
            conn.Close();

            Response.Write("<script language = 'javascript'> window.open('userpage?username=" +
               username2 + "&shenfenzhenghao=" +
               shenfenzhenghao + "&yonghuxingming=" +
               yonghuxingming + "','_parent')</script>");
        }
    }
}