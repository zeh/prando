import java.util.Scanner;

public class swap {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a=s.nextInt();
        int b=s.nextInt();

        //Swapping without a temporary variable
        a=b-a;
        b=b-a;
        a=b+a;
        
        System.out.println(a + " " + b);
    }
}
