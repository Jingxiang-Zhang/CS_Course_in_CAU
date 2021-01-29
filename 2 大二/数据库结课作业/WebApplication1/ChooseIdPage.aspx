<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ChooseIdPage.aspx.cs" Inherits="WebApplication1.ChooseIdPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body  style="background:#FFFFF3;"><center>
    <form id="form1" runat="server">
        <div>

            <hr />
            <br />
            <br />
            <br />
            <br />
            <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="~/img/choice1.png" OnClick ="Patient_Click"/>
&nbsp;&nbsp;&nbsp;
            <asp:ImageButton ID="ImageButton2" runat="server" ImageUrl="~/img/choice2.png" OnClick ="Doctor_Click"/>

            <br />
            <br />
            <br />
            <br />
            <br />
            <hr />

        </div>
    </form></center>
</body>
</html>
