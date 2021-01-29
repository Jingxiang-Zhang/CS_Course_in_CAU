namespace 机器学习
{
    partial class LeftToolTipNet
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label_top = new System.Windows.Forms.Label();
            this.treeView_net = new System.Windows.Forms.TreeView();
            this.contextMenu_net = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.新建数据源ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.新建网络ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.添加代码ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.添加输出ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.timer_load = new System.Windows.Forms.Timer(this.components);
            this.contextMenu_net.SuspendLayout();
            this.SuspendLayout();
            // 
            // label_top
            // 
            this.label_top.AutoSize = true;
            this.label_top.Location = new System.Drawing.Point(12, 9);
            this.label_top.Name = "label_top";
            this.label_top.Size = new System.Drawing.Size(112, 15);
            this.label_top.TabIndex = 0;
            this.label_top.Text = "网络层次结构图";
            // 
            // treeView_net
            // 
            this.treeView_net.ContextMenuStrip = this.contextMenu_net;
            this.treeView_net.Location = new System.Drawing.Point(2, 65);
            this.treeView_net.Name = "treeView_net";
            this.treeView_net.Size = new System.Drawing.Size(245, 495);
            this.treeView_net.TabIndex = 1;
            this.treeView_net.MouseMove += new System.Windows.Forms.MouseEventHandler(this.treeView_net_MouseMove);
            // 
            // contextMenu_net
            // 
            this.contextMenu_net.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenu_net.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.新建数据源ToolStripMenuItem,
            this.新建网络ToolStripMenuItem,
            this.添加代码ToolStripMenuItem,
            this.添加输出ToolStripMenuItem});
            this.contextMenu_net.Name = "contextMenu_net";
            this.contextMenu_net.Size = new System.Drawing.Size(173, 100);
            // 
            // 新建数据源ToolStripMenuItem
            // 
            this.新建数据源ToolStripMenuItem.Name = "新建数据源ToolStripMenuItem";
            this.新建数据源ToolStripMenuItem.Size = new System.Drawing.Size(172, 24);
            this.新建数据源ToolStripMenuItem.Text = "添加数据源(&S)";
            // 
            // 新建网络ToolStripMenuItem
            // 
            this.新建网络ToolStripMenuItem.Name = "新建网络ToolStripMenuItem";
            this.新建网络ToolStripMenuItem.Size = new System.Drawing.Size(172, 24);
            this.新建网络ToolStripMenuItem.Text = "添加网络(&N)";
            // 
            // 添加代码ToolStripMenuItem
            // 
            this.添加代码ToolStripMenuItem.Name = "添加代码ToolStripMenuItem";
            this.添加代码ToolStripMenuItem.Size = new System.Drawing.Size(172, 24);
            this.添加代码ToolStripMenuItem.Text = "添加代码(&C)";
            // 
            // 添加输出ToolStripMenuItem
            // 
            this.添加输出ToolStripMenuItem.Name = "添加输出ToolStripMenuItem";
            this.添加输出ToolStripMenuItem.Size = new System.Drawing.Size(172, 24);
            this.添加输出ToolStripMenuItem.Text = "添加输出(&E)";
            // 
            // timer_load
            // 
            this.timer_load.Enabled = true;
            this.timer_load.Interval = 800;
            this.timer_load.Tick += new System.EventHandler(this.timer_load_Tick);
            // 
            // LeftToolTipNet
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(250, 565);
            this.Controls.Add(this.treeView_net);
            this.Controls.Add(this.label_top);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.MaximumSize = new System.Drawing.Size(600, 2000);
            this.MinimumSize = new System.Drawing.Size(250, 0);
            this.Name = "LeftToolTipNet";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "LeftToolTipNet";
            this.SizeChanged += new System.EventHandler(this.LeftToolTipNet_SizeChanged);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.LeftToolTipNet_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.LeftToolTipNet_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.LeftToolTipNet_MouseUp);
            this.contextMenu_net.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_top;
        public System.Windows.Forms.TreeView treeView_net;
        private System.Windows.Forms.ContextMenuStrip contextMenu_net;
        private System.Windows.Forms.ToolStripMenuItem 新建数据源ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 新建网络ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 添加代码ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 添加输出ToolStripMenuItem;
        private System.Windows.Forms.Timer timer_load;
    }
}