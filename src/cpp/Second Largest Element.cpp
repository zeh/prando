#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {10, 3, 1, 7, 9, 0, 2, 5, 8, 4, 6};
    int n = sizeof(a) / sizeof(int);
    int largest = INT_MIN, second_largest = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > largest)
        {
            second_largest = largest;
            largest = a[i];
        }
        if(a[i] > second_largest && a[i] < largest)
        {
            second_largest = a[i];
        }
    }
    cout << second_largest << endl;
}
