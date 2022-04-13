public class Palette_Movement {
    static void Movement(){

        for(int i = 13; i < 20; i++){
            Pong_Body.Pong[3][i - Main.L_palette] = 1;
            Pong_Body.Pong[82][i - Main.R_palette] = 1;
        }
        Pong_Body.Pong[3][12 - Main.L_palette] = 0;
        Pong_Body.Pong[3][20 - Main.L_palette] = 0;
        Pong_Body.Pong[82][12-Main.R_palette] = 0;
        Pong_Body.Pong[82][20-Main.R_palette] = 0;

        Pong_Body.Pong[3][0] = 3;
        Pong_Body.Pong[3][32] = 3;
        Pong_Body.Pong[82][0] = 3;
        Pong_Body.Pong[82][32] = 3;
    }
}
