import java.util.Scanner;

public class praca_domowa_z_lekcji_18 {
    static void praca_domowa_z_lekcji_18(){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Input the password: ");
        String password = scanner.nextLine();
        String encrypted_pass = "";

        for (int i = 0; i < password.length(); i++) {
            int ascii = password.charAt(i);
            encrypted_pass += ascii;
        }
        System.out.println(encrypted_pass);
        long pass = Long.parseLong(encrypted_pass);


        if(pass % 2 == 0){
            pass = pass/2;
        }

        System.out.println('\n' + "The encryption of your password is: " + pass);
    }
}
