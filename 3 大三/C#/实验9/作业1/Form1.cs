using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.Sql;
using System.Data.SqlClient;

namespace 作业1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.radioButton_nan.Checked = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string connectStr = "Data Source=.;Initial Catalog=test;User ID=sa;pwd=sa";
            SqlConnection connection = new SqlConnection(connectStr);
            try
            {
                string sqlStr = "select 姓名 from 医生";
                connection.Open();
                SqlCommand cmd = new SqlCommand(sqlStr, connection);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    comboBox_yisheng.Items.Add(reader[0].ToString());
                }
            }
            catch(Exception et)
            {
                MessageBox.Show(et.Message, "错误");
                this.Close();
            }
            finally
            {
                connection.Close();
            }
            try
            {
                string sqlStr = "select 类别名称 from 类型表数据字典";
                connection.Open();
                SqlCommand cmd = new SqlCommand(sqlStr, connection);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    comboBox_leixing.Items.Add(reader[0].ToString());
                }
            }
            catch (Exception et)
            {
                MessageBox.Show(et.Message, "错误");
                this.Close();
            }
            finally
            {
                connection.Close();
            }



        }

        private void Button_exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        
        private void Button_add_Click(object sender, EventArgs e)
        {
            if (!Check())
            {
                return;
            }
            string connectStr = "Data Source=.;Initial Catalog=test;User ID=sa;pwd=sa";
            SqlConnection connection = new SqlConnection(connectStr);
            try
            {
                string xingbie = "男";
                string sqlStr = "insert into 病人 values ('" +
                                textBox_bingrenbianhao.Text + "','" +
                                textBox_xingming.Text + "','" +
                                textBox_nianling.Text + "','" +
                                xingbie + "','" +
                                text_bingzheng.Text + "','" +
                                comboBox_leixing.SelectedIndex + "','" +
                                comboBox_yisheng.SelectedIndex + "')";


                connection.Open();
                SqlCommand cmd = new SqlCommand(sqlStr, connection);
                cmd.ExecuteNonQuery();
                MessageBox.Show("插入成功", "成功");
            }
            catch (Exception et)
            {
                MessageBox.Show(et.Message, "错误");
            }
            finally
            {
                connection.Close();
            }

        }
        public Boolean Check()
        {
            if (textBox_bingrenbianhao.Text == "")
            {
                MessageBox.Show("医生编号不能为空！", "错误");
                return false;
            }
            if (textBox_xingming.Text == "")
            {
                MessageBox.Show("姓名不能为空！", "错误");
                return false;
            }

            if (comboBox_yisheng.SelectedIndex == -1)
            {
                MessageBox.Show("医生不能不选！", "错误");
                return false;
            }
            if (comboBox_leixing.SelectedIndex == -1)
            {
                MessageBox.Show("类别不能不选！", "错误");
                return false;
            }
            if (textBox_nianling.Text == "")
            {
                MessageBox.Show("年龄不能为空！", "错误");
                return false;
            }
            if (text_bingzheng.Text == "")
            {
                MessageBox.Show("年龄不能为空！", "错误");
                return false;
            }
            try
            {
                int age = Convert.ToInt32(textBox_nianling.Text);
                if(age<0 || age > 100)
                {
                    MessageBox.Show("年龄范围不合理！", "错误");
                    return false;
                }
            }
            catch
            {
                MessageBox.Show("年龄错误！", "错误");
                return false;
            }
            return true;
        }
    }
}
