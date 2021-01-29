/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

/*
 *
 * @author lenovo
 */
public class app extends Applet implements ActionListener {

    private Label label;
    private long count = 0;

    @Override
    public void init() {
        Button button;
        button = new Button("请点击");

        button.addActionListener(this);

        add(button);
        label = new Label(String.valueOf(count));
        add(label);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        count++;
        label.setText(String.valueOf(count));
    }

}
