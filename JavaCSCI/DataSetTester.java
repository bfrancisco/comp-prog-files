public class DataSetTester {
    
    public static void main(String[] args){

        DataSet ds = new DataSet();

        ds.add(new BankAccount(1000, "Alice"));
        ds.add(new BankAccount(2000, "Bob"));
        ds.add(new BankAccount(500, "Cindy"));

        


    }
}
