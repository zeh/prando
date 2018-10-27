// Extended Euclid Gcd is often useful in finding inverse of 
// number mod n efficently. If gcd=1, then equation will turned to be
// 1=x*a+y*b, no taking modulo with b we get x as inverse of 
// a mod b
#include <bits/stdc++.h>
using namespace std;

// (d,x,y) is tuple
struct gcd_tuple{
    int d;
    int x;
    int y;
};

// evaluate gcd using Extended-Euclid-Gcd
// d=x*a+b*y
// d is gcd of a and b
// and is smallest number that can be expressed in this form.
// extended_euclid_gcd(a,b){
    // (d,x,y)=extended_euclid_gcd(b,a%b);
    // a=b*q+r;
    // return (d,y,x-y*q);
// }
struct gcd_tuple extended_euclid_gcd(int a,int b)
{
    struct gcd_tuple e_gcd;
    if(b==0)
    {
        e_gcd.d=a;
        e_gcd.x=1;
        e_gcd.y=0;
        return e_gcd;
    }    

    e_gcd=extended_euclid_gcd(b,a%b);
    int q=a/b;
    int x=e_gcd.x;
    int y=e_gcd.y;
    e_gcd.x=y;
    e_gcd.y=x-y*q;

    return e_gcd;
}

// output format is d=a*x+b*y
int main(){

    int a,b;
    cin>>a>>b;
    struct gcd_tuple e_gcd;
    e_gcd=extended_euclid_gcd(a,b);
    cout<<e_gcd.d<<"="<<a<<"*"<<e_gcd.x<<"+"<<b<<"*"<<e_gcd.y;
}