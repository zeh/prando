import java.util.Scanner;
import java.lang.Character;
public class Main
{
	public static void main(String[] args) {
		String s1 = new String();
		String s2 = "";
		Scanner sc = new Scanner(System.in);
		s1 = sc.nextLine();
		for(int i=0 ; i < s1.length() ; i++) {
		    char ch = s1.charAt(i);
		    if(Character.isLowerCase(ch)) {
		       System.out.print(Character.toUpperCase(ch));
		    }
		    else if(Character.isUpperCase(ch)) {
                System.out.print(Character.toLowerCase(ch));
		    }
	}
}
}
