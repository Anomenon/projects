import java.lang.Math;

public class Main {
    static int BinToDec(String binary) {
        int decimal = 0, pow = 0;

        for(int i = binary.length() - 1; i >= 0; i--){
            decimal += Character.getNumericValue(binary.charAt(i)) * Math.pow(2, pow);
            pow++;
        }

        return decimal;
    }
    static String DecToBin(int decimal){
        String bin = "", binary = "";

        while(decimal > 0){
            bin +=  decimal%2;
            decimal = decimal/2;
        }

        for(int i = bin.length() - 1; i >= 0; i--){
            binary += bin.charAt(i);
        }

        return binary;
    }
    static String Changer(String text){
        char[] letter = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        text = text.toLowerCase();
        String new_text = "";

        for (int i = 0; i < text.length(); i++){
            for (int j = 0; j < letter.length; j++){
                if (text.charAt(i) == letter[j]){
                    new_text += letter[letter.length - j - 1];
                }
            }
        }

        new_text = new_text.toUpperCase();
        return new_text;
    }

    public static void main(String[] args){
        System.out.println(BinToDec("1010"));
        System.out.println(DecToBin(10));
        System.out.println(Changer("KUBA"));


        try{
            int[] x = new int[0];
            System.out.println(x[0]);
        } catch (ArrayIndexOutOfBoundsException exception) {
            System.out.println("Something went wrong");
        }

    }
}

