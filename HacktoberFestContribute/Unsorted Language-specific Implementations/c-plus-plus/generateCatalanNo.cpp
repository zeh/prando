// Complexity analysis
// catalan number grows exponentially 
// Time complexity of following program is O(n)

#include <iostream>
using namespace std;

// / Returns value of Binomial Coefficient C(n, k) 
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
    unsigned long int res = 1; 

    if (k > n - k) 
        k = n - k; 

    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res; 
} 

unsigned long int catalan(unsigned int n) 
{ 
    // Calculate value of 2nCn 
    unsigned long int c = binomialCoeff(2*n, n); 
    // return 2nCn/(n+1) 
    return c/(n+1); 
} 

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<catalan(i)<<" ";
    }
    cout<<endl;
}