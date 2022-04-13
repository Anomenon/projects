import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

public class GameArea extends JPanel {
    public GameArea(){
        Border border = BorderFactory.createLineBorder(new Color(0, 0, 0), 1);
        this.setBorder(border);
        this.setBounds(220,15,270,540);
        this.setLayout(null);
        this.setSize(270,540);
    }
    @Override
    protected void paintComponent(Graphics g){
        for(int i=0;i<540/27;i++) {
            g.drawLine(i*27, 0, i*27, 540);
            g.drawLine(0, i*27, 270, i*27);
        }
    }
}
