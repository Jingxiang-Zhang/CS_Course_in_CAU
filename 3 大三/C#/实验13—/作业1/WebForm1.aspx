<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="作业1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>

</head>
<body style="background-color: aliceblue">
    <form id="form1" runat="server">
        <div>
            <h1><u>
                <center>中新公司员工信息表</center>
            </u></h1>
        </div>
        <div>
            <table>
                <tr>
                    <td>
                        <div style="width: 100px" align="center"></div>
                    </td>
                    <td>
                        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource1"
                            DataKeyNames="sno" Width="1000px" Style="margin-right: 528px" OnRowDataBound="GridView1_RowDataBound"
                            AllowPaging="True" PageSize="20" GridLines="Vertical"
                            OnRowCreated="GridView1_RowCreated">
                            <Columns>
                                <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" ShowSelectButton="True" />
                                <asp:TemplateField HeaderText="选择">
                                    <ItemTemplate>
                                        <asp:LinkButton ID="select" runat="server" Text="选择" />
                                    </ItemTemplate>
                                </asp:TemplateField>
                                <asp:TemplateField HeaderText="编号">
                                    <ItemTemplate>
                                        <asp:Label ID="Lable2" runat="server" Text="" />
                                        <asp:Label ID="Lable3" runat="server" Text="|" />
                                        <asp:Label ID="Lable4" runat="server" Text="" />
                                    </ItemTemplate>
                                </asp:TemplateField>
                                <asp:BoundField DataField="sno" HeaderText="姓名" InsertVisible="False" SortExpression="sno" />
                                <asp:BoundField DataField="sname" HeaderText="性别" SortExpression="sname" />
                                <asp:BoundField DataField="ssex" HeaderText="年龄" SortExpression="ssex" />
                                <asp:BoundField DataField="sage" HeaderText="职务" SortExpression="sage" />
                                <asp:BoundField DataField="stitle" HeaderText="所属部门" SortExpression="stitle" />
                                <asp:BoundField DataField="sdept" HeaderText="聘用时间" SortExpression="sdept" />
                                <asp:BoundField DataField="sdate" HeaderText="" SortExpression="sdate" />
                                <asp:ButtonField Visible="false" />
                                <asp:TemplateField HeaderText="">
                                    <ItemTemplate>
                                        <asp:Label ID="Lable1" runat="server" Text=""></asp:Label>
                                        <asp:Button ID="Button1" runat="server" Text="..." />
                                    </ItemTemplate>
                                </asp:TemplateField>
                                <asp:CommandField ShowInsertButton="True" />
                                <asp:CommandField ShowEditButton="True" />
                                <asp:CommandField ShowDeleteButton="true" />



                            </Columns>
                        </asp:GridView>


                        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=localhost;database=employee;uid=root;password=51272162zjx" ProviderName="MySql.Data.MySqlClient"
                            DeleteCommand="DELETE FROM employee WHERE sno = ?;"
                            InsertCommand="INSERT INTO employee (sno, sname, ssex, sage, stitle, sdept, sdate) VALUES (?, ?, ?, ?, ?, ?, ?);"
                            SelectCommand="SELECT * FROM employee;"
                            UpdateCommand="UPDATE employee SET sname=?, ssex=?, sage=?, stitle=?, sdept=?, sdate=? WHERE sno = ?;">

                            <SelectParameters>
                                <asp:ControlParameter ControlID="GridView1" PropertyName="SelectedValue"
                                    Name="sno" Type="Char" DefaultValue="0" />

                            </SelectParameters>

                            <DeleteParameters>
                                <asp:Parameter Name="sno" Type="Int32" DefaultValue="1" />
                            </DeleteParameters>

                            <UpdateParameters>
                                <asp:Parameter Name="sno" Type="Char" />
                                <asp:Parameter Name="sname" Type="Char" DefaultValue="1" />
                                <asp:Parameter Name="ssex" Type="Char" DefaultValue="1" />
                                <asp:Parameter Name="sage" Type="Int32" DefaultValue="1" />
                                <asp:Parameter Name="stitle" Type="Char" DefaultValue="1" />
                                <asp:Parameter Name="sdept" Type="Char" DefaultValue="1" />
                                <asp:Parameter Name="sname" Type="Char" DefaultValue="1" />
                            </UpdateParameters>

                            <InsertParameters>
                                <asp:Parameter Name="sno" Type="Char" />
                                <asp:Parameter Name="sname" Type="Char" DefaultValue="1" />
                                <asp:Parameter Name="ssex" Type="Char" DefaultValue="1" />
                                <asp:Parameter Name="sage" Type="Int32" DefaultValue="1" />
                                <asp:Parameter Name="stitle" Type="Char" DefaultValue="1" />
                                <asp:Parameter Name="sdept" Type="Char" DefaultValue="1" />
                                <asp:Parameter Name="sname" Type="Char" DefaultValue="1" />
                            </InsertParameters>
                        </asp:SqlDataSource>
                    </td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
