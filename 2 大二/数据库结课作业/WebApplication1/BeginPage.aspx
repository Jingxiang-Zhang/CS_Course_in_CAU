<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="BeginPage.aspx.cs" Inherits="WebApplication1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="background:#FFFFF3;">
    <form id="form1" runat="server">
        <p>
            <center><asp:Label ID="Label4" runat="server" Text="登陆访问预约"></asp:Label>
        </p>
        <p>
            <asp:Label ID="account" runat="server" Text="账号"></asp:Label>
            <asp:TextBox ID="account_TextBox1" runat="server"></asp:TextBox>
        </p>
                <p>
                    <asp:Literal ID="remind_info" runat="server"></asp:Literal>
        </p>
        <asp:Label ID="password" runat="server" Text="密码"></asp:Label>
                <input id="password_TextBox2" type="password" name ="pa"/><br />
        <br />
        <br />
        <asp:LinkButton ID="register" runat="server" OnClick ="register_Click">登陆</asp:LinkButton>

                &nbsp;&nbsp;&nbsp;

                <asp:LinkButton ID="register_new" runat="server" OnClick ="new_register_Click">注册新用户</asp:LinkButton>
    </form>
</body></center>
</html>
