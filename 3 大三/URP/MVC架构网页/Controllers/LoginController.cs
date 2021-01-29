using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.IO;

namespace CowCow.Controllers
{
    public class LoginController : Controller
    {
        // GET: Login
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Checkin(CowCow.Models.UserLogin user)
        {
            string url = Request.Url.ToString();
            string num = url.Substring(17, 5);
            url = CowCow.ProgramConfig.userloc;
            StreamReader stream = new StreamReader(url);
            while (true)
            {
                string str = stream.ReadLine();
                if (str == null) break;
                string[] cont = str.Split('#');
                string pwd = cont[1];
                string uid = cont[0];
                
                if (uid ==user.userid && pwd == user.password)
                {
                    Models.UserLogin.loginsuccesful = 1;
                    return Json("1");
                }

            }
            return Json("0");
        }
        public ActionResult Checkout()
        {
            Models.UserLogin.loginsuccesful = 0;
            return Json("1");

        }
        public ActionResult CheckinWithoutPwd()
        {
            Models.UserLogin.loginsuccesful = 1;
            return Json("1");

        }
    }
}