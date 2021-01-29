using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace CowCow.Models
{
    public class UserLogin
    {
        public string userid { get; set; }
        public string password { get; set; }
        public static int loginsuccesful = 0;
}

}