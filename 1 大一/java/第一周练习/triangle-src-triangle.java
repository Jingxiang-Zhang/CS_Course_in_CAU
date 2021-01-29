import java.awt.Frame;
import java.awt.Graphics;


public class triangle extends Frame{
    triangle_class ang=new triangle_class(200,200,200);
    triangle_class ang2=new triangle_class(0,0,300,0,0,300);
    triangle_class ang3=new triangle_class(200,300);
    
    public static void main(String[] args) {
        triangle tr=new triangle();
        tr.setVisible(true);
        tr.setSize(400, 400);
     
    }
    @Override
    public void paint(Graphics g){
         
        ang.draw(g);
        System.out.println("The Circonference of the triangle is "+ang.get_Circomference());
        System.out.println("The Area of the triangle is "+ang.get_Area());
        
        
}
}