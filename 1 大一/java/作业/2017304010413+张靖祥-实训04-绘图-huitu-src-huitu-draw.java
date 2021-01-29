package huitu;

import java.awt.*;

public class draw extends Frame {

    public draw() {

    }

    public static void main(String[] args) {
        draw java_draw = new draw();
        java_draw.setSize(1000, 600);
        java_draw.setVisible(true);
    }

    @Override
    public void paint(Graphics g) {
        rectangualr rect11 = new rectangualr(20, 20, new Color(255, 255, 0), new Color(34, 139, 34));
        rect11.draw(g, 120);
        rectangualr rect12 = new rectangualr(860, 20, new Color(255, 255, 0), new Color(34, 139, 34));
        rect12.draw(g, 120);
        rectangualr rect13 = new rectangualr(20, 460, new Color(255, 255, 0), new Color(199, 21, 133));
        rect13.draw(g, 120);
        rectangualr rect14 = new rectangualr(860, 460, new Color(255, 255, 0), new Color(199, 21, 133));
        rect14.draw(g, 120);

        rectangualr rect21 = new rectangualr(20, 200, new Color(255, 0, 0), new Color(255, 255, 255));
        rect21.draw(g, 80);
        rectangualr rect22 = new rectangualr(45, 225, new Color(255, 0, 0), new Color(255, 0, 0));
        rect22.draw(g, 80);
        rectangualr rect23 = new rectangualr(70, 250, new Color(255, 0, 0), new Color(0, 0, 255));
        rect23.draw(g, 80);
        rectangualr rect24 = new rectangualr(95, 275, new Color(255, 0, 0), new Color(0, 255, 0));
        rect24.draw(g, 80);

        rectangualr rect31 = new rectangualr(825, 200, new Color(255, 0, 0), new Color(255, 255, 255));
        rect31.draw(g, 80);
        rectangualr rect32 = new rectangualr(850, 225, new Color(255, 0, 0), new Color(255, 0, 0));
        rect32.draw(g, 80);
        rectangualr rect33 = new rectangualr(875, 250, new Color(255, 0, 0), new Color(0, 0, 255));
        rect33.draw(g, 80);
        rectangualr rect34 = new rectangualr(900, 275, new Color(255, 0, 0), new Color(0, 255, 0));
        rect34.draw(g, 80);

        oval ov0 = new oval(310, 50, new Color(255, 255, 0), new Color(255, 0, 0));
        ov0.draw(g, 400, 520);

        oval ov110 = new oval(305, 50, new Color(255, 255, 0), new Color(255, 20, 147));
        ov110.draw(g, 80, 80);
        oval ov111 = new oval(635, 50, new Color(255, 255, 0), new Color(255, 20, 147));
        ov111.draw(g, 80, 80);

        oval ov120 = new oval(263, 120, new Color(255, 255, 0), new Color(34, 139, 34));
        ov120.draw(g, 80, 80);
        oval ov121 = new oval(677, 120, new Color(255, 255, 0), new Color(34, 139, 34));
        ov121.draw(g, 80, 80);

        oval ov130 = new oval(238, 195, new Color(255, 255, 0), new Color(0, 0, 205));
        ov130.draw(g, 80, 80);
        oval ov131 = new oval(702, 195, new Color(255, 255, 0), new Color(0, 0, 205));
        ov131.draw(g, 80, 80);

        oval ov140 = new oval(230, 275, new Color(255, 255, 0), new Color(255, 215, 0));
        ov140.draw(g, 80, 80);
        oval ov141 = new oval(710, 275, new Color(255, 255, 0), new Color(255, 215, 0));
        ov141.draw(g, 80, 80);
        
        oval ov150 = new oval(238, 355, new Color(255, 255, 0), new Color(255,140,0));
        ov150.draw(g, 80, 80);
        oval ov151 = new oval(702, 355, new Color(255, 255, 0), new Color(255,140,0));
        ov151.draw(g, 80, 80);
        
        oval ov160 = new oval(263, 430, new Color(255, 255, 0), new Color( 30,144,255 ));
        ov160.draw(g, 80, 80);
        oval ov161 = new oval(677, 430, new Color(255, 255, 0), new Color( 30,144,255 ));
        ov161.draw(g, 80, 80);
        
        oval ov170 = new oval(310, 497, new Color(255, 255, 0), new Color(199, 21, 133));
        ov170.draw(g, 80, 80);
        oval ov171 = new oval(630, 497, new Color(255, 255, 0), new Color(199, 21, 133));
        ov171.draw(g, 80, 80);
        
    }
}
