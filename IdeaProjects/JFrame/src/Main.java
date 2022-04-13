import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

public class Main {
    public static void main(String[] args){

        ImageIcon image = new ImageIcon("apple.png");
        Border border = BorderFactory.createLineBorder(new Color(248, 203, 28), 10);
        JLabel label = new JLabel();
        label.setText("Bro do you even code?");
        label.setIcon(image);
        label.setHorizontalTextPosition(JLabel.CENTER);
        label.setVerticalTextPosition(JLabel.TOP);
        label.setForeground(new Color(248, 203, 28));
        label.setFont(new Font("MV Boli", Font.PLAIN, 20));
        label.setIconTextGap(-20);
        label.setBackground(new Color(245, 161, 4));
        label.setOpaque(true);
        label.setBorder(border);
        label.setVerticalAlignment(JLabel.CENTER);
        label.setHorizontalAlignment(JLabel.CENTER);
        //label.setBounds(0,0,250,250);

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //frame.setSize(500, 500);
        //frame.setLayout(null);
        frame.setVisible(true);
        frame.add(label);
        frame.pack();

        /*
        JLabel label = new JLabel();
        label.setText("Hi");
        ImageIcon image = new ImageIcon("applelogo2.png");
        label.setIcon(image);
        label.setVerticalAlignment(JLabel.CENTER);
        label.setHorizontalAlignment(JLabel.CENTER);
        label.setBounds(0,0,75,75);

        JPanel redPanel = new JPanel();
        redPanel.setBackground(new Color(155, 27, 27));
        redPanel.setBounds(0,0,250,250);
        redPanel.setLayout(null);

        JPanel bluePanel = new JPanel();
        bluePanel.setBackground(new Color(27, 68, 155));
        bluePanel.setBounds(250,0,250,250);
        bluePanel.setLayout(null);

        JPanel greenPanel = new JPanel();
        greenPanel.setBackground(new Color(27, 155, 48));
        greenPanel.setBounds(0,250,250,250);
        greenPanel.setLayout(null);

        JPanel yellowPanel = new JPanel();
        yellowPanel.setBackground(new Color(218, 175, 30, 255));
        yellowPanel.setBounds(250,250,250,250);
        yellowPanel.setLayout(null);

        JFrame frame = new JFrame();
        frame.setSize(750, 750);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        greenPanel.add(label);
        frame.add(redPanel);
        frame.add(bluePanel);
        frame.add(greenPanel);
        frame.add(yellowPanel);

         */


    }
}
