import java.util.ArrayList;

public class MultipleOfThreeAndFive {

    public static void main(String[] args) {
      
        int upperBound = Integer.parseInt(args[0]);
        int nrOfMultipleForThree = 0;
        int nrOfMultipleForFive = 0;

        for(int temp =0; temp < upperBound ; temp++) {
          if(temp % 3 == 0)
            nrOfMultipleForThree += temp;
          else if(temp % 5 == 0)
              nrOfMultipleForFive += temp;
        }

        int totalNrOfMultiple = nrOfMultipleForFive + nrOfMultipleForThree;

        System.out.println("The multiples of 3 or 5 up to " + upperBound + " are: " + totalNrOfMultiple);

    }

}
