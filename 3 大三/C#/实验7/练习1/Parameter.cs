using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习1
{
    
    class Parameter
    {
        public static bool IsTextChange;
        public static Dictionary<string,string> form_file;
        public static Dictionary<string, bool> form_change;
        public static List<int> form_number;
        public static List<int> form_is_close;
        public static int find_position;
        public static List<string> file_name;
        public static Form1 this_form;
        public Parameter()
        {
            IsTextChange = false;
            form_file = new Dictionary<string, string>();
            form_change = new Dictionary<string, bool>();
            form_number = new List<int>();
            form_is_close = new List<int>();
            file_name = new List<string>();
            find_position = 0;
        }
    }
}
