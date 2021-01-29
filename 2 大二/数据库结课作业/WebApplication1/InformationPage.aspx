<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="InformationPage.aspx.cs" Inherits="WebApplication1.infomationpage" %>

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
            <br />
            <asp:Literal ID="Literal1" runat="server"></asp:Literal>
            <br />
            <br />
            <br />
            <asp:LinkButton ID="LinkButton1" runat="server" OnClick ="BackTo_Click">返回</asp:LinkButton>
            <br />
            <br />
            <hr />

        </div>
    </form></center>
</body>
</html>
