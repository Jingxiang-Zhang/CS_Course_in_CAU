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
    public partial class ConsultationPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
            time.Text = DateTime.Now.Date.ToString();
            Label1.Text = Class1.primary_Dno ;
            PatientSituation.Text = "病人部分预约信息：";
            GridView1.DataBind();

        }

        protected void Add1_Medicine_Click(object sender, EventArgs e)
        {
            Literal2.Text = "";
            if (GridView1.Rows.Count > 0)
            {
                Class1.primary_Pno = GridView1.Rows[0].Cells[0].Text.ToString();
                Class1.primary_Dno = GridView1.Rows[0].Cells[1].Text.ToString();
            }
            else return; 

            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            string Mno, Mname = Request.Form["DropDownList1"], Mamount = Request.Form["DropDownList2"] ;
            string sel_sql = "SELECT Mno FROM medicine WHERE Mname ='" + Mname +"'";
            SqlCommand cmd = new SqlCommand(sel_sql, conn);
            Mno = cmd.ExecuteScalar().ToString();
            nowPno.Text = Class1.primary_Pno;
            string ins_sql = "INSERT INTO patientchart(Pno,Dno,DueTime,Csympton,Mno,Mamount)VALUES('" + Class1.primary_Pno + "','" + Class1.primary_Dno + "','" + DateTime.Now.Date.ToString() + "','" + SymptonBox.Text + "','" + Mno + "','" + Mamount + "')";
            cmd = new SqlCommand(ins_sql, conn);
            cmd.ExecuteNonQuery();
        

            conn.Close();
            Literal1.Text = "添加成功。";
            GridView2.DataBind();
        }

        protected void Delete1_Medicine_Click(object sender, EventArgs e)
        {
            Literal1.Text = "";
            if (GridView1.Rows.Count > 0)
            {
                Class1.primary_Pno = GridView1.Rows[0].Cells[0].Text.ToString();
                Class1.primary_Dno = GridView1.Rows[0].Cells[1].Text.ToString();
            }
            else return;

            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            string Mno, Mname = Request.Form["DropDownList1"], Mamount = Request.Form["DropDownList2"];
            string sel_sql = "SELECT Mno FROM medicine WHERE Mname ='" + Mname + "'";
            SqlCommand cmd = new SqlCommand(sel_sql, conn);
            Mno = cmd.ExecuteScalar().ToString();

            string ins_sql = "DELETE FROM patientchart WHERE Mno = '" + Mno + "'AND Mamount = '" + Mamount + "'AND Pno = '" + Class1.primary_Pno + "'AND Dno = '" + Class1.primary_Dno + "'";
            cmd = new SqlCommand(ins_sql, conn);
            cmd.ExecuteNonQuery();

            conn.Close();
            Literal2.Text = "删除成功。";
            GridView2.DataBind();
        }

        protected void Delete2_Medicine_Click(object sender, EventArgs e)
        {
            Literal3.Text = "";
            if (GridView1.Rows.Count > 0)
            {
                Class1.primary_Pno = GridView1.Rows[0].Cells[0].Text.ToString();
                Class1.primary_Dno = GridView1.Rows[0].Cells[1].Text.ToString();
            }
            else return;

            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            string Mno, Mname = Request.Form["DropDownList4"], Mamount = Request.Form["DropDownList3"];
            string sel_sql = "SELECT Mno FROM medicine WHERE Mname ='" + Mname + "'";
            SqlCommand cmd = new SqlCommand(sel_sql, conn);
            Mno = cmd.ExecuteScalar().ToString();

            string ins_sql = "DELETE FROM patientchart WHERE Mno = '" + Mno + "'AND Mamount = '" + Mamount + "'AND Pno = '" + Class1.primary_Pno + "'AND Dno = '" + Class1.primary_Dno + "'";
            cmd = new SqlCommand(ins_sql, conn);
            cmd.ExecuteNonQuery();

            conn.Close();
            Literal4.Text = "删除成功。";
            GridView2.DataBind();
        }

        protected void Add2_Medicine_Click(object sender, EventArgs e)
        {
            Literal4.Text = "";
            if (GridView1.Rows.Count > 0)
            {
                Class1.primary_Pno = GridView1.Rows[0].Cells[0].Text.ToString();
                Class1.primary_Dno = GridView1.Rows[0].Cells[1].Text.ToString();
            }
            else return;

            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            string Mno, Mname = Request.Form["DropDownList4"], Mamount = Request.Form["DropDownList3"];
            string sel_sql = "SELECT Mno FROM medicine WHERE Mname ='" + Mname + "'";
            SqlCommand cmd = new SqlCommand(sel_sql, conn);
            Mno = cmd.ExecuteScalar().ToString();
            nowPno.Text = Class1.primary_Pno;
            string ins_sql = "INSERT INTO patientchart(Pno,Dno,DueTime,Csympton,Mno,Mamount)VALUES('" + Class1.primary_Pno + "','"+ Class1.primary_Dno + "','"+ DateTime.Now.Date.ToString() +"','"+SymptonBox.Text + "','" + Mno + "','" + Mamount + "')";
            cmd = new SqlCommand(ins_sql, conn);
            cmd.ExecuteNonQuery();
            
            conn.Close();
            Literal3.Text = "添加成功。";
            GridView2.DataBind();
        }

        protected void Prescription_Click(object sender, EventArgs e)
        {
            //连接数据库
            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            string sql = "UPDATE consultation SET Vregister = 1 WHERE Vno ='" + Class1.primary_Pno + "'AND Dno = '" + Class1.primary_Dno + "'";
            SqlCommand cmd = new SqlCommand(sql, conn);
            cmd.ExecuteNonQuery();

            conn.Close();
            Response.Redirect("http://localhost:64854/ConsultationPage.aspx", false);
        }
    }
}