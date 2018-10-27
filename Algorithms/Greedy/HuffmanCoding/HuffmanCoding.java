import java.util.PriorityQueue; 
import java.util.Scanner; 
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map; 

class Node { 
  
    int data; 
    char c; 
  
    Node left; 
    Node right; 
} 

class MyComparator implements Comparator<Node> { 
    public int compare(Node x, Node y) 
    { 
  
        return x.data - y.data; 
    } 
} 
  
public class HuffmanCoding { 
  
    public static void printCode(Node root, String s) { 
        if (root.left 
                == null
            && root.right 
                   == null
            && Character.isLetter(root.c)) { 

            System.out.println(root.c + ":" + s); 
  
            return; 
        } 

        printCode(root.left, s + "0"); 
        printCode(root.right, s + "1"); 
    } 
  
    // main function 
    public static void main(String[] args) { 
  
        Scanner s = new Scanner(System.in); 
  
        System.out.print("Input String: ");
        String line = s.nextLine();

        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < line.length(); i++) {
          if (map.containsKey(line.charAt(i))) {
            map.put(line.charAt(i), map.get(line.charAt(i)) + 1);
          } else {
            map.put(line.charAt(i), 1);
          }
        }

        int n = map.size();

        char[] charArray = new char[map.size()]; 
        int[] charfreq = new int[map.size()];

        int k = 0;

        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
          charArray[k] = entry.getKey();
          charfreq[k] = entry.getValue();

          k++;
        }
        
        PriorityQueue<Node> q 
            = new PriorityQueue<Node>(n, new MyComparator()); 
  
        for (int i = 0; i < n; i++) { 

            Node hn = new Node(); 
  
            hn.c = charArray[i]; 
            hn.data = charfreq[i]; 
  
            hn.left = null; 
            hn.right = null; 
            
            q.add(hn); 
        } 

        Node root = null; 

        while (q.size() > 1) { 
  
            Node x = q.peek(); 
            q.poll(); 
  
            Node y = q.peek(); 
            q.poll(); 
  
            Node f = new Node(); 

            f.data = x.data + y.data; 
            f.c = '-'; 
  
            f.left = x; 
  
            f.right = y; 
  
            root = f; 
  
            q.add(f); 
        } 
        
        printCode(root, ""); 
    } 
} 