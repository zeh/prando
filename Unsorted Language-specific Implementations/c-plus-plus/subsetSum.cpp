#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
   return isSubsetSum(set, n-1, sum) ||
                        isSubsetSum(set, n-1, sum-set[n-1]);
}
int main()
{
  int set[10000],n,sum;
  //enter the size of set
  cin>>n;
  //enter the elements of set
  for(int i=0;i<n;i++)
  cin>>set[i];
  //enter the required sum
  cin>>sum;
  if (isSubsetSum(set, n, sum) == true)
     cout<<"Found a subset with given sum";
  else
     cout<<"No subset with given sum";
  return 0;
}
