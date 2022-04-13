public class Score {
    static boolean breaking2 = false;

    public static int getRandomNumber(int min, int max) {
        return (int) ((Math.random() * (max - min)) + min);
    }

    static void score() throws InterruptedException{

        if (Main.L_score == 11 || Main.R_score == 11){
            if (Main.L_score == 11){
                Maps.Winner_screen[9] = "│                              █████████████████████████                              │";
                Maps.Winner_screen[10] ="│                              █▄─▄███▄─▄▄─█▄─▄▄─█─▄─▄─█                              │";
                Maps.Winner_screen[11] ="│                              ██─██▀██─▄█▀██─▄█████─███                              │";
                Maps.Winner_screen[12] ="│                              ▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▀▀▀▀▄▄▄▀▀                              │";

            } else if (Main.R_score == 11){
                Maps.Winner_screen[9] = "│                              ███████████████▀███████████                            │";
                Maps.Winner_screen[10] ="│                              █▄─▄▄▀█▄─▄█─▄▄▄▄█─█─█─▄─▄─█                            │";
                Maps.Winner_screen[11] ="│                              ██─▄─▄██─██─██▄─█─▄─███─███                            │";
                Maps.Winner_screen[12] ="│                              ▀▄▄▀▄▄▀▄▄▄▀▄▄▄▄▄▀▄▀▄▀▀▄▄▄▀▀                            │";
            }

            Main.clearScreen();
            for(int i = 0; i < Maps.Winner_screen.length; i++){
                System.out.println(Maps.Winner_screen[i]);
            }
            Thread.sleep(2000);
            breaking2 = true;
            Main.GameOn = false;
            Main.MenuOn = true;
        }

        if(Ball_Movement.breaking){
            if (Main.L_score > Main.R_score || Main.Left_Right){
                Main.Left_Right = true;
                Main.y_direction = 1;
                Main.y_axis = 67;

            } else {
                Main.Left_Right = false;
                Main.y_direction = -1;
                Main.y_axis = 20;

            }
            Main.acceleration = 4;
            Main.x_axis = getRandomNumber(3, 30);
            Main.L_palette = 0;
            Main.R_palette = 0;
            Main.timer = -1;
            Ball_Movement.breaking = false;
        }
    }
}
