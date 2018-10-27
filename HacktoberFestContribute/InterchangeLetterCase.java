import java.util.Scanner;

public class InterchangeLetterCase {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Input string: ");

    String line = scanner.nextLine();

    StringBuilder builder = new StringBuilder();

    for (int i = 0; i < line.length(); i++) {
      if (Character.isUpperCase(line.codePointAt(i))) {
        builder.append(Character.toLowerCase(line.charAt(i)));
      } else {
        builder.append(Character.toUpperCase(line.charAt(i)));
      }
    }

    System.out.println(builder.toString());
  }
}