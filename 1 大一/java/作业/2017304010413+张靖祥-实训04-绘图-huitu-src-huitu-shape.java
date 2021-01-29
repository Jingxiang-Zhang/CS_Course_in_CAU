 
package huitu;
import java.awt.Color;
 
public abstract class shape {
    public int X,Y;
    Color bian_color,nei_color;
    
    public shape(int X,int Y,Color bian_color,Color nei_color){
        this.X=X;this.Y=Y;
        this.bian_color=bian_color;
        this.nei_color=nei_color;
    }
}
