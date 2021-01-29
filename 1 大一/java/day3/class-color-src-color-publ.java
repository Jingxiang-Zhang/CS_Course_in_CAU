/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package color;
import java.awt.Graphics;
import java.awt.Color;


public class publ {
    protected int x,y;
    protected int size;
    protected java.awt.Color bcolor=java.awt.Color.BLACK,fcolor=java.awt.Color.blue;
      public publ(){
    }
    public publ(int x,int y,int size,Color c,Color d ){
        this(x,y,size);
        this.fcolor=c;
        this.bcolor=d;
    }
    public publ(int x,int y,int size){
        this.x=x;
        this.y=y;
        this.size=size;
    }
    public void draw(Graphics g) {     
    }
}
