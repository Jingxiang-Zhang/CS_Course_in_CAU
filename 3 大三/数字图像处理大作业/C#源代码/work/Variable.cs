using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace work
{
    class Variable
    {
        public struct Image_list
        {
            public Image_form img_form;
            public Bitmap pic;
        }
        public static int now_count = 1;

        public static List<Image_list> image_form_list = new List<Image_list>();

        public static Image_form last_time_act = null;

        public static string python_loc = "";

        public static bool confirm = false;
        public static double linear_change_contrast = 1;
        public static int linear_change_range = 0;
        public static bool linear_change_gray = true;

        public static double gamma = 1;
        public static bool gamma_gray = true;

        public static double add_rate = 0.5;

        public static int cornel = 3;
        public static bool avg_filt = true;

        public static double face_scale = 1.1   ;

    }
}
