public class BankAccount implements Measurable {

    private String accntName;
    private double balance;

    public BankAccount(double initBal, String name){
        accntName = name;
        balance = initBal;
    }
    
    public String getItemName(){
        return accntName;
    }

    public double getMeasure(){
        return balance;
    }

}
