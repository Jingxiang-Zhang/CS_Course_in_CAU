namespace 机器学习
{
    partial class RightAttribute
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
            this.timer_load = new System.Windows.Forms.Timer(this.components);
            this.label_attribute = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // timer_load
            // 
            this.timer_load.Enabled = true;
            this.timer_load.Interval = 800;
            this.timer_load.Tick += new System.EventHandler(this.timer_load_Tick);
            // 
            // label_attribute
            // 
            this.label_attribute.AutoSize = true;
            this.label_attribute.Location = new System.Drawing.Point(12, 9);
            this.label_attribute.Name = "label_attribute";
            this.label_attribute.Size = new System.Drawing.Size(37, 15);
            this.label_attribute.TabIndex = 0;
            this.label_attribute.Text = "属性";
            // 
            // RightAttribute
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(250, 565);
            this.Controls.Add(this.label_attribute);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "RightAttribute";
            this.Text = "RightAttribute";
            this.Load += new System.EventHandler(this.RightAttribute_Load);
            this.SizeChanged += new System.EventHandler(this.RightAttribute_SizeChanged);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.RightAttribute_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.RightAttribute_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.RightAttribute_MouseUp);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer timer_load;
        private System.Windows.Forms.Label label_attribute;
    }
}