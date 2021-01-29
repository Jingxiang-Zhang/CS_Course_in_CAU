<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WaitPage.aspx.cs" Inherits="WebApplication1.waitpage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head><center>
<body style="background:#FFFFF3;">
    <form id="form1" runat="server">
        <div>
            
            <hr />
            
            <asp:Button ID="Button1" runat="server" Text="登记" OnClick ="Arrive_Click"/>
            <br />
            <asp:Literal ID="Literal2" runat="server"></asp:Literal>
            <br />
            （请到达候诊大厅后登记！）<br />
            
            <asp:Literal ID="Literal1" runat="server"></asp:Literal>
            <hr />
        </div>
            <br />

            <asp:LinkButton ID="LinkButton2" runat="server" OnCLick ="pay_Click">网上付费</asp:LinkButton> 
       
            &nbsp;&nbsp;&nbsp; 
       
            <asp:LinkButton ID="LinkButton1" runat="server" OnCLick ="return_Click">返回登陆</asp:LinkButton>
       
        <br />
        <hr />
       
    </form>
</body> </center>
</html>
