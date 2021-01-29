using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 作业1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“test10DataSet.student”中。您可以根据需要移动或删除它。
            this.studentTableAdapter.Fill(this.test10DataSet.student);
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            if (!(textBox1.Text == "男" || textBox1.Text == "女"))
            {
                MessageBox.Show("错误，性别只能为男或女", "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            string conn = "Data Source=.;Initial Catalog=test10;User ID=sa;pwd=sa";
            SqlConnection connection = new SqlConnection(conn);
            try
            {
                connection.Open();
                string sqlStr = "DECLARE @Sex NCHAR='" + textBox1.Text + "' exec SelectManStudent @Sex";

                SqlCommand cmd = new SqlCommand("SelectManStudent", connection);
                cmd.CommandType = CommandType.StoredProcedure;

                SqlParameter sp = new SqlParameter("@Sex", SqlDbType.NChar);
                sp.Value = textBox1.Text;
                cmd.Parameters.Add(sp);
               
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds, "test10");
                dataGridView1.DataSource = ds.Tables[0].DefaultView;
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message, "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
