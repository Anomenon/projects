public class Game_Body {
    static void Body() throws InterruptedException{
        while (true){
            while (Main.GameOn){
                Pong_Body.Graphics();
            }
            Main.clearScreen();
            Game_Menu.Menu();
        }
    }
}
