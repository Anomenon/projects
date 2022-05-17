public class Mercedes extends Car{
    enum CarColor{
        Black,
        Gray,
        White
    }

    private String Name;
    private CarColor Color;

    public CarColor getColor() {return Color;}
    public void setColor(CarColor color) {Color = color;}

    public String getName() {return Name;}
    public void setName(String name) {Name = name;}

    public Mercedes(float speed, float acceleration, float topSpeed) {
        super(speed, acceleration, topSpeed);
    }
}
