import java.util.ArrayList;

public class MultipleOfThreeAndFive {

    public static void main(String[] args) {
      
        int upperBound = Integer.parseInt(args[0]);
        int nrOfMultipleForThree = upperBound / 3;
        int nrOfMultipleForFive = upperBound / 5;

        int totalNrOfMultiple = nrOfMultipleForFive + nrOfMultipleForThree;

        System.out.println("The multiples of 3 or 5 up to " + upperBound + " are: " + totalNrOfMultiple);
    }

}
