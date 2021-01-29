using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace 作业1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        string name;
        string gender;
        string wed;
        string gusto;
        string telephone;
        string address;
        protected void Page_Load(object sender, EventArgs e)
        {
            name = "";
            name = Request.Form["姓名"];
            gender = Request.Form["gender"];
            wed= Request.Form["wed"];
            gusto = Request.Form["gusto"];
            telephone = Request.Form["telephone"];
            address = Request.Form["address"];
        }
        protected string Getname()
        {
            return name;
        }
        protected string Getgender()
        {
            if (gender == "1") return "男";
            else if (gender == "2") return "女";
            else return "";
        }
        protected string Getwed()
        {
            if (wed == "1") return "已婚";
            else if (wed == "2") return "未婚";
            else return "";
        }
        protected string Getgusto()
        {
            string str = "";
            string[] gus = gusto.Split(',');
            string[] name = { "运动 ", "游泳 ", "购物 ", "音乐 " };
            for(int i = 0; i < gus.Length; i++)
            {
                str += name[Convert.ToInt32(gus[i]) - 1];
            }
            return str;
        }
        protected string Gettel()
        {
            return telephone;
        }
        protected string Getaddress()
        {
            return address;
        }
    }
}