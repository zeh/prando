import java.util.Arrays;

public class DPDemos {

	public static void main(String[] args) {

		int n = 2;
		 System.out.println(fibonacciTD(n, new int[n + 1]));
		 System.out.println(fibonacciBU(n));
		 System.out.println(fibonacciBUSE(n));		

	}

	public static int fibonacci(int n) {            // fibonacci - normal recursion approach without using dynamic programming .

		if (n == 0 || n == 1) {
			return n;
		}

		int fnm1 = fibonacci(n - 1);
		int fnm2 = fibonacci(n - 2);

		int fn = fnm1 + fnm2;

		return fn;

	}

	public static int fibonacciTD(int n, int[] strg) {      //fibonacci top down approach

		if (n == 0 || n == 1) {
			return n;
		}

		if (strg[n] != 0) {
			return strg[n];
		}

		int fnm1 = fibonacciTD(n - 1, strg);
		int fnm2 = fibonacciTD(n - 2, strg);

		int fn = fnm1 + fnm2;

		strg[n] = fn;
		return fn;

	}

	public static int fibonacciBU(int n) {     //fibonacci bottoms up approach

		int[] strg = new int[n + 1];

		strg[0] = 0;
		strg[1] = 1;

		for (int i = 2; i < strg.length; i++) {
			strg[i] = strg[i - 1] + strg[i - 2];
		}

		return strg[n];

	}

	public static int fibonacciBUSE(int n) {   // fibonacci bottoms up approach - space efficient .

		int[] strg = new int[2];
		strg[0] = 0;
		strg[1] = 1;

		for (int slide = 1; slide <= n - 1; slide++) {

			int sum = strg[0] + strg[1];
			strg[0] = strg[1];
			strg[1] = sum;

		}

		return strg[1];

	}
}
