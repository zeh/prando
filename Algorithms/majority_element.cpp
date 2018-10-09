#include <bits/stdc++.h> 
using namespace std; 

// find max occuring element using moore's voting algorithm
int find_max_elem(int arr[], int n) 
{ 
    int maj_idx = 0, count = 1; 
    for (int i = 1; i < n; i++) 
    { 
        if (arr[maj_idx] == arr[i]) 
            count++; 
        else
            count--; 
        if (count == 0) 
        { 
            maj_idx = i; 
            count = 1; 
        } 
    } 
    return arr[maj_idx]; 
} 
 // check if the searched element is majority 
bool ismaj(int arr[], int n, int val) 
{ 
    int count = 0; 
    for (int i = 0; i < n; i++) 
      if (arr[i] == val) 
        count++; 
    if(count > n/2) 
        return true; 
    return false;   
} 
int main() 
{ 
    // taken input size of the array
    int n;
    cin >> n;
    int*arr = new int[n];
    for(int i = 0 ; i<n ;i++)
    {
        cin >> arr[i];
    }
    int val = find_max_elem(arr , n);
    ismaj(arr , n , val)? cout << val << "\n" : cout << "No majority element .\n";
    delete[] arr;
    return 0; 
} 