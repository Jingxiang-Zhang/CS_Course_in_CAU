using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;


namespace CowCow.Models
{
    public class TestCowTransation
    {
        private Dictionary<string, string> Config;
        public static string previousFac = "";
        public static string previousCam = "";

        public TestCowTransation()
        {
            Config = new Dictionary<string, string>(); ;
            if (System.IO.File.Exists(ProgramConfig.pyImageTestConfig))
            {
                StreamReader stream = new StreamReader(ProgramConfig.pyImageTestConfig);
                string linetext;
                while ((linetext = stream.ReadLine()) != null)
                {
                    string[] cont = linetext.Split(new char[1] { ':' }, 2);
                    Config.Add(cont[0], cont[1]);
                }
                stream.Close();
            }
            else
            {
                Config.Add("netloc", "100");
                Config.Add("videoloc", "");
                Config.Add("videotimes", "0");
                Config.Add("ffmpegloc", "");
                Config.Add("map", "");
                Config.Add("resultpicloc", "");
                Config.Add("temppicloc", "");
                Config.Add("stopprocess", "false");
                Config.Add("classifier", "");
            }
        }

        public void AutoSetLoc(string facname,string camera)
        {
            Config["netloc"] = ProgramConfig.pysave.Replace('/', '\\') + "\\" + facname + "\\" + facname + "-";
            Config["videoloc"] = ProgramConfig.VideoData.Replace('/', '\\') + "\\" + facname + "\\" + camera + "\\video.mp4";
            Config["ffmpegloc"] = ProgramConfig.pyFfmpegloc.Replace('/', '\\');
            Config["map"] = ProgramConfig.pymap.Replace('/', '\\') + "\\" + facname + ".txt";
            Config["resultpicloc"] = ProgramConfig.pyResultPicLoc.Replace('/', '\\');
            Config["temppicloc"] = ProgramConfig.pyTempPicLoc.Replace('/', '\\');
            Config["classifier"] = ProgramConfig.pyClassifier.Replace('/', '\\');
        }

        public void SetVideoTimes(int second)
        {
            Config["videotimes"] = second.ToString();
        }
        public void SetStop(bool flag)
        {
            if (flag == true)
            {
                Config["stopprocess"] = "true";
            }
            else
            {
                Config["stopprocess"] = "false";
            }
        }

        public void SaveConfig()
        {
            StreamWriter stream = new StreamWriter(ProgramConfig.pyImageTestConfig, false, System.Text.Encoding.UTF8);
            stream.WriteLine("netloc:" + Config["netloc"]);
            stream.WriteLine("videoloc:" + Config["videoloc"]);
            stream.WriteLine("videotimes:" + Config["videotimes"]);
            stream.WriteLine("ffmpegloc:" + Config["ffmpegloc"]);
            stream.WriteLine("map:" + Config["map"]);
            stream.WriteLine("resultpicloc:" + Config["resultpicloc"]);
            stream.WriteLine("temppicloc:" + Config["temppicloc"]);
            stream.WriteLine("stopprocess:" + Config["stopprocess"]);
            stream.WriteLine("classifier:" + Config["classifier"]);
            stream.Close();
        }

        public Dictionary<string, string> getContent()
        {
            return Config;
        }
    }
}