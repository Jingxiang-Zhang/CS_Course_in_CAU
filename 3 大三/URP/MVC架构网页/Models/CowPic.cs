using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace CowCow.Models
{
    public class CowPic
    {
        public string name { get; set; } //表示当前操作养牛场的名称
        public static string information { get; set; } //表示当前操作的养牛场的介绍信息，只能读一行
        public static int picnumber { get; set; }  //当前养牛场中奶牛分组的个数
        public static string currentname { get; set; }  //表示当前操作养牛场的名称
        public static string[] picloction { get; set; }//表示当前操作养牛场中分组的各个组的标题图片
        public static string[] cowNum { get; set; } //表示当前操作养牛场中分组的各个组的标题名称
        public static int[] cowSortCount{ get; set; }  //表示当前操作养牛场中分组的各个组的个数（与上面两个个一起使用）
        public static bool firsttimeLoad = true;  //是否为第一次加载养牛场信息（是否第一次进入界面）
        public static string currentCowFactoryLoc { get; set; }//记录当前奶牛场的相对位置
        public static string[] cowBunchPicLoc{ get; set; }//表示当前操作的奶牛组的每个图片的相对位置
        public static string[] cowBunchPicName { get; set; }//表示当前操作的奶牛组的每个图片名称
        public static int cowBunchPicNum { get; set; }  //表示当前操作的奶牛组的图片个数
        public static string cowSortName{ get; set; }  //表示当前操作的奶牛组的名称
        public static string currentFullFacSortName { get; set; }//表示当前操作的奶牛组的绝对位置



    }
}