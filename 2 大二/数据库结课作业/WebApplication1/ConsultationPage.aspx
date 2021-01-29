<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ConsultationPage.aspx.cs" Inherits="WebApplication1.ConsultationPage" %>

<%@ Register assembly="System.Web.DataVisualization, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35" namespace="System.Web.UI.DataVisualization.Charting" tagprefix="asp" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="background:#FFFFF3;">
    <center>

    <form id="form1" runat="server">
        <div>

            <hr />
            <br />
            <br />

            医生序号&lt;<asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>&gt;正在坐诊。

            <br />

            <br />

            <asp:Label ID="time" runat="server" Text="time"></asp:Label>
            <br />
            <br />

            <br />

            <asp:Label ID="PatientSituation" runat="server" Text="Label"></asp:Label>

            <br />
            <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource1" BackColor="White" BorderColor="#DEDFDE" BorderStyle="None" BorderWidth="1px" CellPadding="4" ForeColor="Black" GridLines="Vertical">
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:BoundField DataField="Pno" HeaderText="Pno" SortExpression="Pno" />
                    <asp:BoundField DataField="Dno" HeaderText="Dno" SortExpression="Dno" />
                    <asp:BoundField DataField="DueTime" HeaderText="DueTime" SortExpression="DueTime" />
                </Columns>
                <FooterStyle BackColor="#CCCC99" />
                <HeaderStyle BackColor="#6B696B" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#F7F7DE" ForeColor="Black" HorizontalAlign="Right" />
                <RowStyle BackColor="#F7F7DE" />
                <SelectedRowStyle BackColor="#CE5D5A" Font-Bold="True" ForeColor="White" />
                <SortedAscendingCellStyle BackColor="#FBFBF2" />
                <SortedAscendingHeaderStyle BackColor="#848384" />
                <SortedDescendingCellStyle BackColor="#EAEAD3" />
                <SortedDescendingHeaderStyle BackColor="#575357" />
            </asp:GridView>
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:hospitalConnectionString2 %>" SelectCommand="SELECT TOP (1)  derivedtbl_1.Pno, derivedtbl_1.Dno,derivedtbl_1.DueTime FROM (SELECT TOP (100) PERCENT patient.Pno, patient.Dno, patient.DueTime FROM patient,arrive,consultation WHERE ( patient.Dno = @Dno AND arrive.Cdate = @time AND patient.Dno = arrive.Dno AND patient.Pno = arrive.Pno AND patient.Pno = consultation.Vno AND patient.Dno = consultation.Dno AND consultation.Vregister = 0) ORDER BY arrive.Cdate) AS derivedtbl_1
">
                <SelectParameters>
                    <asp:ControlParameter ControlID="Label1" Name="Dno" PropertyName="Text" />
                    <asp:ControlParameter ControlID="time" Name="time" PropertyName="Text" />
                </SelectParameters>
            </asp:SqlDataSource>

            <hr />

            <br />
            <asp:Label ID="SymptonLabel" runat="server" Text="症状描述："></asp:Label>
            <br />
            <asp:TextBox ID="SymptonBox" runat="server" Height="55px" Width="191px" BorderStyle="Groove" Rows="5" TextMode="MultiLine"></asp:TextBox>
            <br />
            <br />
            <hr />
            <br />
            <asp:Label ID="Label2" runat="server" Text="添加药品："></asp:Label>
            <asp:DropDownList ID="DropDownList1" runat="server" DataSourceID="SqlDataSource2" DataTextField="Mname" DataValueField="Mname">
            </asp:DropDownList>
            &nbsp;数量<asp:DropDownList ID="DropDownList2" runat="server">
                <asp:ListItem Value="0"></asp:ListItem>
                <asp:ListItem Value="1"></asp:ListItem>
                <asp:ListItem Value="2"></asp:ListItem>
                <asp:ListItem Value="3"></asp:ListItem>
                <asp:ListItem Value="4"></asp:ListItem>
                <asp:ListItem Value="5"></asp:ListItem>
                <asp:ListItem Value="6"></asp:ListItem>
                <asp:ListItem Value="7"></asp:ListItem>
                <asp:ListItem Value="8"></asp:ListItem>
                <asp:ListItem Value="9"></asp:ListItem>
                <asp:ListItem Value="10"></asp:ListItem>
                <asp:ListItem Value="11"></asp:ListItem>
                <asp:ListItem Value="12"></asp:ListItem>
                <asp:ListItem Value="13"></asp:ListItem>
                <asp:ListItem Value="14"></asp:ListItem>
                <asp:ListItem Value="15"></asp:ListItem>
                <asp:ListItem Value="16"></asp:ListItem>
                <asp:ListItem Value="17"></asp:ListItem>
                <asp:ListItem Value="18"></asp:ListItem>
                <asp:ListItem Value="19"></asp:ListItem>
                <asp:ListItem Value="20"></asp:ListItem>
            </asp:DropDownList>
            &nbsp;<br />
            <br />
            <asp:Button ID="Button1" runat="server" Text="添加" OnClick ="Add1_Medicine_Click"/>
            &nbsp;<asp:Literal ID="Literal1" runat="server"></asp:Literal>
&nbsp; <asp:Button ID="Button2" runat="server" Text="删除" OnClick ="Delete1_Medicine_Click"/>
            &nbsp;
            <asp:Literal ID="Literal2" runat="server"></asp:Literal>
            <br />
            <br />
            <asp:Label ID="Label3" runat="server" Text="手动搜索："></asp:Label>
            <asp:TextBox ID="ManualSearchBox" runat="server"></asp:TextBox>
            &nbsp;<asp:Button ID="ManualSearchButton" runat="server" Text="确定" />
            (搜索全称或关键词)<br />
            <br />
            <br />
            <asp:Label ID="Label4" runat="server" Text="搜索结果："></asp:Label>
            <asp:DropDownList ID="DropDownList4" runat="server" DataSourceID="SqlDataSource4" DataTextField="Mname" DataValueField="Mname" Height="20px" Width="80px">
            </asp:DropDownList>
            &nbsp; 数量<asp:DropDownList ID="DropDownList3" runat="server">
                <asp:ListItem Value="0"></asp:ListItem>
                <asp:ListItem Value="1"></asp:ListItem>
                <asp:ListItem Value="2"></asp:ListItem>
                <asp:ListItem Value="3"></asp:ListItem>
                <asp:ListItem Value="4"></asp:ListItem>
                <asp:ListItem Value="5"></asp:ListItem>
                <asp:ListItem Value="6"></asp:ListItem>
                <asp:ListItem Value="7"></asp:ListItem>
                <asp:ListItem Value="8"></asp:ListItem>
                <asp:ListItem Value="9"></asp:ListItem>
                <asp:ListItem Value="10"></asp:ListItem>
                <asp:ListItem Value="11"></asp:ListItem>
                <asp:ListItem Value="12"></asp:ListItem>
                <asp:ListItem Value="13"></asp:ListItem>
                <asp:ListItem Value="14"></asp:ListItem>
                <asp:ListItem Value="15"></asp:ListItem>
                <asp:ListItem Value="16"></asp:ListItem>
                <asp:ListItem Value="17"></asp:ListItem>
                <asp:ListItem Value="18"></asp:ListItem>
                <asp:ListItem Value="19"></asp:ListItem>
                <asp:ListItem Value="20"></asp:ListItem>
            </asp:DropDownList>
            &nbsp;<asp:SqlDataSource ID="SqlDataSource4" runat="server" ConnectionString="<%$ ConnectionStrings:hospitalConnectionString2 %>" SelectCommand="SELECT DISTINCT [Mname] FROM [medicine] WHERE ([Mname] LIKE '%' + @Mname + '%')">
                <SelectParameters>
                    <asp:ControlParameter ControlID="ManualSearchBox" Name="Mname" PropertyName="Text" Type="String" />
                </SelectParameters>
            </asp:SqlDataSource>
            <br />
            <br />
            <asp:Button ID="Button3" runat="server" Text="添加" OnClick="Add2_Medicine_Click" />
            &nbsp;
            <asp:Literal ID="Literal3" runat="server"></asp:Literal>
            &nbsp;<asp:Button ID="Button4" runat="server" Text="删除" OnClick ="Delete2_Medicine_Click"/>
            &nbsp;
            <asp:Literal ID="Literal4" runat="server"></asp:Literal>
            <br />

            <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:hospitalConnectionString2 %>" SelectCommand="SELECT [Mname] FROM [medicine]"></asp:SqlDataSource>

            <br />

            <hr />

            当前病人<asp:Label ID="nowPno" runat="server" Text=""></asp:Label>处方：<br />
            <asp:GridView ID="GridView2" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource3" BackColor="#CCCCCC" BorderColor="#999999" BorderStyle="Solid" BorderWidth="3px" CellPadding="4" CellSpacing="2" ForeColor="Black">
                <Columns>
                    <asp:BoundField DataField="PNO" HeaderText="PNO" SortExpression="PNO" />
                    <asp:BoundField DataField="DNO" HeaderText="DNO" SortExpression="DNO" />
                    <asp:BoundField DataField="MNAME" HeaderText="MNAME" SortExpression="MNAME" />
                    <asp:BoundField DataField="MAMOUNT" HeaderText="MAMOUNT" SortExpression="MAMOUNT" />
                </Columns>
                <FooterStyle BackColor="#CCCCCC" />
                <HeaderStyle BackColor="Black" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#CCCCCC" ForeColor="Black" HorizontalAlign="Left" />
                <RowStyle BackColor="White" />
                <SelectedRowStyle BackColor="#000099" Font-Bold="True" ForeColor="White" />
                <SortedAscendingCellStyle BackColor="#F1F1F1" />
                <SortedAscendingHeaderStyle BackColor="#808080" />
                <SortedDescendingCellStyle BackColor="#CAC9C9" />
                <SortedDescendingHeaderStyle BackColor="#383838" />
            </asp:GridView>
            <hr />
            <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:hospitalConnectionString2 %>" SelectCommand="SELECT PATIENTCHART.PNO,PATIENTCHART.DNO,MEDICINE.MNAME,PATIENTCHART.MAMOUNT FROM PATIENTCHART,MEDICINE WHERE PATIENTCHART.MNO = MEDICINE.MNO AND PNO = @PNO AND DNO = @DNO">
                <SelectParameters>
                    <asp:ControlParameter ControlID="nowPno" Name="PNO" PropertyName="Text" Type="String" />
                    <asp:ControlParameter ControlID="Label1" Name="DNO" PropertyName="Text" Type="Int32" />
                </SelectParameters>
            </asp:SqlDataSource>

            <br />

            <br />
            <asp:LinkButton ID="LinkButton3" runat="server" OnClick ="Prescription_Click">开具当前处方</asp:LinkButton>
&nbsp;&nbsp;&nbsp;
            <asp:LinkButton ID="LinkButton1" runat="server" OnClick ="Page_Load">叫号</asp:LinkButton>
&nbsp;&nbsp;&nbsp;
            <asp:LinkButton ID="LinkButton2" runat="server">结束坐诊</asp:LinkButton>

            <br />

            <br />
            <br />
            <hr />

        </div>
    </form>

    </center>
</body>
</html>
