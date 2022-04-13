public class praca_domowa_z_lekcji_20 {
    static int convertTriplesToDecimal(int n) {

        int decimalNumber = 0;
        int base = 1;

        while (n > 0) {
            int lastDigit = n % 10;
            n = n / 10;
            decimalNumber += lastDigit * base;
            base = base * 3;
        }
        return decimalNumber;
    }
    static int convertDecimalToTriples(int n){
        int triples = 0;
        int base = 3;

        n = n / 3;
        while (n > 0) {
            int lastDigit = n % 3;
            n = n / 3;
            triples += lastDigit * base;
            base = base * 10;
        }

        return triples;
    }
}
