using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;
namespace CowCow.Models
{
    public class LearnStateTread
    {
       

        private Dictionary<string, string> Config;
        public LearnStateTread()
        {
            Config = new Dictionary<string, string>(); ;
            if (System.IO.File.Exists(ProgramConfig.pyconfig))
            {
                StreamReader stream = new StreamReader(ProgramConfig.pyconfig);
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
                Config.Add("traintimes","100");
                Config.Add("nowtimes", "0");
                Config.Add("stop", "false");
                Config.Add("newtrain", "true");
                Config.Add("piclocation", "");
                Config.Add("resultloc", "");
                Config.Add("saveloc", "");
                Config.Add("maploc", "");
                Config.Add("tarinlogloc", "");
                Config.Add("errorlogloc", "");
            }
        }

        public void AutoSetLoc(string name)
        {
            Config["piclocation"] = ProgramConfig.pictureloc.Replace('/', '\\') + "\\" + name;
            Config["resultloc"] = ProgramConfig.pyresult.Replace('/', '\\') + "\\" + name+".txt";           
            Config["maploc"] = ProgramConfig.pymap.Replace('/', '\\') + "\\" + name + ".txt";
            Config["saveloc"] = ProgramConfig.pysave.Replace('/', '\\') + "\\" + name;
            if (!Directory.Exists(Config["saveloc"]))
                Directory.CreateDirectory(Config["saveloc"]);
            Config["saveloc"] = Config["saveloc"] + "\\" + name + "-";
            Config["tarinlogloc"] = ProgramConfig.pytrainlog.Replace('/', '\\');
            Config["errorlogloc"] = ProgramConfig.pyerrorlog.Replace('/', '\\');
        }

        public void SetNewTrain(bool flag)
        {
            if (flag == true)
            {
                Config["newtrain"] = "true";
            }
            else
            {
                Config["newtrain"] = "false";
            }
        }
        public void SetStop(bool flag)
        {
            if (flag == true)
            {
                Config["stop"] = "true";
            }
            else
            {
                Config["stop"] = "false";
            }
        }

        public void SetNowTimes(int nowtimes)
        {
            Config["nowtimes"] = nowtimes.ToString();
        }

        public void SetTrainTimes(int traintimes)
        {
            Config["traintimes"] = traintimes.ToString();
        }

        public void SaveConfig()
        {
            StreamWriter stream = new StreamWriter(ProgramConfig.pyconfig, false, System.Text.Encoding.UTF8);
            stream.WriteLine("traintimes:"+ Config["traintimes"]);
            stream.WriteLine("nowtimes:" + Config["nowtimes"]);
            stream.WriteLine("stop:" + Config["stop"]);
            stream.WriteLine("newtrain:" + Config["newtrain"]);
            stream.WriteLine("piclocation:" + Config["piclocation"]);
            stream.WriteLine("resultloc:" + Config["resultloc"]);
            stream.WriteLine("saveloc:" + Config["saveloc"]);
            stream.WriteLine("maploc:" + Config["maploc"]);
            stream.WriteLine("tarinlogloc:" + Config["tarinlogloc"]);
            stream.WriteLine("errorlogloc:" + Config["errorlogloc"]);
            stream.Close();
        }

        public Dictionary<string, string> getContent()
        {
            return Config;
        }

        
    }
}