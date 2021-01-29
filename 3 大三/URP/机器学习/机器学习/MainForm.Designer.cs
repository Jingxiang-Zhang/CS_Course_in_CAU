namespace 机器学习
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.Menu_File = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_File_newfile = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_File_open = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.Menu_File_close = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.Menu_File_save = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_File_saveas = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.Menu_File_exit = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Edit = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Edit_search = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.Menu_Edit_undo = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Edit_redo = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.Menu_Edit_cut = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Edit_copy = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Edit_paste = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Edit_delete = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Gengrate = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Gengrate_pyfile = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Test = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Test_Run = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Help = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Help_help = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Help_support = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.timer1_load = new System.Windows.Forms.Timer(this.components);
            this.contextMenuStrip_Icon = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.还原ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.最大化ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.最小化ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.关闭ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label1 = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.contextMenuStrip_Icon.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Menu_File,
            this.Menu_Edit,
            this.Menu_Gengrate,
            this.Menu_Test,
            this.Menu_Help});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1180, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // Menu_File
            // 
            this.Menu_File.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Menu_File_newfile,
            this.Menu_File_open,
            this.toolStripSeparator1,
            this.Menu_File_close,
            this.toolStripSeparator2,
            this.Menu_File_save,
            this.Menu_File_saveas,
            this.toolStripSeparator3,
            this.Menu_File_exit});
            this.Menu_File.Name = "Menu_File";
            this.Menu_File.Size = new System.Drawing.Size(71, 24);
            this.Menu_File.Text = "文件(&F)";
            // 
            // Menu_File_newfile
            // 
            this.Menu_File_newfile.Name = "Menu_File_newfile";
            this.Menu_File_newfile.Size = new System.Drawing.Size(224, 26);
            this.Menu_File_newfile.Text = "新建(&N)";
            this.Menu_File_newfile.Click += new System.EventHandler(this.Menu_File_newfile_Click);
            // 
            // Menu_File_open
            // 
            this.Menu_File_open.Name = "Menu_File_open";
            this.Menu_File_open.Size = new System.Drawing.Size(224, 26);
            this.Menu_File_open.Text = "打开(&O)";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(221, 6);
            // 
            // Menu_File_close
            // 
            this.Menu_File_close.Name = "Menu_File_close";
            this.Menu_File_close.Size = new System.Drawing.Size(224, 26);
            this.Menu_File_close.Text = "关闭(&C)";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(221, 6);
            // 
            // Menu_File_save
            // 
            this.Menu_File_save.Name = "Menu_File_save";
            this.Menu_File_save.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.Menu_File_save.Size = new System.Drawing.Size(224, 26);
            this.Menu_File_save.Text = "保存(&S)";
            // 
            // Menu_File_saveas
            // 
            this.Menu_File_saveas.Name = "Menu_File_saveas";
            this.Menu_File_saveas.Size = new System.Drawing.Size(224, 26);
            this.Menu_File_saveas.Text = "另存为(&A)";
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(221, 6);
            // 
            // Menu_File_exit
            // 
            this.Menu_File_exit.Name = "Menu_File_exit";
            this.Menu_File_exit.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F4)));
            this.Menu_File_exit.Size = new System.Drawing.Size(224, 26);
            this.Menu_File_exit.Text = "退出(&X)";
            this.Menu_File_exit.Click += new System.EventHandler(this.Menu_File_exit_Click);
            // 
            // Menu_Edit
            // 
            this.Menu_Edit.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Menu_Edit_search,
            this.toolStripSeparator4,
            this.Menu_Edit_undo,
            this.Menu_Edit_redo,
            this.toolStripSeparator5,
            this.Menu_Edit_cut,
            this.Menu_Edit_copy,
            this.Menu_Edit_paste,
            this.Menu_Edit_delete});
            this.Menu_Edit.Name = "Menu_Edit";
            this.Menu_Edit.Size = new System.Drawing.Size(71, 24);
            this.Menu_Edit.Text = "编辑(&E)";
            // 
            // Menu_Edit_search
            // 
            this.Menu_Edit_search.Name = "Menu_Edit_search";
            this.Menu_Edit_search.Size = new System.Drawing.Size(200, 26);
            this.Menu_Edit_search.Text = "查找和替换(&F)";
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(197, 6);
            // 
            // Menu_Edit_undo
            // 
            this.Menu_Edit_undo.Name = "Menu_Edit_undo";
            this.Menu_Edit_undo.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
            this.Menu_Edit_undo.Size = new System.Drawing.Size(200, 26);
            this.Menu_Edit_undo.Text = "撤销(&U)";
            // 
            // Menu_Edit_redo
            // 
            this.Menu_Edit_redo.Name = "Menu_Edit_redo";
            this.Menu_Edit_redo.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Y)));
            this.Menu_Edit_redo.Size = new System.Drawing.Size(200, 26);
            this.Menu_Edit_redo.Text = "重做(&R)";
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(197, 6);
            // 
            // Menu_Edit_cut
            // 
            this.Menu_Edit_cut.Name = "Menu_Edit_cut";
            this.Menu_Edit_cut.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X)));
            this.Menu_Edit_cut.Size = new System.Drawing.Size(200, 26);
            this.Menu_Edit_cut.Text = "剪切(&T)";
            // 
            // Menu_Edit_copy
            // 
            this.Menu_Edit_copy.Name = "Menu_Edit_copy";
            this.Menu_Edit_copy.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C)));
            this.Menu_Edit_copy.Size = new System.Drawing.Size(200, 26);
            this.Menu_Edit_copy.Text = "复制(&C)";
            // 
            // Menu_Edit_paste
            // 
            this.Menu_Edit_paste.Name = "Menu_Edit_paste";
            this.Menu_Edit_paste.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
            this.Menu_Edit_paste.Size = new System.Drawing.Size(200, 26);
            this.Menu_Edit_paste.Text = "粘贴(&P)";
            // 
            // Menu_Edit_delete
            // 
            this.Menu_Edit_delete.Name = "Menu_Edit_delete";
            this.Menu_Edit_delete.ShortcutKeys = System.Windows.Forms.Keys.Delete;
            this.Menu_Edit_delete.Size = new System.Drawing.Size(200, 26);
            this.Menu_Edit_delete.Text = "删除(&D)";
            // 
            // Menu_Gengrate
            // 
            this.Menu_Gengrate.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Menu_Gengrate_pyfile});
            this.Menu_Gengrate.Name = "Menu_Gengrate";
            this.Menu_Gengrate.Size = new System.Drawing.Size(72, 24);
            this.Menu_Gengrate.Text = "生成(&B)";
            // 
            // Menu_Gengrate_pyfile
            // 
            this.Menu_Gengrate_pyfile.Name = "Menu_Gengrate_pyfile";
            this.Menu_Gengrate_pyfile.ShortcutKeys = System.Windows.Forms.Keys.F7;
            this.Menu_Gengrate_pyfile.Size = new System.Drawing.Size(248, 26);
            this.Menu_Gengrate_pyfile.Text = "生成Python文件(&B)";
            // 
            // Menu_Test
            // 
            this.Menu_Test.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Menu_Test_Run});
            this.Menu_Test.Name = "Menu_Test";
            this.Menu_Test.Size = new System.Drawing.Size(74, 24);
            this.Menu_Test.Text = "调试(&D)";
            // 
            // Menu_Test_Run
            // 
            this.Menu_Test_Run.Name = "Menu_Test_Run";
            this.Menu_Test_Run.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.F5)));
            this.Menu_Test_Run.Size = new System.Drawing.Size(237, 26);
            this.Menu_Test_Run.Text = "开始执行(&H)";
            // 
            // Menu_Help
            // 
            this.Menu_Help.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Menu_Help_help,
            this.Menu_Help_support});
            this.Menu_Help.Name = "Menu_Help";
            this.Menu_Help.Size = new System.Drawing.Size(75, 24);
            this.Menu_Help.Text = "帮助(&H)";
            // 
            // Menu_Help_help
            // 
            this.Menu_Help_help.Name = "Menu_Help_help";
            this.Menu_Help_help.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.F1)));
            this.Menu_Help_help.Size = new System.Drawing.Size(215, 26);
            this.Menu_Help_help.Text = "查看帮助";
            // 
            // Menu_Help_support
            // 
            this.Menu_Help_support.Name = "Menu_Help_support";
            this.Menu_Help_support.Size = new System.Drawing.Size(215, 26);
            this.Menu_Help_support.Text = "技术支持";
            // 
            // toolStrip1
            // 
            this.toolStrip1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1,
            this.toolStripButton2});
            this.toolStrip1.Location = new System.Drawing.Point(0, 28);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(1180, 27);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(29, 24);
            this.toolStripButton1.Text = "toolStripButton1";
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(29, 24);
            this.toolStripButton2.Text = "toolStripButton2";
            // 
            // timer1_load
            // 
            this.timer1_load.Enabled = true;
            this.timer1_load.Interval = 10;
            this.timer1_load.Tick += new System.EventHandler(this.timer1_load_Tick);
            // 
            // contextMenuStrip_Icon
            // 
            this.contextMenuStrip_Icon.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip_Icon.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.还原ToolStripMenuItem,
            this.最大化ToolStripMenuItem,
            this.最小化ToolStripMenuItem,
            this.toolStripSeparator6,
            this.关闭ToolStripMenuItem});
            this.contextMenuStrip_Icon.Name = "contextMenuStrip_Icon";
            this.contextMenuStrip_Icon.Size = new System.Drawing.Size(124, 106);
            // 
            // 还原ToolStripMenuItem
            // 
            this.还原ToolStripMenuItem.Name = "还原ToolStripMenuItem";
            this.还原ToolStripMenuItem.Size = new System.Drawing.Size(123, 24);
            this.还原ToolStripMenuItem.Text = "还原";
            // 
            // 最大化ToolStripMenuItem
            // 
            this.最大化ToolStripMenuItem.Name = "最大化ToolStripMenuItem";
            this.最大化ToolStripMenuItem.Size = new System.Drawing.Size(123, 24);
            this.最大化ToolStripMenuItem.Text = "最大化";
            // 
            // 最小化ToolStripMenuItem
            // 
            this.最小化ToolStripMenuItem.Name = "最小化ToolStripMenuItem";
            this.最小化ToolStripMenuItem.Size = new System.Drawing.Size(123, 24);
            this.最小化ToolStripMenuItem.Text = "最小化";
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            this.toolStripSeparator6.Size = new System.Drawing.Size(120, 6);
            // 
            // 关闭ToolStripMenuItem
            // 
            this.关闭ToolStripMenuItem.Name = "关闭ToolStripMenuItem";
            this.关闭ToolStripMenuItem.Size = new System.Drawing.Size(123, 24);
            this.关闭ToolStripMenuItem.Text = "关闭";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(386, 268);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(262, 25);
            this.label1.TabIndex = 6;
            this.label1.Text = "注：所有功能均未实现";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1180, 672);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.MinimumSize = new System.Drawing.Size(1180, 672);
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Ai Learn";
            this.SizeChanged += new System.EventHandler(this.MainForm_SizeChanged);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.contextMenuStrip_Icon.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem Menu_File;
        private System.Windows.Forms.ToolStripMenuItem Menu_File_newfile;
        private System.Windows.Forms.ToolStripMenuItem Menu_File_open;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem Menu_File_close;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem Menu_File_save;
        private System.Windows.Forms.ToolStripMenuItem Menu_File_saveas;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem Menu_File_exit;
        private System.Windows.Forms.ToolStripMenuItem Menu_Edit;
        private System.Windows.Forms.ToolStripMenuItem Menu_Edit_search;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripMenuItem Menu_Edit_undo;
        private System.Windows.Forms.ToolStripMenuItem Menu_Edit_redo;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripMenuItem Menu_Edit_cut;
        private System.Windows.Forms.ToolStripMenuItem Menu_Edit_copy;
        private System.Windows.Forms.ToolStripMenuItem Menu_Edit_paste;
        private System.Windows.Forms.ToolStripMenuItem Menu_Edit_delete;
        private System.Windows.Forms.ToolStripMenuItem Menu_Gengrate;
        private System.Windows.Forms.ToolStripMenuItem Menu_Gengrate_pyfile;
        private System.Windows.Forms.ToolStripMenuItem Menu_Test;
        private System.Windows.Forms.ToolStripMenuItem Menu_Test_Run;
        private System.Windows.Forms.ToolStripMenuItem Menu_Help;
        private System.Windows.Forms.ToolStripMenuItem Menu_Help_help;
        private System.Windows.Forms.ToolStripMenuItem Menu_Help_support;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        private System.Windows.Forms.Timer timer1_load;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip_Icon;
        private System.Windows.Forms.ToolStripMenuItem 还原ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 最大化ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 最小化ToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator6;
        private System.Windows.Forms.ToolStripMenuItem 关闭ToolStripMenuItem;
        private System.Windows.Forms.Label label1;
    }
}

