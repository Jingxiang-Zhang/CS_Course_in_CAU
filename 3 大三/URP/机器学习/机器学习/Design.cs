using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace PyAttribute
{

    /*
     * 属性添加说明：
     * 此空间下的类用作表示层次结构中各个组件的属性和函数，他们的关系如下：
     *      属性类：
     *          类Design，包含可视化界面的一系列基本属性
     *          类NetLayer，包含作为网络关系中的输入和输出节点个数的属性
     *          每个属性要继承PyAttribute类
     *      函数类设计说明：
     *          1.各个函数均需要继承PyFunction，每个函数中如果需要使用属性类，则要实例化一个属性类，并且把
     *          这个属性加入到函数的Attribute列表中，如果使用的属性类为非必须属性，比如Design，则可以在
     *          函数类实例化的时候动态添加。
     *          2.每一个函数都需要将其所有的希望能够在设计化界面显示出来的变量值加入到Attribute列表中
     *          3.每个需要实现的在Python的函数（以test函数举例）,需要包含一个FunctionImformation类成员，
     *          此静态类包含该函数的：
     *                  1).函数使用名称，string类型（如："test.showtest"）
     *                  2).调用该函数需要引用的库函数
     *                  3).生成Python代码时候的代码注释
     *          4.定义枚举类型要放在类的前面
     */

    abstract class PyAttribute
    {
        private List<object> variableList;
        public PyAttribute()
        {
            VariableList = new List<object>();
        }

        public List<object> VariableList { get => variableList; set => variableList = value; }
    }

    abstract class PyFunction
    {
        /*
         * 每一个函数均需要添加这个属性类，用于表示py函数的使用方法
         */
         /*
        private string functionName;    //调用函数的名称：例如：tf.nn.cond
        private string functionImport;  //例如tensorflow
        private string functionExplain; //函数解释
        private string showName;        //组名称*/
        private List<object> variableList;
        private List<PyAttribute> attributeList;

        public PyFunction()
        {
            VariableList = new List<object>();
            AttributeList = new List<PyAttribute>();
        }

        public List<object> VariableList { get => variableList; set => variableList = value; }
        public List<PyAttribute> AttributeList { get => attributeList; set => attributeList = value; }
    }
    class Design:PyAttribute
    {
        /* 
         * 此类为可视化界面的属性类
         * 包含的属性包括初始化的位置，最大和最小的大小，尺寸
         * 是否可用
         * 名称
         * 背景颜色，背景图片，文字字体，文字文本
         * 以及包括所有以上这些信息的列表
         * 其中，每次继承这个类，都需要扩充本基类的attributeGroup
         */
        //布局
        private Point location;
        private Point maximumSize;
        private Point minimumSize;
        private Point size;
        //行为
        private bool enable;
        //设计
        private string name;
        //外观
        private Color backColor;
        private Image backGroundImage;
        private Font font;
        private string text;

        public Design(string name = "Attribute",
            bool enable = true,
            string text = "Attribute")
        {
            this.Name = name;
            this.Enable = enable;
            this.Text = text;
            base.VariableList.Add(Location);
            base.VariableList.Add(MaximumSize);

            base.VariableList.Add(MinimumSize);
            base.VariableList.Add(Size);
            base.VariableList.Add(enable);
            base.VariableList.Add(name);
            base.VariableList.Add(BackColor);
            base.VariableList.Add(BackGroundImage);
            base.VariableList.Add(Font);
            base.VariableList.Add(text);
        }
        public Point Location { get => location; set => location = value; }
        public Point MaximumSize { get => maximumSize; set => maximumSize = value; }
        public Point MinimumSize { get => minimumSize; set => minimumSize = value; }
        public Point Size { get => size; set => size = value; }
        public bool Enable { get => enable; set => enable = value; }
        public string Name { get => name; set => name = value; }
        public Color BackColor { get => backColor; set => backColor = value; }
        public Image BackGroundImage { get => backGroundImage; set => backGroundImage = value; }
        public Font Font { get => font; set => font = value; }
        public string Text { get => text; set => text = value; }       
    }

    class NetLayer:PyAttribute
    {
        /*
         * 数据的传输层，此类继承了attribute的数据，并且为所有的和数据操作相关的函数
         * 提供中间的继承层次，包括了：
         *     数据的流入，数据的流出，步伐，步伐的每个分量，层次的名称
         * 其中：
         *     data_In和data_Out表示该变量有几个数据输入和数据输出
         *     IsLayer表示是否为层次化的一部分，即：是否需要作为本程序的一个可视化组件显示
         *            屏幕上，如果为false，则不会调用基类的构造函数
         */
        private Design[] data_In;
        private Design[] data_Out;
        private string layerName;

        public NetLayer(int data_In, int data_Out)
        {
            this.Data_In = new Design[data_In];
            this.Data_Out = new Design[data_Out];

            base.VariableList.Add(this.Data_In);
            base.VariableList.Add(this.Data_Out);
            base.VariableList.Add(this.LayerName);

        }

        public string LayerName { get => layerName; set => layerName = value; }
        internal Design[] Data_In { get => data_In; set => data_In = value; }
        internal Design[] Data_Out { get => data_Out; set => data_Out = value; }
    }

    enum VariableInitializer
    {
        xavier_initializer
    }
    sealed class GetVariable:PyFunction
    {
        /*
         * 来自tf.get_variable
         * 变量类，包含变量名称，变量的大小，
         * 初始化器，默认为xavier_initializer
         * 是否为可训练，默认为可以
         */
        private string variableName;
        private VariableInitializer initializer;
        private bool trainable;
        private int[] shape;
        
        public GetVariable(bool IsLayer,
            string name,
            int[] shape,
            VariableInitializer initializer = VariableInitializer.xavier_initializer,
            bool trainable = true)
        { 
            this.variableName = name;
            this.initializer = initializer;
            this.trainable = trainable; 
            this.shape = shape;

            base.VariableList.Add(this.variableName);
            base.VariableList.Add(this.initializer);
            base.VariableList.Add(this.trainable);
            base.VariableList.Add(this.shape);
            base.Name = "GetVariable";
            base.Text = "GetVariable";
        }
        public string VariableName { get => variableName; set => variableName = value; }
        public bool Trainable { get => trainable; set => trainable = value; }
        public int[] Shape { get => shape; set => shape = value; }
        public VariableInitializer Initializer { get => initializer; set => initializer = value; }
    }
    static class ReluS
    {
        private static string functionLocation = SourceData.Attribute_Relu_FunctionName;
        public static string FunctionLocation { get => functionLocation; set => functionLocation = value; }

    }
    sealed class Relu:NetLayer
    {
        /*
         * 机器学习中的Relu函数，来自tf.nn.relu
         * 包括：
         * Relu函数的名称
         */
        private string reluName;
        public Relu(bool IsLayer, string name) : base(1, 1, IsLayer)
        {
            if (IsLayer == false)
            {
                return;
            }
            this.reluName = name;
            base.Group.Add(this.reluName);
            base.Name = "Relu";
            base.Text = "Relu";
        }
        public string ReluName { get => reluName; set => reluName = value; }
    }

    static class BiasAddS
    {
        private static string functionLocation = SourceData.Attribute_BiasAdd_FunctionName;
        public static string FunctionLocation { get => functionLocation; set => functionLocation = value; }

    }
    sealed class BiasAdd:NetLayer
    {
        /*
         * 机器学习中的bias_add函数，来自tf.nn.bias_add
         * 包括：
         * 名称，两个输入变量
         */
        private string biasAddName;
        public BiasAdd(bool IsLayer,string name) : base(2, 1, IsLayer)
        {
            if (IsLayer == false)
            {
                this.biasAddName = name;
                base.Group.Add(this.biasAddName);
                base.Name = "BiasAdd";
                base.Text = "BiasAdd";
            }
        }
        public string BiasAddName { get => biasAddName; set => biasAddName = value; }
    }

    enum Padding
    {
        SAME
    }
    enum PoolMode
    {
        max_pool,
        avg_pool
    }

    class Pool : NetLayer
    {
        private string PoolName;
        private string kernel;
        private string stride;
        private Padding padding;
        private PoolMode poolMode;

        public Pool(bool IsLayer,
            string name,
            string kernel = "1,2,2,1",
            string stride = "1,2,2,1",
            Padding padding= Padding.SAME,
            PoolMode poolMode = PoolMode.max_pool
            ) : base(1, 1, IsLayer)
        {
            if (IsLayer == false)
            {
                this.PoolName1 = name;
                this.Kernel = kernel;
                this.Stride5 = stride;
                this.Padding = padding;                
                this.PoolMode = PoolMode.max_pool;

                base.Group.Add(this.PoolName1);
                base.Group.Add(this.Kernel);
                base.Group.Add(this.Stride5);
                base.Group.Add(this.Padding);
                base.Group.Add(this.PoolMode);
                base.Name = "Pool";
                base.Text = "Pool";
            }
           
        }

        public string PoolName1 { get => PoolName; set => PoolName = value; }
        public string Kernel { get => kernel; set => kernel = value; }
        public string Stride5 { get => stride; set => stride = value; }
        public Padding Padding { get => padding; set => padding = value; }
        public PoolMode PoolMode { get => poolMode; set => poolMode = value; }
    }
    class Conv2d:NetLayer
    {
        private string conv2dName;

        public Conv2d() { }
        public Conv2d(bool InitAttribute) : base(InitAttribute) { }
        public string Conv2dName { get => conv2dName; set => conv2dName = value; }
    }
    class Conv : NetLayer
    {
        private int inChannels;
        private int outChannels;
        private GetVariable variableX;
        private GetVariable variableY;
        private Relu relu;
        private BiasAdd biasAdd;
        private Conv2d conv2D;
        private string netLayerName;

        public Conv():base(true)
        {
            variableX = new GetVariable(true);
            variableY = new GetVariable(true);
            relu = new Relu();
            biasAdd = new BiasAdd();
            conv2D = new Conv2d();
        }
        public int InChannels { get => inChannels; set => inChannels = value; }
        public int OutChannels { get => outChannels; set => outChannels = value; }
        public GetVariable VariableX { get => variableX; set => variableX = value; }
        public GetVariable VariableY { get => variableY; set => variableY = value; }
        public Relu Relu { get => relu; set => relu = value; }
        public BiasAdd BiasAdd { get => biasAdd; set => biasAdd = value; }
        public Conv2d Conv2D { get => conv2D; set => conv2D = value; }
        public string NetLayerName { get => netLayerName; set => netLayerName = value; }
    }


    
}
