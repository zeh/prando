import java.io.*;
public class Permutation 
{ 
    public static void main(String[] args)throws IOException 
    { 
        InputStreamReader ob=new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(ob);
        System.out.println("Enter A String");
        String str = in.readLine(); 
        int n = str.length(); 
        permute(str, 0, n-1); 
    } 
    private static void permute(String str, int l, int r) 
    { 
        if (l == r) 
            System.out.println(str); 
        else
        { 
            for (int i = l; i <= r; i++) 
            { 
                str = swap(str,l,i); 
                permute(str, l+1, r); 
                str = swap(str,l,i); 
            } 
        } 
    } 
    public static String swap(String a, int i, int j) 
    { 
        char temp; 
        char[] charArray = a.toCharArray(); 
        temp = charArray[i] ; 
        charArray[i] = charArray[j]; 
        charArray[j] = temp; 
        return String.valueOf(charArray); 
    } 
  
} 
