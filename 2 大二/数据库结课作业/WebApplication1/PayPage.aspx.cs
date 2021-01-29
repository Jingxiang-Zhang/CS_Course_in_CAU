using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;//tql
using Microsoft.VisualBasic;
using System.Data;

namespace WebApplication1
{
    public partial class paypage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void already_pay_Click(object sender, EventArgs e)
        {

            //连接数据库
            string strconn = "server=.\\sqlexpress;user ID=sa;pwd=sa;database=hospital;";//服务器   用户名  密码  数据库
            SqlConnection conn = new SqlConnection(strconn);
            conn.Open();
            //更新consultation表
            string sql = "UPDATE consultation SET Vmedicine = 1 WHERE Vno='" + Class1.primary_Pno + "' AND Dno = '" + Class1.primary_Dno + "'";
            SqlCommand cmd = new SqlCommand(sql, conn);
            cmd.ExecuteNonQuery();

            //更新药品库
            sql = "SELECT COUNT(*) FROM patientchart WHERE Dno ='" + Class1.primary_Dno + "' AND Pno='" + Class1.primary_Pno + "'";
            cmd = new SqlCommand(sql, conn);
            int i = 0, n = Convert.ToInt16(cmd.ExecuteScalar());
            string Mno, Mamount;
            sql = "SELECT * FROM patientchart WHERE Dno ='" + Class1.primary_Dno + "' AND Pno='" + Class1.primary_Pno + "'";
            SqlDataAdapter sda = new SqlDataAdapter(sql, conn);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            while (i < n)
            {
                Mno = dt.Rows[i][4].ToString();
                Mamount = dt.Rows[i][5].ToString();
                sql = "UPDATE medicine SET Mamount = Mamount - '" + Mamount + "' WHERE Mno ='" + Mno + "'";
                cmd = new SqlCommand(sql, conn);
                if (Convert.ToInt16(cmd.ExecuteNonQuery()) == 0)
                {
                    Literal1.Text = "更新失败！请重新确认处方！";
                    return;
                }
                i++;
            }

            //支付完毕则删除病例表中的数据
            sql = "DELETE FROM patientchart WHERE Dno ='" + Class1.primary_Dno + "' AND Pno='" + Class1.primary_Pno + "'AND DueTime ='" + DateTime.Now.Date.ToString() + "'";
            cmd = new SqlCommand(sql, conn);
            cmd.ExecuteNonQuery();

            conn.Close();
            Literal1.Text = "已完成支付！";

            //Response.Redirect("http://localhost:64854/BeginPage.aspx", false);

        }

    }
}