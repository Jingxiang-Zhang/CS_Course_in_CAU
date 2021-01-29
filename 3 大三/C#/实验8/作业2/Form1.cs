using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 作业2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
         }

        private void TreeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            if (e.Node.Text.ToString() != "我的电脑")
                EnumDirectories(e.Node);
            else
                EnumDrives(e.Node);

        }

        private void EnumDirectories(TreeNode ParentNode)
        {
            treeView1.SelectedNode = ParentNode;
            string DirectoryPath = ParentNode.Tag.ToString();
            if (ParentNode.Nodes.Count == 0)
            {
                if (DirectoryPath.Substring(DirectoryPath.Length - 1) != @"\")
                    DirectoryPath += @"\";
                try
                {
                    foreach (string directory in Directory.GetDirectories(DirectoryPath))
                    {
                        TreeNode TempNode = new TreeNode();
                        TempNode.Text = directory.Substring(directory.LastIndexOf(@"\") + 1);
                        TempNode.Tag = directory;
                        TempNode.ImageIndex = 3;
                        TempNode.SelectedImageIndex = 4;
                        treeView1.SelectedNode.Nodes.Add(TempNode);
                        treeView1.SelectedNode.Nodes[treeView1.SelectedNode.Nodes.Count - 1].EnsureVisible();
                    }
                    foreach (string directory in Directory.GetFiles(DirectoryPath))
                    {
                        TreeNode TempNode = new TreeNode();
                        TempNode.Text = directory.Substring(directory.LastIndexOf(@"\") + 1);
                        TempNode.Tag = directory;
                        TempNode.ImageIndex = 5;
                        TempNode.SelectedImageIndex = 6;
                        treeView1.SelectedNode.Nodes.Add(TempNode);
           //             treeView1.SelectedNode.Nodes[treeView1.SelectedNode.Nodes.Count - 1].EnsureVisible();
                    }
                }
                catch (Exception)
                {
                }
            }
        }
        
        private void EnumDrives(TreeNode ParentNode)
        {
            if (ParentNode.Nodes.Count == 0)
            {
                foreach (string drive in Directory.GetLogicalDrives())
                {
                    treeView1.SelectedNode = ParentNode;
                    TreeNode TempNode = new TreeNode();
                    TempNode.Text = drive.Substring(0, drive.Length - 1);
                    TempNode.Tag = drive;
                    TempNode.ImageIndex = 1;
                    TempNode.SelectedImageIndex = 2;
                    treeView1.SelectedNode.Nodes.Add(TempNode);
              //      treeView1.SelectedNode.Nodes[treeView1.SelectedNode.Nodes.Count - 1].EnsureVisible();
                }
            }
        }

        string textname = "";
        private void TreeView1_MouseDown(object sender, MouseEventArgs e)
        {
            if(e.Button== System.Windows.Forms.MouseButtons.Right)
            {
                TreeNode tn = treeView1.GetNodeAt(new Point(e.X, e.Y));
                if (tn != null)
                {
                    textname = tn.Tag.ToString();
                    contextMenuStrip1.Show(treeView1, new Point(e.X, e.Y));
                }
            }
        }

        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ProcessStartInfo info = new ProcessStartInfo();
            info.FileName = textname;
            info.Arguments = "";
            info.WindowStyle = ProcessWindowStyle.Normal;
            Process pro = Process.Start(info);
        }

        private void TreeView1_AfterExpand(object sender, TreeViewEventArgs e)
        {
            //收缩与目标node同一级别的node
            TreeNode tn = e.Node;
            if (tn.Parent != null)
            {
                foreach (TreeNode node in tn.Parent.Nodes)
                {
                    if (tn != node)
                    {
                        node.Collapse();
                    }
                }
            }
            //收缩根节点
            while (tn.Parent != null)
                tn = tn.Parent;
            foreach (TreeNode node in treeView1.Nodes)
            {
                if (tn != node)
                {
                    node.Collapse();
                }
            }
        }

        private void TreeView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Left)
            {
                TreeNode tn = treeView1.GetNodeAt(new Point(e.X, e.Y));
                if(tn != null)
                {
                    string name = tn.Text;
                    if (name.Contains("."))
                    {
                        name = tn.Tag.ToString();
                        ProcessStartInfo info = new ProcessStartInfo();
                        info.FileName = name;
                        info.Arguments = "";
                        info.WindowStyle = ProcessWindowStyle.Normal;
                        Process pro = Process.Start(info);
                    }
                }
            }
        }
    }
}
