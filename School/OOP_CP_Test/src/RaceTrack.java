public class RaceTrack {
    private float length;
    private Ferrari ferrari;
    private Mercedes mercedes;

    public float getLength() {return length;}
    public void setLength(float length) {this.length = length;}

    public void race(){

    }

    public RaceTrack(){
        this.ferrari = new Ferrari(0, 20, 100);
        ferrari.setName("Pepperoni");
        ferrari.setColor(Ferrari.CarColor.Red);

        this.mercedes = new Mercedes(0, 20, 100);
        mercedes.setName("Margherita");
        mercedes.setColor(Mercedes.CarColor.Black);
    }
}
