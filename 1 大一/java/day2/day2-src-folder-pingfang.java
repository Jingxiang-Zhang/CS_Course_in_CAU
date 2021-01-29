package folder;

public class pingfang 
{
    public double sqrt,a;
    public pingfang(int x){a=x;};
    public pingfang(){};
    public pingfang(int x,int y)
    { 
        this(2);
    }
    public double sqrt(double x)
    {
        return Math.sqrt(x);
    }
    public double sqrt()
    {
        return Math.sqrt(a);
    }
}

class circle extends pingfang
{
    public circle()
    {
        
    }
     public double sqrt(double x)
    {
        return Math.sqrt(x);
    }
}

