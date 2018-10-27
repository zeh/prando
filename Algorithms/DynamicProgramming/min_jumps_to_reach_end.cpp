#include <bits/stdc++.h>
using namespace std;
int minjump(vector <int> arr)
{
    int n = arr.size(),i;
	int maxReach = arr[0], step = arr[0], jump = 1;
    for(int i=1;i<n;i++)
    {
        if(i == arr.size() -1)
        return jump;
        maxReach = max(maxReach,i+arr[i]);
        step--;
        if(step==0)
        {
            jump++;
            if(i >= maxReach)
            return -1;
            step = maxReach - i;
        }
    }
    return jump;
}
int main() {
    vector <int> arr = {1, 3, 6, 1, 0, 9};
	cout<<minjump(arr);
	return 0;
}
	
