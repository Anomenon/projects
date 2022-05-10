public class Score_Graphics {
    static int i = 34;
    public static void conditions(int condition) {
        for (int j = 1; j < 6; j++) {

            if (condition == 1) {
                if (j == 2 || j == 3 || j == 4) {
                    Pong_Body.Pong[i][j] = 12;
                }

            } else if (condition == 2) {
                if (j == 1 || j == 5) {
                    Pong_Body.Pong[i][j] = 12;
                }

            } else if (condition == 3) {
                Pong_Body.Pong[i][j] = 12;

            } else if (condition == 4) {
                if (j == 1 || j == 3 || j == 5) {
                    Pong_Body.Pong[i][j] = 12;
                }
            } else if (condition == 5) {
                if (j != 4) {
                    Pong_Body.Pong[i][j] = 12;
                }
            } else if (condition == 6) {
                if (j != 2) {
                    Pong_Body.Pong[i][j] = 12;
                }
            } else if (condition == 7) {
                if (j == 3) {
                    Pong_Body.Pong[i][j] = 12;
                }
            } else if (condition == 8) {
                if (j == 1 || j == 2 || j == 3) {
                    Pong_Body.Pong[i][j] = 12;
                }
            } else if (condition == 9) {
                if (j == 1) {
                    Pong_Body.Pong[i][j] = 12;
                }
            }

        }
    }

    static void Graphics() {
        i = 34;

        while (i < 55) {
            switch (i) {
                case 34:
                    if(Main.L_score == 10){
                        conditions(3);
                    }
                    break;
                case 37:
                    if(Main.L_score == 0 || Main.L_score == 10){
                        conditions(1);
                    } else if (Main.L_score == 2){
                        conditions(6);
                    } else if (Main.L_score == 4){
                        conditions(8);
                    } else if (Main.L_score == 5 || Main.L_score == 9){
                        conditions(5);
                    } else if (Main.L_score == 6 || Main.L_score == 8) {
                        conditions(3);
                    } else if (Main.L_score == 7){
                        conditions(9);
                    } else if (Main.L_score == 3){
                        conditions(4);
                    }
                    break;

                case 38:
                case 40:
                    if(Main.L_score == 0 || Main.L_score == 10){
                        conditions(2);
                    } else if (Main.L_score == 2 || Main.L_score == 3 || Main.L_score == 5 || Main.L_score == 9 || Main.L_score == 6 || Main.L_score == 8){
                        conditions(4);
                    } else if (Main.L_score == 4){
                        conditions(7);
                    } else if (Main.L_score == 7){
                        conditions(9);
                    }

                    break;

                case 39:
                    if(Main.L_score == 0 || Main.L_score == 10){
                        conditions(2);
                    } else if (Main.L_score == 1) {
                        conditions(3);
                    } else if (Main.L_score == 2 || Main.L_score == 3 || Main.L_score == 5 || Main.L_score == 9 || Main.L_score == 6 || Main.L_score == 8){
                        conditions(4);
                    } else if (Main.L_score == 4){
                        conditions(7);
                    } else if (Main.L_score == 7){
                        conditions(9);
                    }

                    break;

                case 41:
                    if(Main.L_score == 0 || Main.L_score == 10){
                        conditions(1);
                    } else if (Main.L_score == 2){
                        conditions(5);
                    } else if (Main.L_score == 5 || Main.L_score == 6){
                        conditions(6);
                    } else if (Main.L_score == 9 || Main.L_score == 7 || Main.L_score == 8 || Main.L_score == 4 || Main.L_score == 3){
                        conditions(3);
                    }
                    break;

                case 45:
                    if(Main.R_score == 0){
                        conditions(1);
                    } else if (Main.R_score == 2){
                        conditions(6);
                    } else if (Main.R_score == 4){
                        conditions(8);
                    } else if (Main.R_score == 5 || Main.R_score == 9){
                        conditions(5);
                    } else if (Main.R_score == 6 || Main.R_score == 8) {
                        conditions(3);
                    } else if (Main.R_score == 7){
                        conditions(9);
                    } else if (Main.R_score == 3){
                        conditions(4);
                    }

                break;
                case 46:
                case 48:
                    if(Main.R_score == 0){
                        conditions(2);
                    } else if (Main.R_score == 2 || Main.R_score == 3 || Main.R_score == 5 || Main.R_score == 9 || Main.R_score == 6 || Main.R_score == 8){
                        conditions(4);
                    } else if (Main.R_score == 4){
                        conditions(7);
                    } else if (Main.R_score == 7){
                        conditions(9);
                    }
                    break;
                case 47:
                    if(Main.R_score == 0){
                        conditions(2);
                    } else if (Main.R_score == 1 || Main.R_score == 10) {
                        conditions(3);
                    } else if (Main.R_score == 2 || Main.R_score == 3 || Main.R_score == 5 || Main.R_score == 9 || Main.R_score == 6 || Main.R_score == 8){
                        conditions(4);
                    } else if (Main.R_score == 4){
                        conditions(7);
                    } else if (Main.R_score == 7){
                        conditions(9);
                    }
                    break;

                case 49:
                    if(Main.R_score == 0){
                        conditions(1);
                    } else if (Main.R_score == 2){
                        conditions(5);
                    } else if (Main.R_score == 3){
                        conditions(3);
                    } else if (Main.R_score == 4){
                        conditions(3);
                    } else if (Main.R_score == 5 || Main.R_score == 6){
                        conditions(6);
                    } else if (Main.R_score == 9 || Main.R_score == 7 || Main.R_score == 8){
                        conditions(3);
                    }
                    break;
                case 54:
                case 50:
                    if(Main.R_score == 10){
                        conditions(1);
                    }
                    break;
                case 51:
                case 52:
                case 53:
                    if(Main.R_score == 10){
                        conditions(2);
                    }
            }
            i++;
        }

    }


}




