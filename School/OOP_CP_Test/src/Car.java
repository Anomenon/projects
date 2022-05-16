public class Car {
    private int speed, acceleration, topSpeed;

    public int getSpeed() {
        return speed;
    }
    public void setSpeed(int newSpeed) {
        this.speed = newSpeed;
    }

    public int getAcceleration() {
        return acceleration;
    }
    public void setAcceleration(int newAcceleration) {
        this.acceleration = newAcceleration;
    }

    public int getTopSpeed() {
        return topSpeed;
    }
    public void setTopSpeed(int newTopSpeed) {
        this.topSpeed = newTopSpeed;
    }

    void accelerate(){
        if(speed + acceleration <= topSpeed){
            speed += acceleration;
        }
    }

    public Car(int speed, int acceleration, int topSpeed){
        this.speed = speed;
        this.acceleration = acceleration;
        this.topSpeed = topSpeed;
    }
}
