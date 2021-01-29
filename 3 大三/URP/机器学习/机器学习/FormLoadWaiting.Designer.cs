namespace 机器学习
{
    partial class FormLoadWaiting
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
            this.bgimage = new System.Windows.Forms.PictureBox();
            this.label_LoadContent = new System.Windows.Forms.Label();
            this.Load_time = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.bgimage)).BeginInit();
            this.SuspendLayout();
            // 
            // bgimage
            // 
            this.bgimage.Location = new System.Drawing.Point(0, 0);
            this.bgimage.Name = "bgimage";
            this.bgimage.Size = new System.Drawing.Size(500, 354);
            this.bgimage.TabIndex = 1;
            this.bgimage.TabStop = false;
            // 
            // label_LoadContent
            // 
            this.label_LoadContent.AutoSize = true;
            this.label_LoadContent.BackColor = System.Drawing.Color.Transparent;
            this.label_LoadContent.ForeColor = System.Drawing.Color.White;
            this.label_LoadContent.Location = new System.Drawing.Point(96, 274);
            this.label_LoadContent.Name = "label_LoadContent";
            this.label_LoadContent.Size = new System.Drawing.Size(82, 15);
            this.label_LoadContent.TabIndex = 2;
            this.label_LoadContent.Text = "正在加载：";
            // 
            // Load_time
            // 
            this.Load_time.Enabled = true;
            this.Load_time.Interval = 1;
            this.Load_time.Tick += new System.EventHandler(this.Load_time_Tick);
            // 
            // FormLoadWaiting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(500, 354);
            this.bgimage.Controls.Add(this.label_LoadContent);
            this.Controls.Add(this.bgimage);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "FormLoadWaiting";
            this.Text = "Load";
            ((System.ComponentModel.ISupportInitialize)(this.bgimage)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.PictureBox bgimage;
        private System.Windows.Forms.Label label_LoadContent;
        private System.Windows.Forms.Timer Load_time;
    }
}