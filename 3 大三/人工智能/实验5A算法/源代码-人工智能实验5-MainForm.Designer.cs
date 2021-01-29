namespace 人工智能实验5
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.label1 = new System.Windows.Forms.Label();
            this.pictureBox_flag = new System.Windows.Forms.PictureBox();
            this.pictureBox_asterisk = new System.Windows.Forms.PictureBox();
            this.label2 = new System.Windows.Forms.Label();
            this.trackBar_bar = new System.Windows.Forms.TrackBar();
            this.label_startT = new System.Windows.Forms.Label();
            this.label_start = new System.Windows.Forms.Label();
            this.label_end = new System.Windows.Forms.Label();
            this.label_endT = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.label3 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.label_clock = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.pictureBox_person = new System.Windows.Forms.PictureBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_flag)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_asterisk)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_bar)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_person)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(26, 46);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(309, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "请拖拽起点和终点到地图中的位置";
            // 
            // pictureBox_flag
            // 
            this.pictureBox_flag.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_flag.Image")));
            this.pictureBox_flag.Location = new System.Drawing.Point(420, 30);
            this.pictureBox_flag.Name = "pictureBox_flag";
            this.pictureBox_flag.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_flag.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_flag.TabIndex = 1;
            this.pictureBox_flag.TabStop = false;
            this.pictureBox_flag.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox_flag_MouseDown);
            this.pictureBox_flag.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox_flag_MouseMove);
            this.pictureBox_flag.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pictureBox_flag_MouseUp);
            // 
            // pictureBox_asterisk
            // 
            this.pictureBox_asterisk.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_asterisk.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_asterisk.Image")));
            this.pictureBox_asterisk.Location = new System.Drawing.Point(350, 30);
            this.pictureBox_asterisk.Name = "pictureBox_asterisk";
            this.pictureBox_asterisk.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_asterisk.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_asterisk.TabIndex = 2;
            this.pictureBox_asterisk.TabStop = false;
            this.pictureBox_asterisk.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox_asterisk_MouseDown);
            this.pictureBox_asterisk.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox_asterisk_MouseMove);
            this.pictureBox_asterisk.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pictureBox_asterisk_MouseUp);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.Location = new System.Drawing.Point(335, 88);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(149, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "障碍画笔的程度";
            // 
            // trackBar_bar
            // 
            this.trackBar_bar.AutoSize = false;
            this.trackBar_bar.Location = new System.Drawing.Point(339, 112);
            this.trackBar_bar.Maximum = 4;
            this.trackBar_bar.Name = "trackBar_bar";
            this.trackBar_bar.Size = new System.Drawing.Size(168, 38);
            this.trackBar_bar.TabIndex = 4;
            // 
            // label_startT
            // 
            this.label_startT.AutoSize = true;
            this.label_startT.Location = new System.Drawing.Point(417, 41);
            this.label_startT.Name = "label_startT";
            this.label_startT.Size = new System.Drawing.Size(52, 15);
            this.label_startT.TabIndex = 5;
            this.label_startT.Text = "起点：";
            this.label_startT.Visible = false;
            // 
            // label_start
            // 
            this.label_start.AutoSize = true;
            this.label_start.Location = new System.Drawing.Point(417, 65);
            this.label_start.Name = "label_start";
            this.label_start.Size = new System.Drawing.Size(15, 15);
            this.label_start.TabIndex = 6;
            this.label_start.Text = "s";
            this.label_start.Visible = false;
            // 
            // label_end
            // 
            this.label_end.AutoSize = true;
            this.label_end.Location = new System.Drawing.Point(347, 65);
            this.label_end.Name = "label_end";
            this.label_end.Size = new System.Drawing.Size(15, 15);
            this.label_end.TabIndex = 8;
            this.label_end.Text = "e";
            this.label_end.Visible = false;
            // 
            // label_endT
            // 
            this.label_endT.AutoSize = true;
            this.label_endT.Location = new System.Drawing.Point(347, 41);
            this.label_endT.Name = "label_endT";
            this.label_endT.Size = new System.Drawing.Size(52, 15);
            this.label_endT.TabIndex = 7;
            this.label_endT.Text = "终点：";
            this.label_endT.Visible = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButton3);
            this.groupBox1.Controls.Add(this.radioButton2);
            this.groupBox1.Controls.Add(this.radioButton1);
            this.groupBox1.Location = new System.Drawing.Point(12, 88);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(305, 47);
            this.groupBox1.TabIndex = 9;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "请选择画笔";
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(194, 24);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(103, 19);
            this.radioButton3.TabIndex = 2;
            this.radioButton3.Text = "障碍物画笔";
            this.radioButton3.UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(115, 24);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(73, 19);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "墙画笔";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(16, 22);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(88, 19);
            this.radioButton1.TabIndex = 0;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "空白画笔";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label3.Location = new System.Drawing.Point(185, 236);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(0, 15);
            this.label3.TabIndex = 10;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(206, 141);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(133, 33);
            this.button1.TabIndex = 11;
            this.button1.Text = "开始寻路";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label_clock
            // 
            this.label_clock.AutoSize = true;
            this.label_clock.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_clock.Location = new System.Drawing.Point(230, 146);
            this.label_clock.Name = "label_clock";
            this.label_clock.Size = new System.Drawing.Size(79, 20);
            this.label_clock.TabIndex = 12;
            this.label_clock.Text = "周期：0";
            this.label_clock.Visible = false;
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // pictureBox_person
            // 
            this.pictureBox_person.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_person.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_person.Image")));
            this.pictureBox_person.Location = new System.Drawing.Point(12, 146);
            this.pictureBox_person.Name = "pictureBox_person";
            this.pictureBox_person.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_person.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_person.TabIndex = 13;
            this.pictureBox_person.TabStop = false;
            this.pictureBox_person.Visible = false;
            // 
            // comboBox1
            // 
            this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "曼哈顿距离",
            "欧几里得距离",
            "切比雪夫距离"});
            this.comboBox1.Location = new System.Drawing.Point(386, 147);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 23);
            this.comboBox1.TabIndex = 14;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(532, 510);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.pictureBox_person);
            this.Controls.Add(this.label_clock);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label_end);
            this.Controls.Add(this.label_endT);
            this.Controls.Add(this.label_start);
            this.Controls.Add(this.label_startT);
            this.Controls.Add(this.trackBar_bar);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.pictureBox_asterisk);
            this.Controls.Add(this.pictureBox_flag);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MinimumSize = new System.Drawing.Size(550, 540);
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "张靖祥 实验5 2017304010413";
            this.Load += new System.EventHandler(this.MainForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_flag)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_asterisk)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_bar)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_person)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox pictureBox_flag;
        private System.Windows.Forms.PictureBox pictureBox_asterisk;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TrackBar trackBar_bar;
        private System.Windows.Forms.Label label_startT;
        private System.Windows.Forms.Label label_start;
        private System.Windows.Forms.Label label_end;
        private System.Windows.Forms.Label label_endT;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label_clock;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.PictureBox pictureBox_person;
        private System.Windows.Forms.ComboBox comboBox1;
    }
}