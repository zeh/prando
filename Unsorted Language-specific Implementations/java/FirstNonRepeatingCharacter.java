
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map; 

class Index { 
  int count;
  int index; 
  
  public Index(int index) { 
      this.count = 1; 
      this.index = index; 
  } 
  
  public void incrementCount() { 
      this.count++; 
  } 
} 

public class FirstNonRepeatingCharacter {

  static final int NO_OF_CHARS = 256; 
  
  static HashMap<Character, Index> hm = new HashMap<>(NO_OF_CHARS); 

  static void getCharCountArray(String str) { 
    for (int i = 0; i < str.length();  i++)  {

        if(hm.containsKey(str.charAt(i))) { 
            hm.get(str.charAt(i)).incrementCount(); 
        }
        else { 
            hm.put(str.charAt(i), new Index(i)); 
        } 
              
    }     
  } 

  static int firstNonRepeatingCharacter(String str) {
    getCharCountArray(str); 
    int result = Integer.MAX_VALUE, i; 
    
    for (i = 0; i < str.length();  i++) { 
          // If this character occurs only once and appears 
        // before the current result, then update the result 
        if (hm.get(str.charAt(i)).count == 1 && result > hm.get(str.charAt(i)).index){ 
              result = hm.get(str.charAt(i)).index; 
        } 
            
    }   
        
    return result; 
  }
  public static void main (String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Input String: ");
    String str = scanner.nextLine();
    int index = firstNonRepeatingCharacter(str); 
      
    System.out.println(index == Integer.MAX_VALUE ? "Either all characters are repeating " + 
            " or string is empty" : "First non-repeating character is " +  str.charAt(index)); 
  } 
}