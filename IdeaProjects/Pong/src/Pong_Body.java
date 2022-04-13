public class Pong_Body{
    static int[][] Pong = new int[87][33];

    static void Graphics() throws InterruptedException {
        Maps.Pong_Map();

        while (Main.GameOn){

            Score.score();
            if(Score.breaking2){
                break;
            }

            Ball_Movement.B_Movement();

            if(Ball_Movement.breaking){
                break;
            }

            Palette_Movement.Movement();

            Main.clearScreen();
            for(int x = 0; x < 33; x++){
                for(int y = 0; y < 87; y++){
                    char blocks;
                    if (Pong[y][x] == 0){
                        blocks = ' ';
                    } else if(Pong[y][x] == 1){
                        blocks = '█';
                    } else if(Pong[y][x] == 2){
                        blocks = '⊚';
                    } else if (Pong[y][x] == 3){
                        blocks = '━';
                    } else if (Pong[y][x] == 4){
                        blocks = '│';
                    } else if (Pong[y][x] == 5) {
                        blocks = '┍';
                    } else if (Pong[y][x] == 6) {
                        blocks = '┕';
                    } else if (Pong[y][x] == 7) {
                        blocks = '┑';
                    } else if (Pong[y][x] == 8) {
                        blocks = '┙';
                    } else if (Pong[y][x] == 9){
                        blocks = '┆';
                    } else if (Pong[y][x] == 10){
                        blocks = '┯';
                    } else if (Pong[y][x] == 11){
                        blocks = '┷';
                    } else if (Pong[y][x] == 12){
                        blocks = '█';
                    }else {
                        blocks = ' ';
                    }
                    System.out.print(blocks);
                }
                System.out.print("\r\n");
            }

        }

    }

}
