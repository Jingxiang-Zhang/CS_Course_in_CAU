<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="AppointmentPage.aspx.cs" Inherits="WebApplication1.appointment" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<center>
<body style="background:#FFFFF3;">
    <form id="form1" runat="server">
        <asp:Label ID="Label1" runat="server" Text="预约" BorderStyle="Dashed" Font-Italic="False" Font-Names="Arial" Font-Size="30pt" Font-Strikeout="False" Font-Underline="True" ForeColor="Red" Width="160px" BackColor="White"></asp:Label>
        <br />
        <hr />
        <br />
        
        <asp:Label ID="Label2" runat="server" Text="预约科室：" Height="20px" Font-Size="15pt" Width="100px"></asp:Label>
        <asp:DropDownList ID="DropDownList1" runat="server" DataSourceID="SqlDataSource1" DataTextField="Doffice" DataValueField="Doffice" AutoPostBack="True" Height="30px" Width="50px">
        </asp:DropDownList>
        
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:hospitalConnectionString2 %>" SelectCommand="SELECT DISTINCT [Doffice] FROM [doctors]" OnSelecting="SqlDataSource1_Selecting"></asp:SqlDataSource>
        
        <asp:Label ID="Label3" runat="server" Text="预约大夫：" Height="20px" Font-Size="15pt" Width="100px"></asp:Label>
        <asp:DropDownList ID="DropDownList2" runat="server" DataSourceID="SqlDataSource2" DataTextField="Dname" DataValueField="Dname" Height="30px" Width="60px">
        </asp:DropDownList>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:hospitalConnectionString2 %>" SelectCommand="SELECT DISTINCT [Dname] FROM [doctors] WHERE ([Doffice] = @Doffice2)">
            <SelectParameters>
                <asp:FormParameter FormField="DropDownList1" Name="Doffice2" Type="String" DefaultValue="儿科" />
            </SelectParameters>
        </asp:SqlDataSource>
        <asp:EntityDataSource ID="EntityDataSource1" runat="server" DefaultContainerName="儿科" OnSelecting="EntityDataSource1_Selecting">
        </asp:EntityDataSource>
        <br />
        
        <asp:Label ID="Label6" runat="server" Text="患者姓名：" Height="20px" Font-Size="15pt" Width="100px"></asp:Label>
        <asp:TextBox ID="TextBox1" runat="server" Width="180px"></asp:TextBox>
        *<br />
        
        <asp:Label ID="Label8" runat="server" Text="性别：" Height="20px" Font-Size="15pt" Width="100px"></asp:Label>
        <asp:DropDownList ID="DropDownList3" runat="server" Width="60px">
            <asp:ListItem  Value="1">男</asp:ListItem>
            <asp:ListItem  Value="0">女</asp:ListItem>
        </asp:DropDownList>
        *&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <br />
        
        <asp:Label ID="Label7" runat="server" Text="身份证号：" Height="20px" Font-Size="15pt" Width="100px"></asp:Label>
        <asp:TextBox ID="TextBox5" runat="server" Width="180px"></asp:TextBox>
        *<br />
        
        <asp:Label ID="Label9" runat="server" Text="电话：" Height="20px" Font-Size="15pt" Width="100px"></asp:Label>
        <asp:TextBox ID="TextBox4" runat="server" Width="180px"></asp:TextBox>
        *<br />
        
        &nbsp;<asp:Label ID="Label10" runat="server" Text="家庭住址：" Height="20px" Font-Size="15pt" Width="100px"></asp:Label>
        <asp:TextBox ID="TextBox6" runat="server" Width="180px"></asp:TextBox>
        &nbsp;&nbsp;
        <br />
        （带有*标记为必填项）<asp:Literal ID="Literal1" runat="server"></asp:Literal>
        <br />
        
        <hr />
        <asp:Label ID="Label4" runat="server" Text="预约时间：" Height="20px"></asp:Label>
        
        &nbsp;
                    
        <br />
        <div>
            <br />
            <asp:Calendar ID="Calendar1" runat="server" BackColor="White" BorderColor="#3366CC" BorderWidth="1px" CellPadding="1" DayNameFormat="Shortest" Font-Names="Verdana" Font-Size="8pt" ForeColor="#003399" Height="200px" Width="324px" >
                <DayHeaderStyle BackColor="#99CCCC" ForeColor="#336666" Height="1px" />
                <NextPrevStyle Font-Size="8pt" ForeColor="#CCCCFF" />
                <OtherMonthDayStyle ForeColor="#999999" />
                <SelectedDayStyle BackColor="#009999" Font-Bold="True" ForeColor="#CCFF99" />
                <SelectorStyle BackColor="#99CCCC" ForeColor="#336666" />
                <TitleStyle BackColor="#003399" BorderColor="#3366CC" BorderWidth="1px" Font-Bold="True" Font-Size="10pt" ForeColor="#CCCCFF" Height="25px" />
                <TodayDayStyle BackColor="#99CCCC" ForeColor="White" />
                <WeekendDayStyle BackColor="#CCCCFF" />
            </asp:Calendar>
            <br />
            <asp:ImageButton ID="ImageButton1" runat="server" Width="80px" ImageUrl="~/img/btn2.jpg" Onclick ="Button1_Click" Height="30px" ForeColor="Red"/>
        
            <br />
            <br />
            <hr />
            <br />
            <br />
            <hr />
   
            <br />
        
        </div>
    </form>
</body></center>
</html>
