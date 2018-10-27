class CountOccurancesInSortedArray 
{ 
    static int countOccurrences(int arr[], int x) 
    { 
        int count = 0; 
        for (int i=0; i<arr.length; i++) 
            if (x == arr[i]) 
              count++; 
        return count; 
    } 
      
    public static void main(String args[]) 
    { 
        int arr[] = {1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 6, 6, 7 ,8 ,8 }; 
        int x = 3; 
        System.out.println(x + " occurs in the array " + countOccurrences(arr, x) + " times."); 
    } 
} 