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
    public partial class appointment : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Button1_Click(object sender, EventArgs e)    
        {
            
            string Psex = Request.Form["DropDownList3"];
            string Pname = TextBox1.Text;
            string Pno = TextBox5.Text;//ID card number
            Class1.primary_Pno =     Pno;
            string Pphone = TextBox4.Text;
            string Paddress = TextBox6.Text;
            if (Psex == "" || Pname == "" || Pno == "" || Pphone == "")
            {
                Literal1.Text = "请填写所有必填项，并选择预约时间后再提交！";
                return;
            }

            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            
            
            //记录病人的预约信息，包括预约的大夫、预约的时间
            //获取预约的时间以及医生的员工序号
            string aptm_time =  Calendar1.SelectedDate.ToString();
            string doctorName = Request.Form["DropDownList2"];
            string doctorOffice = Request.Form["DropDownList1"];

            

            //查询预约大夫的Dno
            string ins_sql2 = "Select Distinct Dno From doctors WHERE Doffice ='" + doctorOffice + "' AND Dname ='" + doctorName + "'";
            SqlCommand cmd2 = new SqlCommand(ins_sql2, conn);
            string Dno = cmd2.ExecuteScalar().ToString();
            Class1.primary_Dno = Dno;
            
            //更新patient表记录病人看病的时间
            string ins_sql1 = "Insert Into patient(Pno,Pname,Psex,Paddress,Pphone,Ptime,DueTime,Dno)VALUES('" + Pno + "','" + Pname + "','" + Psex + "','" + Paddress + "','" + Pphone + "','" + DateTime.Now.Date.ToString() + "','" + aptm_time +"','" + Dno + "')";
            SqlCommand cmd1 = new SqlCommand(ins_sql1, conn);
            cmd1.ExecuteNonQuery();
            
            //更新预约表
            //string ins_sql3 = "Insert Into patientchart(Pno,Dno,DueTime)VALUES('" + Pno + "','" + Dno + "','" + aptm_time + "')";
            //SqlCommand cmd3 = new SqlCommand(ins_sql3, conn);
            //cmd3.ExecuteNonQuery();

            //查询目前等待人数，得到自己的序号
            string ins_sql4 = "Select Distinct Dnum From doctors WHERE Dno = '" + Dno + "'";
            SqlCommand cmd4 = new SqlCommand(ins_sql4, conn);
            Class1.tp = cmd4.ExecuteScalar().ToString();
            
            //更新consultation表
            string ins_sql5 = "Insert Into consultation(Vno,Dno,Vappointment,Vregister,Vmedicine)VALUES('" + Pno + "','" + Dno + "','1','0','0')";
            SqlCommand cmd5 = new SqlCommand(ins_sql5, conn);
            cmd5.ExecuteNonQuery();

            conn.Close();
            Response.Redirect("http://localhost:64854/WaitPage.aspx", false);
        }

        protected void SqlDataSource1_Selecting(object sender, SqlDataSourceSelectingEventArgs e)
        {

        }

        protected void EntityDataSource1_Selecting(object sender, EntityDataSourceSelectingEventArgs e)
        {

        }
    }
}