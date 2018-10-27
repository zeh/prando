// calculating nth fibonacci number using 
// recursive + memoization approach
// or top down approach

#include <iostream>
using namespace std;

#define Max 100

void initialize(int lookup[])
{
    for(int i=0;i<Max;i++)
    {
        lookup[i]=-1;
    }
}

// solved using memoziation technique
int fib(int n,int lookup[])
{
    if(lookup[n]==-1)
    {
        if(n<=1)
            lookup[n]=n;
        else
            lookup[n]=fib(n-1,lookup)+fib(n-2,lookup);
    }
    return lookup[n];
}

int main()
{
    int n,result;
    cin>>n;
    int lookup[Max];
    initialize(lookup);
    result=fib(n,lookup);
    cout<<result;	
}