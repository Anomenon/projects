public class BackstrokeSwimmer extends Swimmer{
    enum Styles{
        butterfly,
        backstroke
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

    public BackstrokeSwimmer(int speed, int acceleration, int topSpeed) {
        super(speed, acceleration, topSpeed);
    }
}
