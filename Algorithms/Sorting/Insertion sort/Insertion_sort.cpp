#include <bits/stdc++.h> 
using namespace std;
  
// Insertion sort function
void insertion_sort(int arr[], int n) 
{ 
   int i, k, j; 
   for (i = 1; i < n; i++) 
   { 
       k = arr[i]; 
       j = i-1; 
        while (j >= 0 && arr[j] > k) 
          { 
             arr[j+1] = arr[j]; 
             j = j-1; 
          } 
       arr[j+1] = k; 
   } 
}

int main()
{
  int n;
  cin >> n;
  int* arr = new int[n];
  for(int i = 0 ; i <  n ; i++)
    cin >> arr[i];
  insertion_sort(arr , n);
  cout << "Sorted array :\n";
  for(int i = 0 ; i <  n ; i++)
    cout << arr[i] << " ";

} 
