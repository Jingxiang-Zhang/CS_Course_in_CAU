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
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.button_start = new System.Windows.Forms.Button();
            this.label_end = new System.Windows.Forms.Button();
            this.label_correct_text = new System.Windows.Forms.Label();
            this.label_correct = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label_time = new System.Windows.Forms.Label();
            this.label_second = new System.Windows.Forms.Label();
            this.number1 = new System.Windows.Forms.Label();
            this.label_add = new System.Windows.Forms.Label();
            this.number2 = new System.Windows.Forms.Label();
            this.label_equal = new System.Windows.Forms.Label();
            this.timer = new System.Windows.Forms.Timer(this.components);
            this.result = new System.Windows.Forms.TextBox();
            this.label_stop = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(38, 45);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(415, 72);
            this.label1.TabIndex = 0;
            this.label1.Text = "本题测试你在一分钟内能做对几道1000以内的加法题";
            // 
            // button_start
            // 
            this.button_start.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.button_start.Location = new System.Drawing.Point(43, 245);
            this.button_start.Name = "button_start";
            this.button_start.Size = new System.Drawing.Size(107, 52);
            this.button_start.TabIndex = 1;
            this.button_start.Text = "开始";
            this.button_start.UseVisualStyleBackColor = true;
            this.button_start.Click += new System.EventHandler(this.Button_start_Click);
            // 
            // label_end
            // 
            this.label_end.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_end.Location = new System.Drawing.Point(315, 245);
            this.label_end.Name = "label_end";
            this.label_end.Size = new System.Drawing.Size(108, 52);
            this.label_end.TabIndex = 2;
            this.label_end.Text = "退出";
            this.label_end.UseVisualStyleBackColor = true;
            this.label_end.Click += new System.EventHandler(this.Label_end_Click);
            // 
            // label_correct_text
            // 
            this.label_correct_text.AutoSize = true;
            this.label_correct_text.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_correct_text.Location = new System.Drawing.Point(63, 142);
            this.label_correct_text.Name = "label_correct_text";
            this.label_correct_text.Size = new System.Drawing.Size(187, 25);
            this.label_correct_text.TabIndex = 3;
            this.label_correct_text.Text = "当前最对题数：";
            // 
            // label_correct
            // 
            this.label_correct.AutoSize = true;
            this.label_correct.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_correct.Location = new System.Drawing.Point(310, 142);
            this.label_correct.Name = "label_correct";
            this.label_correct.Size = new System.Drawing.Size(25, 25);
            this.label_correct.TabIndex = 4;
            this.label_correct.Text = "0";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label4.Location = new System.Drawing.Point(63, 195);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(137, 25);
            this.label4.TabIndex = 5;
            this.label4.Text = "剩余时间：";
            // 
            // label_time
            // 
            this.label_time.AutoSize = true;
            this.label_time.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_time.Location = new System.Drawing.Point(310, 195);
            this.label_time.Name = "label_time";
            this.label_time.Size = new System.Drawing.Size(38, 25);
            this.label_time.TabIndex = 6;
            this.label_time.Text = "60";
            // 
            // label_second
            // 
            this.label_second.AutoSize = true;
            this.label_second.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_second.Location = new System.Drawing.Point(354, 195);
            this.label_second.Name = "label_second";
            this.label_second.Size = new System.Drawing.Size(25, 25);
            this.label_second.TabIndex = 7;
            this.label_second.Text = "S";
            // 
            // number1
            // 
            this.number1.AutoSize = true;
            this.number1.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.number1.Location = new System.Drawing.Point(87, 346);
            this.number1.Name = "number1";
            this.number1.Size = new System.Drawing.Size(25, 25);
            this.number1.TabIndex = 9;
            this.number1.Text = "0";
            // 
            // label_add
            // 
            this.label_add.AutoSize = true;
            this.label_add.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_add.Location = new System.Drawing.Point(156, 346);
            this.label_add.Name = "label_add";
            this.label_add.Size = new System.Drawing.Size(25, 25);
            this.label_add.TabIndex = 10;
            this.label_add.Text = "+";
            // 
            // number2
            // 
            this.number2.AutoSize = true;
            this.number2.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.number2.Location = new System.Drawing.Point(225, 346);
            this.number2.Name = "number2";
            this.number2.Size = new System.Drawing.Size(25, 25);
            this.number2.TabIndex = 11;
            this.number2.Text = "0";
            // 
            // label_equal
            // 
            this.label_equal.AutoSize = true;
            this.label_equal.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_equal.Location = new System.Drawing.Point(271, 346);
            this.label_equal.Name = "label_equal";
            this.label_equal.Size = new System.Drawing.Size(25, 25);
            this.label_equal.TabIndex = 12;
            this.label_equal.Text = "=";
            // 
            // timer
            // 
            this.timer.Interval = 1000;
            this.timer.Tick += new System.EventHandler(this.Timer_Tick);
            // 
            // result
            // 
            this.result.Font = new System.Drawing.Font("宋体", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.result.Location = new System.Drawing.Point(315, 341);
            this.result.Name = "result";
            this.result.Size = new System.Drawing.Size(108, 38);
            this.result.TabIndex = 8;
            this.result.TextChanged += new System.EventHandler(this.TextBox1_TextChanged);
            this.result.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Result_KeyPress);
            // 
            // label_stop
            // 
            this.label_stop.Enabled = false;
            this.label_stop.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_stop.Location = new System.Drawing.Point(182, 245);
            this.label_stop.Name = "label_stop";
            this.label_stop.Size = new System.Drawing.Size(94, 52);
            this.label_stop.TabIndex = 13;
            this.label_stop.Text = "暂停";
            this.label_stop.UseVisualStyleBackColor = true;
            this.label_stop.Click += new System.EventHandler(this.Label_stop_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(485, 440);
            this.Controls.Add(this.label_stop);
            this.Controls.Add(this.label_equal);
            this.Controls.Add(this.number2);
            this.Controls.Add(this.label_add);
            this.Controls.Add(this.number1);
            this.Controls.Add(this.result);
            this.Controls.Add(this.label_second);
            this.Controls.Add(this.label_time);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label_correct);
            this.Controls.Add(this.label_correct_text);
            this.Controls.Add(this.label_end);
            this.Controls.Add(this.button_start);
            this.Controls.Add(this.label1);
            this.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "加法测试";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button_start;
        private System.Windows.Forms.Button label_end;
        private System.Windows.Forms.Label label_correct_text;
        private System.Windows.Forms.Label label_correct;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label_time;
        private System.Windows.Forms.Label label_second;
        private System.Windows.Forms.Label number1;
        private System.Windows.Forms.Label label_add;
        private System.Windows.Forms.Label number2;
        private System.Windows.Forms.Label label_equal;
        private System.Windows.Forms.Timer timer;
        private System.Windows.Forms.TextBox result;
        private System.Windows.Forms.Button label_stop;
    }
}

