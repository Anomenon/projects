public class Swimmer {
    private int acceleration, speed, topSpeed;

    public int getAcceleration() {return acceleration;}
    public void setAcceleration(int acceleration) {this.acceleration = acceleration;}

    public int getSpeed() {return speed;}
    public void setSpeed(int speed) {this.speed = speed;}

    public int getTopSpeed() {return topSpeed;}
    public void setTopSpeed(int topSpeed) {this.topSpeed = topSpeed;}

    void accelerate(){
        if(speed + acceleration <= topSpeed){
            speed += acceleration;
        }
    }

    public Swimmer(int speed, int acceleration, int topSpeed){
        this.speed = speed;
        this.acceleration = acceleration;
        this.topSpeed = topSpeed;
    }
}
