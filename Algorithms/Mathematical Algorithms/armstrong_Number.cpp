#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    std::cin >> n;
    int n1 = n;
    int sm = 0;
    while(n1){
        int d = n1%10 ;
        sm = sm + pow(d,3);
        n1 = n1/10;
    }
    
    if(sm == n){
        std::cout << n << " is an armstrong nunmber" << std::endl;
    }
    else {
        std::cout << n << " is not an armstrong number" << std::endl;
    }
    
    return 0;
}
