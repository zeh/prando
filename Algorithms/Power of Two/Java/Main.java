public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        System.out.println("2 = " + main.isPowerOfTwo(2));
        System.out.println("4 = " + main.isPowerOfTwo(4));
        System.out.println("6 = " + main.isPowerOfTwo(6));
        System.out.println("8 = " + main.isPowerOfTwo(8));
        System.out.println("10 = " + main.isPowerOfTwo(10));
        System.out.println("12 = " + main.isPowerOfTwo(12));
        System.out.println("14 = " + main.isPowerOfTwo(14));
        System.out.println("16 = " + main.isPowerOfTwo(16));
    }

    public boolean isPowerOfTwo(int num) {
        if (num % 2 != 0 || num <= 0) {
            // If the number is odd or is less than or equal to 0, then it is not a power of two.
            return false;
        } else
        if (num / 2 == 1) {
            // If the number is 2, then it is a power of two.
            return true;
        } else {
            // Recursive call only if the number is even.
            return isPowerOfTwo(num / 2);
        }
    }
}