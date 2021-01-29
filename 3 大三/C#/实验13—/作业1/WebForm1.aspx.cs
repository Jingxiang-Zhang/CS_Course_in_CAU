using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MySql.Data.MySqlClient;
using System.Data;
using System.Configuration;
using System.Drawing;

namespace 作业1
{
    public partial class WebForm1 : System.Web.UI.Page
    {

        protected void Page_Load(object sender, EventArgs e)
        {
            GridView1.Attributes.Add("BorderColor", "aliceblue");

            GridView1.ShowHeader = true;     
            GridView1.HeaderStyle.ForeColor = Color.White;
            GridView1.RowStyle.HorizontalAlign = HorizontalAlign.Center;
            GridView1.PagerStyle.HorizontalAlign = HorizontalAlign.Center;
            GridView1.PagerStyle.BackColor = ColorTranslator.FromHtml("#3300FF");
            GridView1.PagerStyle.ForeColor = Color.White;
            GridView1.Columns[0].Visible = false;
            GridView1.PagerStyle.Font.Italic = true;
        }

        protected void GridView1_RowDataBound(object sender, GridViewRowEventArgs e)
        {
            if (e.Row.RowType == DataControlRowType.DataRow)
            {
                if (e.Row.RowIndex % 2 == 0)
                {
                    //设置偶数行背景颜色
                    e.Row.BackColor = ColorTranslator.FromHtml("#CCFFFF");
                }
                //鼠标滑过背景颜色
                e.Row.Attributes.Add("onMouseOver", "Color=this.style.backgroundColor;this.style.backgroundColor='#99CCFF';this.style.cursor='hand'");
                e.Row.Attributes.Add("onMouseOut", "this.style.backgroundColor=Color;");
                if (e.Row.Cells[2].FindControl("lable2") != null)
                {
                    Label label = (Label)e.Row.Cells[11].FindControl("lable2");
                    label.Text = e.Row.Cells[3].Text;
                    label.ForeColor = Color.Red;
                }
                if (e.Row.Cells[2].FindControl("lable4") != null)
                {
                    Label label = (Label)e.Row.Cells[11].FindControl("lable4");
                    label.Text = e.Row.Cells[4].Text;
                    label.ForeColor = Color.Blue;
                }
                e.Row.Cells[3].Visible = false;
                if (e.Row.Cells[11].FindControl("lable1") != null)
                {
                    Label label = (Label)e.Row.Cells[11].FindControl("lable1");
                    label.Text = e.Row.Cells[9].Text.Split(' ')[0];
                }
                e.Row.Cells[9].Visible = false;
                e.Row.Cells[12].ForeColor = Color.Black;
                e.Row.Cells[13].ForeColor = Color.Black;
                e.Row.Cells[14].ForeColor = Color.Blue;
            }
            if (e.Row.RowType == DataControlRowType.Header)
            {
                e.Row.BackColor = ColorTranslator.FromHtml("#3300FF");
            }


        }
        protected void GridView1_RowCreated(object sender, GridViewRowEventArgs e)
        {
            if (e.Row.RowType != DataControlRowType.DataRow) return;

            if (e.Row.FindControl("Button1") != null)
            {
                Button CtlButton = (Button)e.Row.FindControl("Button1");
                CtlButton.Click += new EventHandler(CtlButton_Click);
            }
            
            if (e.Row.FindControl("select") != null)
            {
                LinkButton CtlButton = (LinkButton)e.Row.FindControl("select");
                CtlButton.Click += new EventHandler(Select_Click);
            }
        }
        private void Select_Click(object sender, EventArgs e)
        {
            Response.Write("<script language='javascript'>" +
                "var mydata = \"test\";" +
                "mydata.select();" +
                "document.execCommand(\"Copy\") " +
                "</script>");
            
            Response.Write("<script language='javascript'>alert('内容已复制');</script>");
        }

            private void CtlButton_Click(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            GridViewRow gvr = (GridViewRow)button.Parent.Parent;
            string pk = GridView1.DataKeys[gvr.RowIndex].Value.ToString();
            int row_num = Convert.ToInt32(pk) - 1;
            row_num = row_num % 20;
            string day = GridView1.Rows[row_num].Cells[9].Text.Split(' ')[0];
            string[] days = day.Split('/');
            DateTime dateTime = new DateTime(Convert.ToInt32(days[0]),
                                            Convert.ToInt32(days[1]),
                                            Convert.ToInt32(days[2]));
            TimeSpan timeSpan = DateTime.Now - dateTime;
            string year = (timeSpan.Days / 365).ToString();

            Response.Write("<script language='javascript'>alert('该职工的工龄为"+year+"年');</script>");
        }

    }
}   
