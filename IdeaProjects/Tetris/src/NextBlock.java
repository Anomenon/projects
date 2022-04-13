import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

public class NextBlock extends JPanel {
   public NextBlock(){
        Border border = BorderFactory.createLineBorder(new Color(0, 0, 0), 1);
        this.setBorder(border);
        this.setBounds(550,30,135,108);
        this.setLayout(null);
        this.setSize(135,108);
    }
    @Override
    protected void paintComponent(Graphics g){
        for(int i=0;i<135/27;i++) {
            g.drawLine(i*27, 0, i*27, 108);
            g.drawLine(0, i*27, 135, i*27);
        }
    }
}
