namespace 作业1
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
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.load_picture = new System.Windows.Forms.Button();
            this.save_picture = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.ErrorImage = null;
            this.pictureBox1.Image = global::作业1.Properties.Resources.timg;
            this.pictureBox1.Location = new System.Drawing.Point(-3, -3);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(516, 389);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // load_picture
            // 
            this.load_picture.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.load_picture.Location = new System.Drawing.Point(45, 424);
            this.load_picture.Name = "load_picture";
            this.load_picture.Size = new System.Drawing.Size(122, 64);
            this.load_picture.TabIndex = 1;
            this.load_picture.Text = "装载图片";
            this.load_picture.UseVisualStyleBackColor = true;
            this.load_picture.Click += new System.EventHandler(this.Load_picture_Click);
            // 
            // save_picture
            // 
            this.save_picture.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.save_picture.Location = new System.Drawing.Point(340, 424);
            this.save_picture.Name = "save_picture";
            this.save_picture.Size = new System.Drawing.Size(122, 64);
            this.save_picture.TabIndex = 2;
            this.save_picture.Text = "保存图片";
            this.save_picture.UseVisualStyleBackColor = true;
            this.save_picture.Click += new System.EventHandler(this.Save_picture_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(510, 500);
            this.Controls.Add(this.save_picture);
            this.Controls.Add(this.load_picture);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button load_picture;
        private System.Windows.Forms.Button save_picture;
    }
}

