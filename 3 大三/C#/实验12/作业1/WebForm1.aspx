<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="作业1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
    <body>
        <form action="WebForm1.aspx" method="post">
			<h3>用户注册</h3>
            <p>
                姓 名：<input type="text" id="姓名" name="姓名">
            </p>
            <p>
                性 别：
                <input type="radio" name="gender" value="1">男
                <input type="radio" name="gender" value="2">女
            </p>
            <p>
                婚 否：
                <input type="radio" name="wed" value="1">已婚
                <input type="radio" name="wed" value="2">未婚
            </p>
			<p>
                个人爱好：
			    <input type="checkbox" name="gusto" value="1">运动 
                <input type="checkbox" name="gusto" value="2">游泳
			    <input type="checkbox" name="gusto" value="3">购物
                <input type="checkbox" name="gusto" value="4">音乐
			</p>
            <p>
                电 话：<input type="text" id="电话" name="telephone">
            </p>
            <p>
                地 址：<input type="text" id="地址" name="address">
            </p>
 			<p>
                <input type="submit" id="btnSub" name="btnSub" value="提交" > 
                <input type="reset" value="取消" name="B2" tabindex="9" id="Reset1">
			</p>
		</form>
        <%if (Getgender() != ""){ %>
        <div id="div1"></div>
        <style>
            #div1{
            argin-top: 100px;
            width: 900px;
            border-bottom: 1px solid #ff0000;
            }
        </style>
            姓名：<%=Getname() %>
        <br>
            性别：<%=Getgender() %>
        <br>
            婚否：<%=Getwed() %>
        <br>
            爱好：<%=Getgusto() %>
        <br>
            电话：<%=Gettel() %>
        <br>
            地址：<%=Getaddress() %>
        <%} %>
    </body>
</html>
