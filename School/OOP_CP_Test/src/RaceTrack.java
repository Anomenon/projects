public class RaceTrack {
    private int length;
    private Car car1, car2;

    public int getLength() {
        return length;
    }
    public void setLength(int length) {
        this.length = length;
    }

    public void race(){
//        int seconds1 = 0;
//        int new_length1 = length;
//
//        while(new_length1 != 0){
//            new_length1 -= car1.getSpeed();
//            if(car1.getSpeed() != car1.getTopSpeed()){
//                car1.accelerate();
//            }
//            seconds1++;
//        }
//
//        int seconds2 = 0;
//        int new_length2 = length;
//
//        while(new_length2 != 0){
//            new_length2 -= car2.getSpeed();
//            if(car2.getSpeed() != car2.getTopSpeed()){
//                car2.accelerate();
//            }
//            seconds2++;
//        }
//
//        if(seconds1 > seconds2){
//            System.out.println("Winner is:");
//            car1.getClass().getName();
//            car1.getClass().getColor();
//            System.out.println("Second place is:");
//            car2.getClass().getName();
//        }
    }

    public RaceTrack(Car car1, Car car2){
        this.car1 = car1;
        this.car2 = car2;
    }
}
