import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class Game_Input {
    static class Keyboard extends KeyAdapter {
        public void keyPressed(KeyEvent event) {
            switch (event.getKeyCode()) {
                //Left Player ------------
                case 87 -> {
                    Main.code = "w";
                    if (Main.L_palette != 12) {
                        Main.L_palette++;
                    }
                }
                case 83 -> {
                    Main.code = "s";
                    if (Main.L_palette != -12) {
                        Main.L_palette--;

                    }
                }
                //------------------------
                //Right Player -----------
                case 79 -> {
                    Main.code = "up";
                    if (Main. R_palette != 12) {
                        Main.R_palette++;
                    }
                }
                case 76 -> {
                    Main.code = "down";
                    if (Main.R_palette != -12) {
                        Main.R_palette--;
                    }
                }
                //------------------------
                //Menu ---------------
                case 27 -> {
                    Main.code = "esc";
                    Main.GameOn = false;
                    Main.MenuOn = true;
                }
                case 10 -> {
                    Main.code = "enter";
                    if (Main.Menu_changer == 0){
                        Main.code = "space";

                    } else  if(Main.Menu_changer == 1){
                        Main.code = "exit";
                    }
                }

                case 37, 65 -> Main.Menu_changer = 0;
                case 39, 68 -> Main.Menu_changer = 1;

                //------------------------
            }

        }
    }
}
