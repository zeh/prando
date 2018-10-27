#include <iostream>
#include <math.h>

using namespace std;

// Fuction for checking whether a number is perfect or not 
bool is_perfect(int n){
    int i,j;
    int sm = 1;
    for(i = 2; i<=sqrt(n); i++){
        if(n % i == 0){
            sm = sm + i + n/i ;
        }
    }
    
    if(n != 1 && sm == n )
        return true;
    else
        return false;
}

int main()
{
    int l,u;
    cin>>l>>u;
    for(int i = l  ;i<=u ; i++){
        if( is_perfect(i) ) {
            cout<<i<<" ";
        }
    }
    
    return 0;
}
