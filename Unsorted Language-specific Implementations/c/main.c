#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long int n;
    scanf("%lld",&n);
    if(!(n&(n-1)))
        printf("%d is a power of 2",n);
    else
        printf("%d isn't a power of 2",n);
    return 0;
}
