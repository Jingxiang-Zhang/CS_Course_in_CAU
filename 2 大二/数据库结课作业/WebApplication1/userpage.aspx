<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="userpage.aspx.cs" Inherits="WebApplication1.userpage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>用户信息</title>
</head>

<body style=" background:#FFFFF3;">
    <form id="form1" runat="server" aligh="center">
   
        <%
            string yonghuxingming = get_yonghuxingming();
            string shifoukanwanbing = get_shifoukanwanbing();
            string[] jiuzhendanhao = new string[100];
            string[] shifouyuyue = new string[100];
            string[] shifouguahao = new string[100];
            string[] jiuzhenriqi = new string[100];
            string[] shifoujiaofei = new string[100];
            int length = tableresult(jiuzhendanhao, shifouyuyue, shifouguahao, jiuzhenriqi, shifoujiaofei);
        %>
        <h3 align="center">您好，亲爱的<%=yonghuxingming%>用户</h3>
        <div>
        <h3 align="center">请选择预约挂号的时间</h3>
        <table  border="0" align="center" style="width:700px; font-size:20px;"  >
            <tr style="height:300px">
                <td style="width:200px"></td>
                <td>
                    <asp:Calendar ID="Calendar1" runat="server"  >
                        <DayStyle BorderColor="Fuchsia" />
                    </asp:Calendar>
                </td>
            </tr>
        </table>
        <h3 align="center"><asp:Button ID="Button1" runat="server" Text="预约" OnClick="Button1_Click" /></h3>

        <h3 align="center">您的最近一次记录如下</h3>
        <table  border="1" align="center" style="width:600px; font-size:20px; height: 60px;"  >
           <tr>
               <td style="width:20%">就诊单号</td>
               <td style="width:15%">是否预约</td>
               <td style="width:15%">是否挂号</td>
               <td style="width:35%">就诊日期</td>
               <td style="width:15%">是否缴费</td>
            </tr>
            <% if(length!=0){ %>
            <tr style="height:80px">
                    <td><%=jiuzhendanhao[length-1] %></td> 
                    <td><%=shifouyuyue[length-1] %></td>
                    <%if (shifouguahao[length-1] != "N" ){ %>
                        <td><p>是</p></td>
                    <%} else { %>
                        <td><p>否</p></td>
                    <%} %>
           
                   <td><%=jiuzhenriqi[length-1] %></td>

                    <%if (shifoujiaofei[length-1] != "N" ){%>
                        <td><p>是</p></td>
                    <%} else { %>
                        <td><p>否</p></td>
                    <%} %>
            </tr>
            <%} %>
        </table>

     <% if(length!=0){ %>
        <%if(shifouguahao[length-1]=="N"){ %>
             <h3 align="center"><asp:Button ID="Button2" runat="server" Text="挂号" OnClick="guahao_Click" Height="27px" Width="50px" /></h3>
         <%} %>
         <%if(shifouguahao[length-1]=="Y" &&shifoukanwanbing=="N" ){ %>
             <h3 align="center">医生正在看病，请耐心等待</h3>
         <%} %>
         <%if(shifouguahao[length-1]=="Y" &&shifoukanwanbing=="Y" && shifoujiaofei[length-1]=="N"){ %>
             <h3 align="center"><asp:Button ID="Button2_Click" runat="server" Text="缴费" OnClick="jiaofei_Click" Height="27px" Width="50px" /></h3>
         <%} %>
    <%} %>
        <h3 align="center">您的历史记录如下</h3>
        <table  border="1" align="center" style="width:600px; font-size:20px; height: 60px;"  >
           <tr>
               <td style="width:20%">就诊单号</td>
               <td style="width:15%">是否预约</td>
               <td style="width:15%">是否挂号</td>
               <td style="width:35%">就诊日期</td>
               <td style="width:15%">是否缴费</td>
            </tr>
                <% for (int i = 0; i < length - 1; i++)
                {    %>
            <tr style="height:80px">
                    <td><%=jiuzhendanhao[i] %></td> 
                    <td><%=shifouyuyue[i] %></td>
                    <%if (shifouguahao[i] != "N")
                { %>
                        <td><p>是</p></td>
                    <%}
                else
                { %>
                        <td><p>否</p></td>
                    <%} %>
           
                   <td><%=jiuzhenriqi[i] %></td>

                    <%if (shifoujiaofei[i] != "N")
                {%>
                        <td><p>是</p></td>
                    <%}
                else
                { %>
                        <td><p>否</p></td>
                    <%} %>

            </tr>
               <% } %>
        </table>

 
        </div>
    </form>
</body>
</html>