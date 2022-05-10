import javax.swing.*;
import java.awt.*;

public class Pong_Frame {
    static void Frame(){
        JFrame frame = new JFrame(" ");
        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());
        frame.addKeyListener(new Game_Input.Keyboard());
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
