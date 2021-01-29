<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="NewRegisterPage.aspx.cs" Inherits="WebApplication1.new_register" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style2 {
            margin-left: 18px;
        }
        .auto-style3 {
            margin-left: 15px;
        }
        .auto-style4 {
            margin-left: 0px;
        }
        .auto-style5 {
            margin-right: 0px;
            margin-bottom: 0px;
        }
    </style>
</head>
<center>
<body style="margin-left: 0px; width: 1289px; margin-right: 4px; margin-bottom: 17px;background:#FFFFF3;" >
    <form id="form1" runat="server" class="auto-style5">
        <div class="auto-style4">

            <hr />
            <br />

            <asp:Label ID="Label1" runat="server" Text="注册界面"></asp:Label>

            <br />
            <hr />

            <br />

        </div>
    <asp:Label ID="用户名" runat="server" Text="用户名"></asp:Label>
    <asp:TextBox ID="re_account" runat="server" CssClass="auto-style2"></asp:TextBox>
        <br />
        <br />
        <asp:Literal ID="remind_info" runat="server"></asp:Literal>
        <p>
            <asp:Label ID="输入密码" runat="server" Text="输入密码"></asp:Label>
            <input id="pw" type="password" /></p>
        <p>
            <asp:Label ID="确认密码" runat="server" Text="确认密码"></asp:Label>
            <input id="re_password" type="password" name ="re_pa"/></p>
        <p>
            <asp:Label ID="手机号" runat="server" Text="手机号"></asp:Label>
            <asp:TextBox ID="ph_num" runat="server" CssClass="auto-style3"></asp:TextBox>
        </p>
        <p>
            <asp:Label ID="re_remind" runat="server" Text="（用于找回密码）"></asp:Label>
        </p>
        <asp:LinkButton ID="注册" runat="server" OnClick ="already_register">注册</asp:LinkButton>
        <hr />
    </form>
    </body></center>
</html>
