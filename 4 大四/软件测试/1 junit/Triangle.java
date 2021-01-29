package test;

public class Triangle {	
	public String triJudge(int a,int b,int c)
	{
		if(a<=0||b<=0||c<=0||a+b<=c||a+c<=b||b+c<=a) 
			return "不是三角形";
		if(a == b&&b == c) 
			return "等边三角形";
		else if(a == b||b == c) 
			return "等腰三角形";
		else 
			return "一般三角形";
	}
}


