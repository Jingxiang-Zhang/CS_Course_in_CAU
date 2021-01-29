using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace Filepack
{
    public enum FileCatagory
    {
        Picture = 1,
        Text,
        others,
        user1,
        user2,
        user3,
        user4
    };
    public class ImgTextTranformInfo
    {
        //表示图像或文本的名称
        List<string> imageAndTextList_name;
        //图像或文本的memory流对象
        List<MemoryStream> imageAndTextList_memory;
        //图像或文本的种类标签，枚举型：图片或文本
        List<FileCatagory> imageAndTextList_catagory;
        string[] filenameList;

        //这三个是单个传入
        string imageAndText_name;
        MemoryStream imageAndText_memory;
        FileCatagory imageAndText_catagory;
        //文本的保存位置
        string saveFileName;
        string password;
        byte[] fileBuffer;
        public ImgTextTranformInfo()
        {
            imageAndTextList_name = new List<string>();
            imageAndTextList_memory = new List<MemoryStream>();
            imageAndTextList_catagory = new List<FileCatagory>();
            password = "";
        }
        public byte[] FileBuffer
        {
            set { fileBuffer = value; }
            get { return fileBuffer; }
        }
        public FileMode FileMode
        {
            set { FileMode = value; }
            get { return FileMode; }
        }
        public string Password
        {
            set { password = value; }
            get { return password; }
        }
        public string FileName
        {
            set { saveFileName = value; }
            get { return saveFileName; }
        }
        public string[] FilenameList
        {
            set { filenameList = value; }
            get { return filenameList; }
        }
        public List<string> ImageAndTextList_name
        {
            set { imageAndTextList_name = value; }
            get { return imageAndTextList_name; }
        }
        public List<MemoryStream> ImageAndTextList_memory
        {
            set { imageAndTextList_memory = value; }
            get { return imageAndTextList_memory; }
        }
        public List<FileCatagory> ImageAndTextList_catagory
        {
            set { imageAndTextList_catagory = value; }
            get { return imageAndTextList_catagory; }
        }
        public string ImageAndText_name
        {
            set { imageAndText_name = value; }
            get { return imageAndText_name; }
        }
        public MemoryStream ImageAndText_memory
        {
            set { imageAndText_memory = value; }
            get { return imageAndText_memory; }
        }
        public FileCatagory ImageAndText_catagory
        {
            set { imageAndText_catagory = value; }
            get { return imageAndText_catagory; }
        }

    }
    public class ImgTextTranform
    {

        private static string[] PictureFormat = new string[] { "jpg", "jpeg", "png" };
        private static string[] TextFormat = new string[] { "txt", "c", "cpp" };
        public static void AddInfoToList(List<string> imageAndTextList_name,
            List<MemoryStream> imageAndTextList_memory,
            List<FileCatagory> imageAndTextList_catagory,
            ImgTextTranformInfo imgTextTranformInfo,
            bool is_list)
        {
            //函数的作用是将imgTextTranformInfo的分别信息加入到List中，不删除原信息
            //需要使用的信息为：ImageAndTextList_memory，ImageAndTextList_name，ImageAndTextList_catagory
            //或者ImageAndText_memory，ImageAndText_name，ImageAndText_catagory
            if (is_list)
            {
                int i = 0;
                for (i = 0; i < imgTextTranformInfo.ImageAndTextList_catagory.Count; i++)
                {
                    imageAndTextList_memory.Add(imgTextTranformInfo.ImageAndTextList_memory[i]);
                    imageAndTextList_name.Add(imgTextTranformInfo.ImageAndTextList_name[i]);
                    imageAndTextList_catagory.Add(imgTextTranformInfo.ImageAndTextList_catagory[i]);
                }
            }
            else
            {
                imageAndTextList_memory.Add(imgTextTranformInfo.ImageAndText_memory);
                imageAndTextList_name.Add(imgTextTranformInfo.ImageAndText_name);
                imageAndTextList_catagory.Add(imgTextTranformInfo.ImageAndText_catagory);
            }
        }
        public static void MemoryToByteFile(ImgTextTranformInfo imgTextTranformInfo)
        {
            //内存写入文件，增加写，需要自己创建文件，末尾不加结束标记
            //需要使用的信息为：ImageAndText_catagory，ImageAndText_memory，ImageAndText_name，FileName
            //定义种类空间
            byte[] temp_catagory = new byte[4];
            temp_catagory[0] = (byte)((int)imgTextTranformInfo.ImageAndText_catagory);
            //定义对象空间
            byte[] temp_imageOrText = imgTextTranformInfo.ImageAndText_memory.ToArray();
            int image_length = temp_imageOrText.Length;
            //定义名称空间
            byte[] temp_name = Encoding.UTF8.GetBytes(imgTextTranformInfo.ImageAndText_name);
            int name_length = temp_name.Length;

            //开辟总空间
            byte[] save_photoOrText = new byte[image_length + name_length + 12];

            //种类写入数据中
            Array.Copy(temp_catagory, 0, save_photoOrText, 0, temp_catagory.Length);

            //计算名字长度，并写入总数据中
            int temp_name_length = name_length;
            save_photoOrText[4] = (byte)temp_name_length;
            temp_name_length = temp_name_length >> 8;
            save_photoOrText[5] = (byte)temp_name_length;
            temp_name_length = temp_name_length >> 8;
            save_photoOrText[6] = (byte)temp_name_length;
            temp_name_length = temp_name_length >> 8;
            save_photoOrText[7] = (byte)temp_name_length;
            //名字写入数据
            Array.Copy(temp_name, 0, save_photoOrText, 8, temp_name.Length);

            //计算对象长度，写入数据
            int temp_image_length = image_length;
            name_length += 8;
            save_photoOrText[name_length] = (byte)temp_image_length;
            temp_image_length = temp_image_length >> 8;
            save_photoOrText[name_length + 1] = (byte)temp_image_length;
            temp_image_length = temp_image_length >> 8;
            save_photoOrText[name_length + 2] = (byte)temp_image_length;
            temp_image_length = temp_image_length >> 8;
            save_photoOrText[name_length + 3] = (byte)temp_image_length;
            //对象写入数据
            Array.Copy(temp_imageOrText, 0, save_photoOrText, name_length + 4, temp_imageOrText.Length);

            //总数居写入data文件
            FileStream file = new FileStream(imgTextTranformInfo.FileName, FileMode.Append, FileAccess.Write);
            file.Write(save_photoOrText, 0, save_photoOrText.Length);
            file.Close();
        }
        public static void FinalToByteFile(ImgTextTranformInfo imgTextTranformInfo)
        {
            //此函数的作用是加入结尾标识符，务必在data文件最后一步调用
            //需要使用的信息为：FileName
            FileStream file = new FileStream(imgTextTranformInfo.FileName, FileMode.Append, FileAccess.Write);
            byte[] end_flag = new byte[4];
            file.Write(end_flag, 0, end_flag.Length);
            file.Close();
        }
        public static void DefinalToByteFile(ImgTextTranformInfo imgTextTranformInfo)
        {
            // 此函数的作用是去掉结尾标识符，结尾务必有标识符，否则会错误删除
            //需要使用的信息为：FileName
            FileStream file = new FileStream(imgTextTranformInfo.FileName, FileMode.Open, FileAccess.Read);
            byte[] end_flag = new byte[file.Length - 4];
            file.Read(end_flag, 0, (int)file.Length - 4);
            file.Close();
            file = new FileStream(imgTextTranformInfo.FileName, FileMode.Open, FileAccess.Write);
            file.Write(end_flag, 0, end_flag.Length);
            file.Close();
           
        }
        public static void MemoryListToByteFile(ImgTextTranformInfo imgTextTranformInfo)
        {
            /*
            此函数的作用是将传入的memory数组（包含图片或文本的信息）写入到一个文件中
            其中imgTextTranformInfo必须包含的参数为：
            1. imageAndText_memory 图片或文本的memory数组
            2. imageAndText_name 每一个对象的名字
            3. imageAndText_catagory 每个对象的种类
            4. saveFileName 需要保存的位置
            写入文件的舒徐为：
            1. 文件的类别，一个int型
            2. 文件的名字，先写入一个int表示名字的长度，再写入名字
            3. 文件的信息，先写入一个int表示长度，再写入文件信息
            注意：该方法为创建写、覆盖写，无需调用FinalToByteFile函数
            需要使用的信息为：ImageAndTextList_name，ImageAndTextList_memory，ImageAndTextList_catagory
            FileName
            */
            if (!(imgTextTranformInfo.ImageAndTextList_name.Count== imgTextTranformInfo.ImageAndTextList_memory.Count
                && imgTextTranformInfo.ImageAndTextList_memory.Count== imgTextTranformInfo.ImageAndTextList_catagory.Count))
            {
                throw new Exception("ImgTextTranformInfo中数组长度不相等");
            }
            FileStream file = new FileStream(imgTextTranformInfo.FileName, FileMode.Create, FileAccess.Write);
            file.Close();
            int i = 0;
            foreach (MemoryStream memory in imgTextTranformInfo.ImageAndTextList_memory)
            {

                ImgTextTranformInfo new_ImgTextTranformInfo = new ImgTextTranformInfo();
                new_ImgTextTranformInfo.ImageAndText_catagory = imgTextTranformInfo.ImageAndTextList_catagory[i];
                new_ImgTextTranformInfo.ImageAndText_name = imgTextTranformInfo.ImageAndTextList_name[i];
                new_ImgTextTranformInfo.ImageAndText_memory = imgTextTranformInfo.ImageAndTextList_memory[i];
                new_ImgTextTranformInfo.FileName = imgTextTranformInfo.FileName;
                MemoryToByteFile(new_ImgTextTranformInfo);
                i++;
            }
            //加入结尾标识
            FinalToByteFile(imgTextTranformInfo);
            CodeDataFile(imgTextTranformInfo);
        }
        public static void ByteFileToMemoryList(ImgTextTranformInfo imgTextTranformInfo)
        {
            //该函数可以将data文件转化为三个list
            //提供：imgTextTranformInfo中的FileBuffer
            try
            {
                MemoryStream memoryStream = new MemoryStream(imgTextTranformInfo.FileBuffer);
                BinaryReader br = new BinaryReader(memoryStream);
                while (true)
                {
                    //读出的第1个值为类型
                    int i = br.ReadInt32();
                    if (i == 0) break;
                    imgTextTranformInfo.ImageAndTextList_catagory.Add((FileCatagory)i);

                    //读出的第2个值为文件名长度
                    i = br.ReadInt32();
                    byte[] temp_name = new byte[i];
                    //读出的第3个值为名字
                    temp_name = br.ReadBytes(i);
                    string ItemName = Encoding.UTF8.GetString(temp_name);
                    imgTextTranformInfo.ImageAndTextList_name.Add(Encoding.UTF8.GetString(temp_name));

                    //读出的第四个值为数据大小
                    i = br.ReadInt32();
                    byte[] temp_image = new byte[i];
                    //读出的第5个值为数据
                    temp_image = br.ReadBytes(i);
                    MemoryStream stream = new MemoryStream(temp_image);
                    imgTextTranformInfo.ImageAndTextList_memory.Add(stream);
                }
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }
        private static void LoadToList(ImgTextTranformInfo imgTextTranformInfo, 
                                string filename, FileCatagory catagory)
        {
            /*
             * 该函数将单个filename文件的信息读取到imgTextTranformInfo中，
             * 可以分为图片，txt和其他三种格式
             * 需要提供filename，FileCatagory
             */
            try
            {
                if (catagory==FileCatagory.Picture)
                {
                    FileStream file = new FileStream(filename, FileMode.Open, FileAccess.Read);
                    byte[] buffer = new byte[file.Length];
                    file.Read(buffer, 0, buffer.Length);
                    MemoryStream stream = new MemoryStream(buffer);

                    imgTextTranformInfo.ImageAndTextList_memory.Add(stream);
                    imgTextTranformInfo.ImageAndTextList_name.Add(filename.Substring(filename.LastIndexOf("\\") + 1));
                    imgTextTranformInfo.ImageAndTextList_catagory.Add(FileCatagory.Picture);
                    //添加图像
                    file.Close();
                }
                else if(catagory==FileCatagory.Text)
                {
                    FileStream file = new FileStream(filename, FileMode.Open, FileAccess.Read);
                    Encoding r = ImgTextTranform.GetFileEncodeType(filename);
                    byte[] filebyte = new byte[file.Length];
                    file.Read(filebyte, 0, filebyte.Length);
                    file.Close();

                    string temp_string = r.GetString(filebyte);
                    filebyte = Encoding.UTF8.GetBytes(temp_string);
                    MemoryStream stream = new MemoryStream(filebyte);
                    imgTextTranformInfo.ImageAndTextList_memory.Add(stream);
                    imgTextTranformInfo.ImageAndTextList_name.Add(filename.Substring(filename.LastIndexOf("\\") + 1));
                    imgTextTranformInfo.ImageAndTextList_catagory.Add(FileCatagory.Text);
                }
                else if (catagory == FileCatagory.others)
                {
                    FileStream file = new FileStream(filename, FileMode.Open, FileAccess.Read);
                    byte[] buffer = new byte[file.Length];
                    file.Read(buffer, 0, buffer.Length);
                    MemoryStream stream = new MemoryStream(buffer);

                    imgTextTranformInfo.ImageAndTextList_memory.Add(stream);
                    imgTextTranformInfo.ImageAndTextList_name.Add(filename.Substring(filename.LastIndexOf("\\") + 1));
                    imgTextTranformInfo.ImageAndTextList_catagory.Add(FileCatagory.others);
                    file.Close();
                }
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        

        public static void FilenameListToMemoryList(ImgTextTranformInfo imgTextTranformInfo)
        {
            /*
             * 该函数用于从一个列表的文件路径中加载所有的图片，txt以及data数据到内存流中
             * 不能为文件夹
             * 需要提供：FilenameList
             * data文件只能作为单独的参数传入，若传入data，需要提供密码
             */
            bool has_directory = false;
            bool not_valid = false;
            bool not_file_size_valid = false;
            bool has_data_file = false;
            foreach (string fileName in imgTextTranformInfo.FilenameList)
            {
                if (Directory.Exists(fileName))
                {
                    has_directory = true;
                }
                else if (File.Exists(fileName))
                {
                    long size = new FileInfo(fileName).Length;
                    if (size >= 1932735283)
                    {
                        not_file_size_valid = true;
                        continue;
                    }
                }
                else
                {
                    not_valid = true; 
                }
                
                string expanded_name = fileName.Substring(fileName.LastIndexOf(".") + 1);
                bool success = false;
                foreach (string str in PictureFormat)
                {
                    if (expanded_name == str)
                    {
                        LoadToList(imgTextTranformInfo, fileName, FileCatagory.Picture);
                        success = true;
                        break;
                    }
                }
                if (success) continue;
                foreach (string str in TextFormat)
                {
                    if (expanded_name == str)
                    {
                        LoadToList(imgTextTranformInfo, fileName, FileCatagory.Text);
                        success = true;
                        break;
                    }
                }
                if (success) continue;
                if (expanded_name != "data")
                {
                    LoadToList(imgTextTranformInfo, fileName, FileCatagory.others);
                    success = true;
                }
                if (success) continue;
                if (imgTextTranformInfo.FilenameList.Length > 1)
                {
                    has_data_file = true;
                    continue;
                }
                try
                {
                    ImgTextTranformInfo imgTextTranformInfo2 = new ImgTextTranformInfo();
                    imgTextTranformInfo2.FileName = fileName;
                    imgTextTranformInfo2.Password = imgTextTranformInfo.Password;
                    DecodeDataFile(imgTextTranformInfo2);

                    ImgTextTranform.ByteFileToMemoryList(imgTextTranformInfo2);

                    for (int i = 0; i < imgTextTranformInfo2.ImageAndTextList_catagory.Count; i++)
                    {
                        imgTextTranformInfo.ImageAndTextList_memory.Add(imgTextTranformInfo2.ImageAndTextList_memory[i]);
                        imgTextTranformInfo.ImageAndTextList_name.Add(imgTextTranformInfo2.ImageAndTextList_name[i]);
                        imgTextTranformInfo.ImageAndTextList_catagory.Add(imgTextTranformInfo2.ImageAndTextList_catagory[i]);
                    }
                }
                catch (Exception ex)
                {
                    throw ex;
                }
            }
            if (not_valid) throw new Exception("路径无效！");
            if (has_directory) throw new Exception("不能包含文件夹！");
            if (not_file_size_valid) throw new Exception("单文件不能超过1.8Gb");
            if (has_data_file) throw new Exception("data文件需要单独导入");
        }
        public static Encoding GetFileEncodeType(string filename)
        {
            //改函数用于获取txt文件的格式编码
            //需要提供文件路径
            FileStream fs = new FileStream(filename, FileMode.Open, FileAccess.Read);
            BinaryReader br = new BinaryReader(fs);
            Byte[] buffer = br.ReadBytes(2);
            fs.Close();
            return GetFileEncodeType(buffer);
        }
        public static Encoding GetFileEncodeType(MemoryStream memoryStream)
        {
            //改函数用于获取txt文件的格式编码
            //需要提供memoryStream对象
            Byte[] buffer = new Byte[2];
            memoryStream.Write(buffer, 0, 2);
            return GetFileEncodeType(buffer);

        }
        public static Encoding GetFileEncodeType(byte [] buffer)
        {
            //改函数用于获取txt文件的格式编码
            //需要提供文件的buffer
            if (buffer[0] >= 0xEF)
            {
                if (buffer[0] == 0xEF && buffer[1] == 0xBB)
                {
                    return Encoding.UTF8;
                }
                else if (buffer[0] == 0xFE && buffer[1] == 0xFF)
                {
                    return Encoding.BigEndianUnicode;
                }
                else if (buffer[0] == 0xFF && buffer[1] == 0xFE)
                {
                    return Encoding.Unicode;
                }
                else
                {
                    return Encoding.Default;
                }
            }
            else
            {
                return Encoding.Default;
            }
        }
        public static void UnpackDataFile(ImgTextTranformInfo imgTextTranformInfo)
        {
            //解包文件，需要提供imgTextTranformInfo中的
            //passWord,FileName
            DecodeDataFile(imgTextTranformInfo);
            try
            {
                ByteFileToMemoryList(imgTextTranformInfo);
            }
            catch(Exception ex)
            {
                throw ex;
            }
            string filename = imgTextTranformInfo.FileName;
            string location = filename.Substring(0, filename.LastIndexOf("."));
            int i = 1;
            if (!Directory.Exists(location))
            {
                Directory.CreateDirectory(location);
            }
            else
            {
                while (true)
                {
                    if (Directory.Exists(location + "(" + i.ToString() + ")")) i++;
                    else break;
                }
                location = location + "(" + i.ToString() + ")";
                Directory.CreateDirectory(location);
            }
            location = location + @"\";
            for (i = 0; i < imgTextTranformInfo.ImageAndTextList_catagory.Count; i++)
            {
                string new_location = location + imgTextTranformInfo.ImageAndTextList_name[i];
                FileStream file = new FileStream(new_location, FileMode.Create, FileAccess.Write);
                byte[] buffer = new byte[imgTextTranformInfo.ImageAndTextList_memory[i].Length];
                imgTextTranformInfo.ImageAndTextList_memory[i].Read(buffer, 0, buffer.Length);
                file.Write(buffer, 0, buffer.Length);
                file.Close();
            }
        }
        public static void CodeDataFile(ImgTextTranformInfo imgTextTranformInfo)
        {
            //将文件编码，需提供的是FileName，Password
            string filename = imgTextTranformInfo.FileName;
            string password = imgTextTranformInfo.Password;
            FileStream file = new FileStream(filename, FileMode.Open, FileAccess.Read);

            byte[] keyArray = TransformPWD(password);
            byte[] buffer = new byte[file.Length];
            file.Read(buffer, 0, buffer.Length);
            file.Close();

            RijndaelManaged rDel = new RijndaelManaged();
            rDel.Key = keyArray;
            rDel.Mode = CipherMode.ECB;
            rDel.Padding = PaddingMode.PKCS7;
            ICryptoTransform cTransform = rDel.CreateEncryptor();
            byte[] resultArray = cTransform.TransformFinalBlock(buffer, 0, buffer.Length);

            file = new FileStream(filename, FileMode.Open, FileAccess.Write);
            file.Write(resultArray, 0, resultArray.Length);
            file.Close();
        }
        public static void DecodeDataFile(ImgTextTranformInfo imgTextTranformInfo)
        {
            //将文件解码，需要提供的是：FileName，Password，
            //返回的是imgTextTranformInfo中的FileBuffer
            string filename = imgTextTranformInfo.FileName;
            FileStream file = new FileStream(filename, FileMode.Open, FileAccess.Read);

            byte[] buffer = new byte[file.Length];
            file.Read(buffer, 0, buffer.Length);
            file.Close();

            string key = imgTextTranformInfo.Password;
            byte[] keyArray = TransformPWD(key);
            RijndaelManaged rDel = new RijndaelManaged();
            rDel.Key = keyArray;
            rDel.Mode = CipherMode.ECB;
            rDel.Padding = PaddingMode.PKCS7;

            ICryptoTransform cTransform = rDel.CreateDecryptor();
            imgTextTranformInfo.FileBuffer = cTransform.TransformFinalBlock(buffer, 0, buffer.Length);
        }
        private static byte[] TransformPWD(string pwd)
        {
            //将密码转化为32位，因为编码需要的是32位
            byte[] bt = new byte[32];
            int length = Math.Min(pwd.Length, 32);
            for (int i = 0; i < length; i++)
            {
                bt[i] = (byte)pwd[i];
            }
            return bt;
        }

        
        public static void SingleFileToMemoryList(ImgTextTranformInfo imgTextTranformInfo)
        {
            //推荐使用
            /*
             * 该函数用于从data文件把数据读入到imgTextTranformInfo对象的内存流
             * 不能为文件夹
             * 需要提供：Filename,Password
             */
            try
            {
                DecodeDataFile(imgTextTranformInfo);
                ByteFileToMemoryList(imgTextTranformInfo);
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }
    }
}
