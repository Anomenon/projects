import java.util.Vector;

public class PoolRace {
    private int poolLength, laps;
    BackstrokeSwimmer Swimmer_One;
    ButterflySwimmer Swimmer_Two;

    public int getPoolLength() {return poolLength;}
    public void setPoolLength(int poolLength) {this.poolLength = poolLength;}

    public int getLaps() {return laps;}
    public void setLaps(int laps) {this.laps = laps;}

    void race(){
        Vector<Integer> v = new Vector<Integer>();
        Vector<Integer> swimTime = new Vector<Integer>();

        int time = 0;
        int route = 0;

        while (route < poolLength * laps){
            route += Swimmer_One.getSpeed();
            if(Swimmer_One.getSpeed() + Swimmer_One.getAcceleration() >= Swimmer_One.getTopSpeed()){
                Swimmer_One.accelerate();
            } else {
                Swimmer_One.setSpeed(Swimmer_One.getTopSpeed());
            }
            time++;
        }
        swimTime.add(0, time);

        time = 0;
        route = 0;

        while (route < poolLength * laps){
            route += Swimmer_Two.getSpeed();
            if(Swimmer_Two.getSpeed() + Swimmer_Two.getAcceleration() >= Swimmer_Two.getTopSpeed()){
                Swimmer_Two.accelerate();
            } else {
                Swimmer_Two.setSpeed(Swimmer_Two.getTopSpeed());
            }
            time++;
        }
        swimTime.add(1, time);

        System.out.print(Swimmer_One.getNationality() + " swimmer that used " + Swimmer_One.getStyle() + " style,");
        if(swimTime.get(0) < swimTime.get(1)){
            System.out.print(" won against ");

        } else if(swimTime.get(0) > swimTime.get(1)){
            System.out.print(" lost against ");

        } else {
            System.out.print(" had tie with ");
        }
        System.out.println(Swimmer_Two.getNationality() + " swimmer that used "+ Swimmer_Two.getStyle() + " style.");
    }

    PoolRace(int poolLength, int laps){
        this.poolLength = poolLength;
        this.laps = laps;

        Swimmer_One = new BackstrokeSwimmer(0, 10, 100);
        Swimmer_One.setNationality(BackstrokeSwimmer.Nationality.German);
        Swimmer_One.setStyle(BackstrokeSwimmer.Styles.butterfly);

        Swimmer_Two = new ButterflySwimmer(0, 5, 1000);
        Swimmer_Two.setNationality(ButterflySwimmer.Nationality.Chinese);
        Swimmer_Two.setStyle(ButterflySwimmer.Styles.freestyle);
    }
}
