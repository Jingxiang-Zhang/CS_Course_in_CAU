<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="PayPage.aspx.cs" Inherits="WebApplication1.paypage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="background:#FFFFF3;"><center>
    <form id="form1" runat="server">
        <div>
            <hr />
            <br />
            <asp:Label ID="Label1" runat="server" Text="扫码完成网上付费"></asp:Label>
            <br />
            <br />
            <hr />
            <br />
            <br />
            <asp:Image ID="Image1" runat="server" imageUrl ="~/img/cau.png"/>
            <br />
            <br />
            <hr />
            <br />
            <asp:Literal ID="Literal1" runat="server"></asp:Literal>
            <br />
            <asp:LinkButton ID="LinkButton1" runat="server" OnClick="already_pay_Click">完成支付</asp:LinkButton>
            <br />
            <br />
            <hr />
        </div>
    </form></center>
</body>
</html>
