import java.util.Objects;

public class Game_Menu {


    static void Menu() throws InterruptedException {
        Main.Menu_changer = 0;
        while (Main.MenuOn) {
            Main.clearScreen();
            Main.Left_Right = Main.rd.nextBoolean();
            Main.Up_Down = Main.rd.nextBoolean();

            for (int j = 0; j < Maps.Menu_Map.length; j++){
                if(Main.Menu_changer == 0){
                    Maps.Menu_Map[24] = "│       ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                                               │";

                } else if(Main.Menu_changer == 1){
                    Maps.Menu_Map[24] = "│                                                       ░░░░░░░░░░░░░░░░░░░░░░░       │";

                }
                System.out.println(Maps.Menu_Map[j]);
            }

            if (Main.code.equals("exit")) {
                Main.clearScreen();
                Main.MenuOn = false;
                Main.clearScreen();
                System.exit(0);

            } else if (Objects.equals(Main.code, "space")) {
                Main.txt = 0;
                Main.acceleration = 4;
                Main.L_score = 0;
                Main.R_score = 0;
                Main.L_palette = 0;
                Main.R_palette = 0;
                Main.timer = -1;
                Main.x_direction = 0;
                Main.y_axis = 43;
                Main.x_axis = 16;
                Main.MenuOn = false;
                Main.GameOn = true;
                Ball_Movement.breaking = false;
                Score.breaking2 = false;
                Ball_Movement.first = 0;
            }
        }
    }
}
