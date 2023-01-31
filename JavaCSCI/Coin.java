public class Coin implements Measurable{
    public String coinName;
    public double coinValue;

    public Coin(double value, String name){
        coinValue = value;
        coinName = name;
    }

    public String getItemName() {
        return coinName;
    }

    public double getMeasure() {
        return coinValue;
    }

    public void times2(){
        coinValue *= 2;
    }
}
