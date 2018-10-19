
import java.util.Arrays;

/**
 * Case-sensitive implementation of Issue #275 (https://github.com/rathoresrikant/HacktoberFestContribute/issues/275)
 *
 */
public class StringAnagram {

    /**
     * Main method example
     * Calls method two times. Contains one success and one fail example.
     *
     */
    public static void main() {
        boolean successExample = determineIfStringsAreAnagrams("Hello there", "ereht olleH");
        boolean failExample = determineIfStringsAreAnagrams("General Kenobi!", "!ibonek lareneg");

        System.out.println(successExample);
        System.out.println(failExample);
    }

    /**
     * Determine if two given strings are anagrams.
     *
     * Method doesn't support empty strings.
     * Possible NullPointerException and UnsupportedOperationException.
     *
     * @param firstString First String to compare
     * @param secondString Second String to compare
     * @return boolean whether the given Strings are anagrams.
     */
    private static boolean determineIfStringsAreAnagrams(String firstString, String secondString) {

        if ((firstString == null) || (secondString == null)) {
            throw new NullPointerException("Are you sure, that you didn't give me an null object there?");
        }

        if ((firstString.isEmpty()) || (secondString.isEmpty())) {
            throw new UnsupportedOperationException("You shouldn't give me an empty string.");
        }

        if (firstString.length() != secondString.length()) {
            return false;
        }

        char[] firstStringAsChars = firstString.toCharArray();
        char[] secondStringAsChars = secondString.toCharArray();

        Arrays.sort(firstStringAsChars);
        Arrays.sort(secondStringAsChars);

        return Arrays.equals(firstStringAsChars, secondStringAsChars);
    }

}