using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 机器学习;
namespace SourceData
{
    static class SourceData
    {
        //框体信息
        public static string password = "9jAbO&KSvE@NrRX^2i^!9!wOGA%!YYT0";
        public static string load_picture_loaction = @"Data\INIT.data";
        public static MainForm MainForm;
        public static LeftToolTipNet LeftToolTipNet;
        public static RightAttribute RightAttribute;
        public static bool MouthDown;
        public static int MouseX;
        public static int MouseY;

        //Attribute中的属性,表示每个网络层最多连接多少个输入和输出
        public static int InitDataLinkIn = 1;
        public static int InitDataLinkOut = 3;

        //记录Attribute中每个函数的调用位置
        public static string Attribute_GetVariable_FunctionName = "tf.get_variable";
        public static string Attribute_Relu_FunctionName = "tf.get_variable";
        public static string Attribute_BiasAdd_FunctionName = "tf.nn.bias_add";


        //所有属性信息
        public static List<List<Object> > ObjectList;
    }
}
