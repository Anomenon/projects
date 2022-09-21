public class ButterflySwimmer extends Swimmer{
    enum Styles{
        breaststroke,
        freestyle
    }

    enum Nationality{
        Polish,
        German,
        Japanese,
        Russian,
        Ukrainian,
        Chinese,
        Czech,
        American
    }

    private Nationality nationality;
    private Styles Style;

    public Nationality getNationality() {return nationality;}
    public void setNationality(Nationality nationality) {this.nationality = nationality;}

    public Styles getStyle() {return Style;}
    public void setStyle(Styles style) {Style = style;}

    public ButterflySwimmer(int speed, int acceleration, int topSpeed) {
        super(speed, acceleration, topSpeed);
    }
}
