import java.util.Random;

/**
 * cd IdeaProjects/Pong/out/production/Pong
 *
 * Tomorrow plan:
 * -Ball A.I.
 */

public class Main {
    static String code = "Null";
    static int y_axis = 43;
    static int x_axis = 16;
    static int timer = 0;
    static int speed = 0;
    static int txt = 0;
    static int y_direction;
    static int x_direction = 0;
    static int R_score = 0;
    static int L_score = 0;
    static int L_palette = 0;
    static int R_palette = 0;
    static int Menu_changer = 0;
    static  int acceleration = 4;
    static boolean GameOn = false;
    static boolean MenuOn = true;
    static boolean Left_Right;
    static boolean Up_Down;
    static Random rd = new Random();

    public static void clearScreen() throws InterruptedException{
        Thread.sleep(40);
        System.out.print("\033\143");
    }

    public static void main(String[] args) throws InterruptedException{
        clearScreen();
        Pong_Frame.Frame();
        Game_Body.Body();
    }

}