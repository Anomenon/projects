public class Ball_Movement {
    static boolean breaking = false;
    static int first = 0;
    static void B_Movement(){
        Main.timer++;

        if(Main.y_axis == 83){
            Main.L_score ++;
            Main.Left_Right = true;
            breaking = true;
        }  else if (Main.y_axis + 1 == 82 && Main.x_axis >= 13 - Main.R_palette && Main.x_axis <= 20 - Main.R_palette){
            Main.Left_Right = true;
            Main.y_direction = 1;
            Pong_Body.Pong[Main.y_axis][Main.x_axis] = 2;
        }
        if (Main.y_axis == 2){
            Main.R_score++;
            Main.Left_Right = false;
            breaking = true;
        }   else if (Main.y_axis - 2 == 2 && Main.x_axis >= 13 - Main.L_palette && Main.x_axis <= 20 - Main.L_palette){
            Main.Left_Right = false;
            Main.y_direction = -1;
            Pong_Body.Pong[Main.y_axis][Main.x_axis] = 2;

        } else if (Pong_Body.Pong[Main.y_axis - Main.y_direction][Main.x_axis - Main.x_direction] == 3 ||
                Pong_Body.Pong[Main.y_axis - Main.y_direction][Main.x_axis - Main.x_direction] == 10 ||
                Pong_Body.Pong[Main.y_axis - Main.y_direction][Main.x_axis - Main.x_direction] == 11){

            if(Main.x_direction == 1){
                Main.x_direction = -1;
            } else if (Main.x_direction == -1){
                Main.x_direction = 1;
            }
        }

        if(Main.timer == Main.acceleration){
            Score_Graphics.Graphics();
            if( Main.y_axis == 43){
                for(int i = 0; i < 33; i ++){
                    if(i == 0){
                        Pong_Body.Pong[43][i] = 10;
                    } else if (i == 32){
                        Pong_Body.Pong[43][i] = 11;
                    } else {
                        Pong_Body.Pong[43][i] = 9;
                    }
                }
            } else {
                Pong_Body.Pong[Main.y_axis][Main.x_axis] = 0;
            }
            Pong_Body.Pong[Main.y_axis -= Main.y_direction][Main.x_axis -= Main.x_direction] = 2;
            Main.speed++;

            Main.timer = 0;
        }

        if(Main.speed == 20){
            if(Main.acceleration != 1){
                Main.acceleration--;
            }
            Main.speed = 0;
        }

        if(first == 0){
            if (Main.Left_Right){
                Main.y_direction = 1;
            } else {
                Main.y_direction = -1;
            }
            Pong_Body.Pong[Main.y_axis][Main.x_axis] = 2;
            if (Main.Up_Down){
                Main.x_direction = 1;
            } else {
                Main.x_direction = -1;
            }
            first = 1;
        }
    }
}
