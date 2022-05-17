public class Car {
    private float speed, acceleration, topSpeed;

    public float getSpeed() {return speed;}
    public void setSpeed(int newSpeed) {this.speed = newSpeed;}

    public float getAcceleration() {return acceleration;}
    public void setAcceleration(float newAcceleration) {this.acceleration = newAcceleration;}

    public float getTopSpeed() {return topSpeed;}
    public void setTopSpeed(float newTopSpeed) {this.topSpeed = newTopSpeed;}

    void accelerate(){
        if(speed + acceleration <= topSpeed){
            speed += acceleration;
        }
    }

    public Car(float speed, float acceleration, float topSpeed){
        this.speed = speed;
        this.acceleration = acceleration;
        this.topSpeed = topSpeed;
    }
}
