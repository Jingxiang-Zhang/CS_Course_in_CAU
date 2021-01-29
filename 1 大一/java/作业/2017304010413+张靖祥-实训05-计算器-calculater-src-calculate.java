
import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.script.*;

public class calculate extends Applet implements ActionListener {

    String biaodashi = new String();
    Label result = new Label(biaodashi);

    @Override
    public void init() {
        this.setSize(600, 600);
      
        setLayout(null);
        Button num1 = new Button("1");
        num1.setSize(70, 70);
        num1.setLocation(50, 400);
        num1.setBackground(new Color(245, 245, 245));
        num1.addActionListener(this);
        add(num1);
        Button num2 = new Button("2");
        num2.setSize(70, 70);
        num2.setLocation(140, 400);
        num2.setBackground(new Color(245, 245, 245));
        num2.addActionListener(this);
        add(num2);
        Button num3 = new Button("3");
        num3.setSize(70, 70);
        num3.setLocation(230, 400);
        num3.setBackground(new Color(245, 245, 245));
        num3.addActionListener(this);
        add(num3);
        Button num4 = new Button("4");
        num4.setSize(70, 70);
        num4.setLocation(50, 310);
        num4.setBackground(new Color(245, 245, 245));
        num4.addActionListener(this);
        add(num4);
        Button num5 = new Button("5");
        num5.setSize(70, 70);
        num5.setLocation(140, 310);
        num5.setBackground(new Color(245, 245, 245));
        num5.addActionListener(this);
        add(num5);
        Button num6 = new Button("6");
        num6.setSize(70, 70);
        num6.setLocation(230, 310);
        num6.setBackground(new Color(245, 245, 245));
        num6.addActionListener(this);
        add(num6);
        Button num7 = new Button("7");
        num7.setSize(70, 70);
        num7.setLocation(50, 220);
        num7.setBackground(new Color(245, 245, 245));
        num7.addActionListener(this);
        add(num7);
        Button num8 = new Button("8");
        num8.setSize(70, 70);
        num8.setLocation(140, 220);
        num8.setBackground(new Color(245, 245, 245));
        num8.addActionListener(this);
        add(num8);
        Button num9 = new Button("9");
        num9.setSize(70, 70);
        num9.setLocation(230, 220);
        num9.setBackground(new Color(245, 245, 245));
        num9.addActionListener(this);
        add(num9);
        Button num0 = new Button("0");
        num0.setSize(160, 70);
        num0.setLocation(50, 490);
        num0.setBackground(new Color(245, 245, 245));
        num0.addActionListener(this);
        add(num0);

        Button dot = new Button(".");
        dot.setSize(70, 70);
        dot.setLocation(230, 490);
        dot.setBackground(new Color(245, 245, 245));
        dot.addActionListener(this);
        add(dot);
        Button add = new Button("+");
        add.setSize(70, 70);
        add.setLocation(320, 490);
        add.setBackground(new Color(220, 220, 220));
        add.addActionListener(this);
        add(add);
        Button sub = new Button("-");
        sub.setSize(70, 70);
        sub.setLocation(320, 400);
        sub.setBackground(new Color(220, 220, 220));
        sub.addActionListener(this);
        add(sub);
        Button mul = new Button("*");
        mul.setSize(70, 70);
        mul.setLocation(320, 310);
        mul.setBackground(new Color(220, 220, 220));
        mul.addActionListener(this);
        add(mul);
        Button div = new Button("/");
        div.setSize(70, 70);
        div.setLocation(320, 220);
        div.setBackground(new Color(220, 220, 220));
        div.addActionListener(this);
        add(div);
        Button per = new Button("%");
        per.setSize(70, 70);
        per.setLocation(320, 130);
        per.setBackground(new Color(220, 220, 220));
        per.addActionListener(this);
        add(per);

        Button sum = new Button("=");
        sum.setSize(70, 160);
        sum.setLocation(410, 400);
        sum.setBackground(new Color(220, 220, 220));
        sum.addActionListener(this);
        add(sum);

        Button del = new Button("C");
        del.setSize(70, 70);
        del.setLocation(230, 130);
        del.setBackground(new Color(220, 220, 220));
        del.addActionListener(this);
        add(del);
        Button dela = new Button("CE");
        dela.setSize(70, 70);
        dela.setLocation(140, 130);
        dela.setBackground(new Color(220, 220, 220));
        dela.addActionListener(this);
        add(dela);
        Button tui = new Button("←");
        tui.setSize(70, 70);
        tui.setLocation(50, 130);
        tui.setBackground(new Color(220, 220, 220));
        tui.addActionListener(this);
        add(tui);

        result.setLocation(50, 20);
        result.setSize(430, 80);
        result.setAlignment(Label.RIGHT);
        result.setFont(new Font("宋体", 30, 30));
        add(result);
        result.setBackground(new Color(245, 245, 245));

    }

    @Override
    public void paint(Graphics g) {

        result.setText(biaodashi);
        result.repaint();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "1":
                biaodashi = biaodashi + "1";
                this.repaint();
                break;
            case "2":
                biaodashi = biaodashi + "2";
                this.repaint();
                break;
            case "3":
                biaodashi = biaodashi + "3";
                this.repaint();
                break;
            case "4":
                biaodashi = biaodashi + "4";
                this.repaint();
                break;
            case "5":
                biaodashi = biaodashi + "5";
                this.repaint();
                break;
            case "6":
                biaodashi = biaodashi + "6";
                this.repaint();
                break;
            case "7":
                biaodashi = biaodashi + "7";
                this.repaint();
                break;
            case "8":
                biaodashi = biaodashi + "8";
                this.repaint();
                break;
            case "9":
                biaodashi = biaodashi + "9";
                this.repaint();
                break;
            case "0":
                biaodashi = biaodashi + "0";
                this.repaint();
                break;
            case "+":
                biaodashi = biaodashi + "+";
                this.repaint();
                break;
            case "-":
                biaodashi = biaodashi + "-";
                this.repaint();
                break;
            case "*":
                biaodashi = biaodashi + "*";
                this.repaint();
                break;
            case "/":
                biaodashi = biaodashi + "/";
                this.repaint();
                break;
            case ".":
                biaodashi = biaodashi + ".";
                this.repaint();
                break;
            case "=":
                try {
                    ScriptEngineManager manager = new ScriptEngineManager();
                    ScriptEngine engine = manager.getEngineByName("js");
                    engine.put("a", 4);
                    Object end = engine.eval(biaodashi);
                    biaodashi = end.toString();
                    this.repaint();
                    break;
                } catch (ScriptException t) {
                    biaodashi = "表达式错误!";
                    this.repaint();
                    break;
                }
            case "C":
                biaodashi = "";
                this.repaint();
                break;
            case "CE":
                biaodashi = "";
                this.repaint();
                break;
            case "←":
                StringBuffer str = new StringBuffer(biaodashi);
                str.delete(biaodashi.length()-1, biaodashi.length());
                biaodashi=str.toString();
                this.repaint();
                break;
            case "%":
                try {
                     ScriptEngineManager manager = new ScriptEngineManager();
                    ScriptEngine engine = manager.getEngineByName("js");
                    engine.put("a", 4);
                    Object end = engine.eval(biaodashi);
                    biaodashi = end.toString();
                  

                    int flag = 0;
                    int i = 0;
                    for (; i < biaodashi.length(); i++) {
                        if (biaodashi.charAt(i) == '.') {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1 && biaodashi.charAt(0) != '0') {
                        StringBuffer str = new StringBuffer(biaodashi);
                        str.insert(i, "00");
                        biaodashi = str.toString();
                        biaodashi += "%";
                    } else if (flag == 0) {
                        biaodashi += "00%";
                    } else {
                        StringBuffer str = new StringBuffer(biaodashi);
                        str.delete(0, 2);
                        str.insert(2, '.');
                        biaodashi = str.toString();
                        biaodashi += "00%";
                    }
                     

                    this.repaint();
                    break;
                } catch (ScriptException t) {
                    biaodashi = "表达式错误!";
                    this.repaint();
                    break;
                }
        }
    }

}
