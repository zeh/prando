#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    //instead of n rows only 2 rows are build in this KnapSack table since only 2 rows are useful(current and the just previous one)
    int K[2][W+1];
    for(i=0;i<=W;i++)
    {
        K[0][i]=0;
        K[1][i]=0;
    }

   // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        w=0;
        //if the item number is even the result will be stored in 0th row
        if(i%2==0)
        {
            while(++w<=W)
            {
                if (wt[i] <= w)
                    K[0][w] = max(val[i] + K[1][w-wt[i]],  K[1][w]);
                else
                    K[0][w] = K[1][w];
            }
        }
        //if the item number is odd the result will be stored in 1st row
        else
        {
            while(++w<=W)
            {
                if (wt[i] <= w)
                    K[1][w] = max(val[i] + K[0][w-wt[i]],  K[0][w]);
                else
                    K[1][w] = K[0][w];
            }
        }
   }
    //depending upon the value of n, we will return from even or odd row
   if(n%2==0)
        return K[1][W];
   else
        return K[0][W];
}

int main()
{
    int n,W;
    cin>>n;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
      cin>>val[i];
    for(int i=0;i<n;i++)
      cin>>wt[i];
    cin>>W;
    cout<< knapSack(W, wt, val, n)<<endl;
    return 0;
}
