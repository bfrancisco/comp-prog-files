public class DataSet {

    private Measurable maximum;
    private static int count;

    public DataSet(){
        count = 0;
        maximum = null;
    }

    void add(Measurable x){
        if (count == 0 || maximum.getMeasure() < x.getMeasure()){
            maximum = x;
        }
        count ++;
    }

    Measurable getMaximum(){
        return maximum;
    }
}
