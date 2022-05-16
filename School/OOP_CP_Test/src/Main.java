public class Main {
    public static void main(String[] args) {
        Ferrari ferrari = new Ferrari(0, 20, 100);
        ferrari.setName("Pepperoni");
        ferrari.setColor(Ferrari.CarColor.Red);

        Mercedes mercedes = new Mercedes(0, 20, 100);
        mercedes.setName("Margherita");
        mercedes.setColor(Mercedes.CarColor.Black);

        RaceTrack race1 = new RaceTrack(ferrari, mercedes);
        race1.setLength(200);
        race1.race();

    }
}




