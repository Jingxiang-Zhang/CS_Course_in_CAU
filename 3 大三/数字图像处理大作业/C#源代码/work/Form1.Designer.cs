namespace work
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.文件ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.打开OToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.退出ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.编辑ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.复制ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.粘贴ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.工具ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.设置python路径ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.对比度CToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.灰度化GToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.n值化VToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.线性变换LToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.伽马调整GToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.直方图HToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.图像相加AToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.图像滤波FToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.图像锐化ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.人脸检测ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.帮助ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.作者介绍ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.灰度ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rGB直方图CToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.文件ToolStripMenuItem,
            this.编辑ToolStripMenuItem,
            this.工具ToolStripMenuItem,
            this.帮助ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1190, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 文件ToolStripMenuItem
            // 
            this.文件ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.打开OToolStripMenuItem,
            this.保存ToolStripMenuItem,
            this.toolStripSeparator1,
            this.退出ToolStripMenuItem});
            this.文件ToolStripMenuItem.Name = "文件ToolStripMenuItem";
            this.文件ToolStripMenuItem.Size = new System.Drawing.Size(71, 24);
            this.文件ToolStripMenuItem.Text = "文件(&F)";
            // 
            // 打开OToolStripMenuItem
            // 
            this.打开OToolStripMenuItem.Name = "打开OToolStripMenuItem";
            this.打开OToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.打开OToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.打开OToolStripMenuItem.Text = "打开(&O)";
            this.打开OToolStripMenuItem.Click += new System.EventHandler(this.打开OToolStripMenuItem_Click);
            // 
            // 保存ToolStripMenuItem
            // 
            this.保存ToolStripMenuItem.Name = "保存ToolStripMenuItem";
            this.保存ToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.保存ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.保存ToolStripMenuItem.Text = "保存(&S)";
            this.保存ToolStripMenuItem.Click += new System.EventHandler(this.保存ToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(221, 6);
            // 
            // 退出ToolStripMenuItem
            // 
            this.退出ToolStripMenuItem.Name = "退出ToolStripMenuItem";
            this.退出ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.退出ToolStripMenuItem.Text = "退出(&Q)";
            this.退出ToolStripMenuItem.Click += new System.EventHandler(this.退出ToolStripMenuItem_Click);
            // 
            // 编辑ToolStripMenuItem
            // 
            this.编辑ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.复制ToolStripMenuItem,
            this.粘贴ToolStripMenuItem});
            this.编辑ToolStripMenuItem.Name = "编辑ToolStripMenuItem";
            this.编辑ToolStripMenuItem.Size = new System.Drawing.Size(71, 24);
            this.编辑ToolStripMenuItem.Text = "编辑(E)";
            // 
            // 复制ToolStripMenuItem
            // 
            this.复制ToolStripMenuItem.Name = "复制ToolStripMenuItem";
            this.复制ToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C)));
            this.复制ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.复制ToolStripMenuItem.Text = "复制(&C)";
            this.复制ToolStripMenuItem.Click += new System.EventHandler(this.复制ToolStripMenuItem_Click);
            // 
            // 粘贴ToolStripMenuItem
            // 
            this.粘贴ToolStripMenuItem.Name = "粘贴ToolStripMenuItem";
            this.粘贴ToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
            this.粘贴ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.粘贴ToolStripMenuItem.Text = "粘贴(&P)";
            this.粘贴ToolStripMenuItem.Click += new System.EventHandler(this.粘贴ToolStripMenuItem_Click);
            // 
            // 工具ToolStripMenuItem
            // 
            this.工具ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.设置python路径ToolStripMenuItem,
            this.toolStripSeparator2,
            this.对比度CToolStripMenuItem,
            this.直方图HToolStripMenuItem,
            this.图像相加AToolStripMenuItem,
            this.图像滤波FToolStripMenuItem,
            this.图像锐化ToolStripMenuItem,
            this.人脸检测ToolStripMenuItem});
            this.工具ToolStripMenuItem.Name = "工具ToolStripMenuItem";
            this.工具ToolStripMenuItem.Size = new System.Drawing.Size(72, 24);
            this.工具ToolStripMenuItem.Text = "工具(T)";
            // 
            // 设置python路径ToolStripMenuItem
            // 
            this.设置python路径ToolStripMenuItem.Name = "设置python路径ToolStripMenuItem";
            this.设置python路径ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.设置python路径ToolStripMenuItem.Text = "设置python路径";
            this.设置python路径ToolStripMenuItem.Click += new System.EventHandler(this.设置python路径ToolStripMenuItem_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(221, 6);
            // 
            // 对比度CToolStripMenuItem
            // 
            this.对比度CToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.灰度化GToolStripMenuItem,
            this.n值化VToolStripMenuItem,
            this.线性变换LToolStripMenuItem,
            this.伽马调整GToolStripMenuItem});
            this.对比度CToolStripMenuItem.Name = "对比度CToolStripMenuItem";
            this.对比度CToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.对比度CToolStripMenuItem.Text = "对比度(&C)";
            // 
            // 灰度化GToolStripMenuItem
            // 
            this.灰度化GToolStripMenuItem.Name = "灰度化GToolStripMenuItem";
            this.灰度化GToolStripMenuItem.Size = new System.Drawing.Size(173, 26);
            this.灰度化GToolStripMenuItem.Text = "灰度化(G)";
            this.灰度化GToolStripMenuItem.Click += new System.EventHandler(this.灰度化GToolStripMenuItem_Click);
            // 
            // n值化VToolStripMenuItem
            // 
            this.n值化VToolStripMenuItem.Name = "n值化VToolStripMenuItem";
            this.n值化VToolStripMenuItem.Size = new System.Drawing.Size(173, 26);
            this.n值化VToolStripMenuItem.Text = "二值化(V)";
            this.n值化VToolStripMenuItem.Click += new System.EventHandler(this.二值化VToolStripMenuItem_Click);
            // 
            // 线性变换LToolStripMenuItem
            // 
            this.线性变换LToolStripMenuItem.Name = "线性变换LToolStripMenuItem";
            this.线性变换LToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.线性变换LToolStripMenuItem.Text = "线性变换(L)";
            this.线性变换LToolStripMenuItem.Click += new System.EventHandler(this.线性变换LToolStripMenuItem_Click);
            // 
            // 伽马调整GToolStripMenuItem
            // 
            this.伽马调整GToolStripMenuItem.Name = "伽马调整GToolStripMenuItem";
            this.伽马调整GToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.伽马调整GToolStripMenuItem.Text = "伽马调整(A)";
            this.伽马调整GToolStripMenuItem.Click += new System.EventHandler(this.伽马调整GToolStripMenuItem_Click);
            // 
            // 直方图HToolStripMenuItem
            // 
            this.直方图HToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.灰度ToolStripMenuItem,
            this.rGB直方图CToolStripMenuItem});
            this.直方图HToolStripMenuItem.Name = "直方图HToolStripMenuItem";
            this.直方图HToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.直方图HToolStripMenuItem.Text = "直方图(&H)";
            // 
            // 图像相加AToolStripMenuItem
            // 
            this.图像相加AToolStripMenuItem.Name = "图像相加AToolStripMenuItem";
            this.图像相加AToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.图像相加AToolStripMenuItem.Text = "图像相加(&A)";
            this.图像相加AToolStripMenuItem.Click += new System.EventHandler(this.图像相加AToolStripMenuItem_Click);
            // 
            // 图像滤波FToolStripMenuItem
            // 
            this.图像滤波FToolStripMenuItem.Name = "图像滤波FToolStripMenuItem";
            this.图像滤波FToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.图像滤波FToolStripMenuItem.Text = "图像滤波(&F)";
            this.图像滤波FToolStripMenuItem.Click += new System.EventHandler(this.图像滤波FToolStripMenuItem_Click);
            // 
            // 图像锐化ToolStripMenuItem
            // 
            this.图像锐化ToolStripMenuItem.Name = "图像锐化ToolStripMenuItem";
            this.图像锐化ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.图像锐化ToolStripMenuItem.Text = "图像锐化(&U)";
            this.图像锐化ToolStripMenuItem.Click += new System.EventHandler(this.图像锐化ToolStripMenuItem_Click);
            // 
            // 人脸检测ToolStripMenuItem
            // 
            this.人脸检测ToolStripMenuItem.Name = "人脸检测ToolStripMenuItem";
            this.人脸检测ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.人脸检测ToolStripMenuItem.Text = "人脸检测(&D)";
            this.人脸检测ToolStripMenuItem.Click += new System.EventHandler(this.人脸检测ToolStripMenuItem_Click);
            // 
            // 帮助ToolStripMenuItem
            // 
            this.帮助ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.作者介绍ToolStripMenuItem});
            this.帮助ToolStripMenuItem.Name = "帮助ToolStripMenuItem";
            this.帮助ToolStripMenuItem.Size = new System.Drawing.Size(75, 24);
            this.帮助ToolStripMenuItem.Text = "帮助(H)";
            // 
            // 作者介绍ToolStripMenuItem
            // 
            this.作者介绍ToolStripMenuItem.Name = "作者介绍ToolStripMenuItem";
            this.作者介绍ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.作者介绍ToolStripMenuItem.Text = "作者介绍(&I)";
            this.作者介绍ToolStripMenuItem.Click += new System.EventHandler(this.作者介绍ToolStripMenuItem_Click);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // 灰度ToolStripMenuItem
            // 
            this.灰度ToolStripMenuItem.Name = "灰度ToolStripMenuItem";
            this.灰度ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.灰度ToolStripMenuItem.Text = "灰度直方图(&G)";
            this.灰度ToolStripMenuItem.Click += new System.EventHandler(this.灰度ToolStripMenuItem_Click);
            // 
            // rGB直方图CToolStripMenuItem
            // 
            this.rGB直方图CToolStripMenuItem.Name = "rGB直方图CToolStripMenuItem";
            this.rGB直方图CToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.rGB直方图CToolStripMenuItem.Text = "RGB直方图(&C)";
            this.rGB直方图CToolStripMenuItem.Click += new System.EventHandler(this.rGB直方图CToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1190, 692);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "数字图像处理";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 文件ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 打开OToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 保存ToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem 退出ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 编辑ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 复制ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 粘贴ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 工具ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 对比度CToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem n值化VToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 线性变换LToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 伽马调整GToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 直方图HToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 图像相加AToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 图像滤波FToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 图像锐化ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 人脸检测ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 帮助ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 作者介绍ToolStripMenuItem;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.ToolStripMenuItem 灰度化GToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 设置python路径ToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem 灰度ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rGB直方图CToolStripMenuItem;
    }
}

