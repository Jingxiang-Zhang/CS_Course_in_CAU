using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.IO;
using CowCow.Models;
using System.Diagnostics;

namespace CowCow.Controllers
{
    public class CowDataController : Controller
    {
        // GET: CowData
        public ActionResult Index()
        {
            return View();
        }
        public ActionResult Create()
        {
            return View();
        }
        public ActionResult Edit()
        {
            return View();
        }
        public ActionResult Learn()
        {
            return View();
        }

        public ActionResult TrainLog()
        {
            return View();
        }

        public ActionResult SavePictureByForm(string factory)
        {
            HttpFileCollectionBase files = Request.Files;
            string path = CowPic.currentFullFacSortName;
            string times = System.DateTime.Now.Year.ToString() + System.DateTime.Now.Month.ToString() +
                System.DateTime.Now.Day.ToString() + System.DateTime.Now.Hour.ToString() +
                System.DateTime.Now.Minute.ToString() + System.DateTime.Now.Second.ToString();
            for (int i = 0; i < files.Count; i++)
            {
                string newpath = path + "\\" + times + "." + i.ToString() + ".jpg";
                files[i].SaveAs(newpath);
            }

            Models.CowPic pict = new Models.CowPic();
            pict.name = CowCow.Models.CowPic.cowSortName;
            CowPictureShowController csc = new CowPictureShowController();
            csc.EditGroup(pict);
            return View("Edit");
        }
        public ActionResult StartLearn(CowCow.Models.CowPic pic)
        {
            string facname = pic.name;
            LearnStateTread newlearn = new LearnStateTread();
            Dictionary<string, string> Config = newlearn.getContent();
            newlearn.AutoSetLoc(facname);
            newlearn.SetNowTimes(0);
            newlearn.SetStop(false);
            newlearn.SetNewTrain(true);
            newlearn.SetTrainTimes(100);
            newlearn.SaveConfig();

            Process pylearn = new Process();
            pylearn.StartInfo.FileName = ProgramConfig.pylearn;
            pylearn.StartInfo.UseShellExecute = false;
            pylearn.StartInfo.RedirectStandardOutput = false;
            pylearn.StartInfo.RedirectStandardInput = true;
            pylearn.StartInfo.CreateNoWindow = true;
            string arg1 = ProgramConfig.pyresult;
            string arg2 = ProgramConfig.pyconfig;
            pylearn.StartInfo.Arguments = "\"" + arg1 + "\"" + " " + "\"" + arg2 + "\"";
            pylearn.Start();
            return Json("true");
        }
        public ActionResult getProgress(CowCow.Models.CowPic pic)
        {
            if (System.IO.File.Exists(ProgramConfig.pyresult))
            {
                StreamReader stream = new StreamReader(ProgramConfig.pyresult);
                string result = stream.ReadLine();
                stream.Close();
                int res = (Convert.ToInt32(result) + 1);
                return Json(res.ToString());
            }
            else
            {
                return Json("-1");
            }
        }

        public ActionResult StopLearn(CowCow.Models.CowPic pic)
        {
            LearnStateTread tread = new LearnStateTread();
            tread.SetStop(true);
            tread.SaveConfig();
            return Json("true");
        }

        public ActionResult ContinueLearn(CowCow.Models.CowPic pic)
        {
            int length = CowPictureShowController.getCowFactoryNum();
            string[] name = CowPictureShowController.getCowFactoryName();
            int nowtimes = 0;
            int sumtimes = 0;
            string readresult = "";
            for (int i = 0; i < length; i++)
            {
                string loc = ProgramConfig.pyresult + "/" + name[i] + ".txt";
                if (System.IO.File.Exists(loc))
                {
                    StreamReader stream = new StreamReader(loc);
                    string value = stream.ReadLine();
                    stream.Close();
                    if (value[0] == 'r')
                    {
                        return Json(name[i]);
                    }
                    else if (name[i] == pic.name)
                    {
                        readresult = value.Substring(1);
                    }
                }
            }
            string[] val = readresult.Split('/');
            nowtimes = Convert.ToInt32(val[0]);
            sumtimes = Convert.ToInt32(val[1]);

            LearnStateTread tread = new LearnStateTread();
            tread.AutoSetLoc(pic.name);
            tread.SetStop(false);
            tread.SetNewTrain(false);
            tread.SetNowTimes(nowtimes);
            tread.SetTrainTimes(sumtimes);
            tread.SaveConfig();

            Process pylearn = new Process();
            pylearn.StartInfo.FileName = ProgramConfig.pylearn;
            pylearn.StartInfo.UseShellExecute = false;
            pylearn.StartInfo.RedirectStandardOutput = false;
            pylearn.StartInfo.RedirectStandardInput = true;
            pylearn.StartInfo.CreateNoWindow = true;
            string arg1 = ProgramConfig.pyresult;
            string arg2 = ProgramConfig.pyconfig;
            pylearn.StartInfo.Arguments = "\"" + arg1 + "\"" + " " + "\"" + arg2 + "\"";
            pylearn.Start();
            return Json("");
        }

        public ActionResult getLearnState(CowCow.Models.CowPic pic)
        {
            int length = CowPictureShowController.getCowFactoryNum();
            string[] name = CowPictureShowController.getCowFactoryName();
            string json = length.ToString() + ",";
            for (int i = 0; i < length; i++)
            {
                string loc = ProgramConfig.pyresult + "/" + name[i] + ".txt";
                json = json + name[i] + ":";

                if (System.IO.File.Exists(loc))
                {
                    StreamReader stream = new StreamReader(loc);
                    string value = stream.ReadLine();
                    stream.Close();
                    json = json + value;
                }
                else
                {
                    json = json + "0";
                }
                json = json + ",";
            }
            return Json(json);
        }

        public static List<string> GetLogs()
        {
            List<string> logs = new List<string>();
            if (System.IO.File.Exists(ProgramConfig.pytrainlog))
            {
                StreamReader stream = new StreamReader(ProgramConfig.pytrainlog, System.Text.Encoding.Default);
                string linetext;
                while ((linetext = stream.ReadLine()) != null)
                {
                    logs.Add(linetext);
                }
                stream.Close();
            }
            return logs;
        }
        public ActionResult Deletelog()
        {
            if (System.IO.File.Exists(ProgramConfig.pytrainlog))
            {
                StreamWriter stream = new StreamWriter(ProgramConfig.pytrainlog, false);
                stream.Write("\n\n\n");
                stream.Close();
                stream = new StreamWriter(ProgramConfig.pyerrorlog, false);
                stream.Write("\n\n\n");
                stream.Close();
            }
            return Json("");
        }


        public ActionResult StartCowTest(CowCow.Models.CowPic pic)
        {
            string[] facAndCam = pic.name.Split('/');
            TestCowTransation newtest = new TestCowTransation();
            if (facAndCam[0] == TestCowTransation.previousFac) //工厂相等的情况下，比较摄像头
            {
                if (facAndCam[1] != TestCowTransation.previousCam)
                {
                    newtest.AutoSetLoc(facAndCam[0], facAndCam[1]);
                }
                return Json("false");
            }

            TestCowTransation.previousFac = facAndCam[0];
            if (TestCowTransation.previousFac != "")  //如果是首次打开
            {
                newtest.SetStop(true);
                newtest.SaveConfig();
                System.Threading.Thread.Sleep(1200);   //停止之前进程，等待1.2秒
            }

            newtest.SetStop(false);
            newtest.AutoSetLoc(facAndCam[0], facAndCam[1]);
            newtest.SaveConfig();
            //开启新进程
            Process pylearn = new Process();
            pylearn.StartInfo.FileName = ProgramConfig.pyTestCow;
            pylearn.StartInfo.UseShellExecute = false;
            pylearn.StartInfo.CreateNoWindow = true;

            string arg1 = ProgramConfig.pyImageTestConfig;
            pylearn.StartInfo.Arguments = arg1;
            pylearn.Start();

            return Json(arg1);
        }
        public ActionResult CloseCowTest()
        {
            TestCowTransation newtest = new TestCowTransation();
            newtest.SetStop(true);
            newtest.SaveConfig();
            return Json("true");
        }
    }
}