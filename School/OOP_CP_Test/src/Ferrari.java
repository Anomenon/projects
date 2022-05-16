public class Ferrari extends Car{
    enum CarColor{
        Yellow,
        Orange,
        Red
    }

    private String Name;
    private CarColor Color;

    public CarColor getColor() {
        return Color;
    }
    public void setColor(CarColor color) {
        Color = color;
    }

    public String getName() {
        return Name;
    }
    public void setName(String name) {
        Name = name;
    }

    public Ferrari(int speed, int acceleration, int topSpeed) {
        super(speed, acceleration, topSpeed);
    }
}
