using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.IO;
using CowCow.Models;

namespace CowCow.Controllers
{
    public class CowPictureShowController : Controller
    {
        // GET: CowPictureShow
        public ActionResult Index()
        {
            return View();
        }
        static string location = CowCow.ProgramConfig.pictureloc;
        static DirectoryInfo root;
        static DirectoryInfo[] dics;
        public static int getCowFactoryNum()
        {
            root = new DirectoryInfo(location);
            dics = root.GetDirectories();
            return dics.Length;
        }
        public static string[] getCowFactoryName()
        {
            string[] name = new string[dics.Length];
            for (int i = 0; i < dics.Length; i++)
            {
                name[i] = dics[i].Name;
            }
            return name;
        }
        public static void getImageAndText()
        {          
            string loc = dics[0].FullName + "\\introduction.txt";
            StreamReader stream = new StreamReader(loc);
            CowCow.Models.CowPic.information = stream.ReadLine();
            stream.Close();
            CowCow.Models.CowPic.currentname = dics[0].Name;

            DirectoryInfo nowloc = new DirectoryInfo(dics[0].FullName);
            DirectoryInfo[] picdirs = nowloc.GetDirectories();
            CowCow.Models.CowPic.picnumber = picdirs.Length;

            CowCow.Models.CowPic.picloction = new string[picdirs.Length];
            CowCow.Models.CowPic.cowNum = new string[picdirs.Length];
            CowCow.Models.CowPic.cowSortCount = new int[picdirs.Length];
            for (int i = 0; i < picdirs.Length; i++)
            {
                string src = "/CowPicture/" + dics[0].Name + "/";
                DirectoryInfo innerloc = new DirectoryInfo(picdirs[i].FullName);
                src += picdirs[i].Name + "/";
                FileInfo[] innerlocdirs = innerloc.GetFiles();
                if (innerlocdirs.Length == 0)
                {
                    src = @"/Image/default.jpg";
                }
                else
                {
                    src += innerlocdirs[0].Name;
                }
                CowCow.Models.CowPic.picloction[i] = src;
                CowCow.Models.CowPic.cowNum[i] = picdirs[i].Name;
                CowCow.Models.CowPic.cowSortCount[i] = innerlocdirs.Length;

            }
            CowPic.currentCowFactoryLoc = "/CowPicture/" + dics[0].Name + "/";

        }
        public ActionResult getImageAndText(CowCow.Models.CowPic pic)
        {
            int i;
            for (i = 0; i < dics.Length; i++)
            {
                if (dics[i].Name == pic.name)
                    break;
            }
            string loc = dics[i].FullName + "\\introduction.txt";
            StreamReader stream = new StreamReader(loc);
            CowCow.Models.CowPic.information = stream.ReadLine();
            stream.Close();
            CowCow.Models.CowPic.currentname = pic.name;


            DirectoryInfo nowloc = new DirectoryInfo(dics[i].FullName);
            DirectoryInfo[] picdirs = nowloc.GetDirectories();
            CowCow.Models.CowPic.picnumber = picdirs.Length;

            CowCow.Models.CowPic.picloction = new string[picdirs.Length];
            CowCow.Models.CowPic.cowNum = new string[picdirs.Length];
            CowCow.Models.CowPic.cowSortCount = new int[picdirs.Length];
            for (i = 0; i < picdirs.Length; i++)
            {
                string src = "/CowPicture/" + pic.name + "/";
                DirectoryInfo innerloc = new DirectoryInfo(picdirs[i].FullName);
                src += picdirs[i].Name + "/";
                FileInfo[] innerlocdirs = innerloc.GetFiles();
                if (innerlocdirs.Length == 0)
                {
                    src = @"/Image/default.jpg";
                }
                else
                {
                    src += innerlocdirs[0].Name;

                }

                CowCow.Models.CowPic.picloction[i] = src;
                CowCow.Models.CowPic.cowNum[i] = picdirs[i].Name;
                CowCow.Models.CowPic.cowSortCount[i] = innerlocdirs.Length;
            }
            CowPic.currentCowFactoryLoc = "/CowPicture/" + pic.name + "/";

            return Json("true");
        }
        public ActionResult deleteGroup(CowCow.Models.CowPic pic)
        {
            int i;
            for (i = 0; i < dics.Length; i++)
            {
                if (dics[i].Name == Models.CowPic.currentname)
                    break;
            }
            DirectoryInfo nowloc = new DirectoryInfo(dics[i].FullName);
            DirectoryInfo[] picdirs = nowloc.GetDirectories();
            for (i = 0; i < picdirs.Length; i++)
            {
                if (picdirs[i].Name == pic.name)
                {
                    break;
                }
            }
            picdirs[i].Delete(true);
            Models.CowPic pict = new Models.CowPic();
            pict.name = CowCow.Models.CowPic.currentname;
            getImageAndText(pict);
            return Json("true");
        }
        public ActionResult AddGroup(CowCow.Models.CowPic pic)
        {
            int i;
            for (i = 0; i < dics.Length; i++)
            {
                if (dics[i].Name == Models.CowPic.currentname)
                    break;
            }
            DirectoryInfo nowloc = new DirectoryInfo(dics[i].FullName);
            DirectoryInfo[] picdirs = nowloc.GetDirectories();
            for (i = 0; i < picdirs.Length; i++)
            {
                if (picdirs[i].Name == pic.name)
                {
                    return Json("false");
                }
            }
            string path = nowloc.FullName + "\\" + pic.name;
            Directory.CreateDirectory(path);

            Models.CowPic pict = new Models.CowPic();
            pict.name = CowCow.Models.CowPic.currentname;
            getImageAndText(pict);
            return Json("true");
        }
        public ActionResult EditGroup(CowCow.Models.CowPic pic)
        {
            int i;
            for (i = 0; i < dics.Length; i++)
            {
                if (dics[i].Name == Models.CowPic.currentname)
                    break;
            }
            DirectoryInfo nowloc = new DirectoryInfo(dics[i].FullName);
            DirectoryInfo[] picdirs = nowloc.GetDirectories();
            for (i = 0; i < picdirs.Length; i++)
            {
                if (picdirs[i].Name == pic.name)
                {
                    CowPic.cowSortName = pic.name;
                    break;
                }                
            }
            CowPic.currentFullFacSortName = picdirs[i].FullName;
            DirectoryInfo nowlocPic = new DirectoryInfo(picdirs[i].FullName);
            FileInfo[] Allpicdirs = nowlocPic.GetFiles();
            
            int num = 0;
            for (i = 0; i < Allpicdirs.Length; i++) 
            {
                if (Allpicdirs[i].Extension == ".jpg")
                {
                    num++;
                }
            }
            CowPic.cowBunchPicNum = num;
            CowPic.cowBunchPicName = new string[num];
            CowPic.cowBunchPicLoc = new string[num];
            num = 0;
            for (i = 0; i < Allpicdirs.Length; i++)
            {
                if (Allpicdirs[i].Extension == ".jpg")
                {
                    CowPic.cowBunchPicName[num] = Allpicdirs[i].Name;
                    string str = CowPic.currentCowFactoryLoc + pic.name + "/" + Allpicdirs[i].Name;
                    CowPic.cowBunchPicLoc[num] = str;
                    num++;
                }
            }
            return Json("true");
        }
        public ActionResult deletePic(CowCow.Models.CowPic pic)
        {
            DirectoryInfo nowloc = new DirectoryInfo(CowPic.currentFullFacSortName);
            FileInfo[] picdirs = nowloc.GetFiles();
            int i;
            for (i = 0; i < picdirs.Length; i++)
            {
                if (picdirs[i].Name == pic.name)
                {
                    break;
                }
            }
            picdirs[i].Delete();
            Models.CowPic pict = new Models.CowPic();
            pict.name = CowCow.Models.CowPic.cowSortName;
            EditGroup(pict);
            return Json("true");
        }
    }
    
}





