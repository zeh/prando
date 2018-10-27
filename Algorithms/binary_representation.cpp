#include <iostream>
void bin(unsigned n)
{
    unsigned i;
    for (i = (1 << 31) ; i > 0; i = (i>>1))
        if(n & i)
			std::cout<<"1";
		else
			std::cout<<"0";
}
 
int main(void)
{
	unsigned n ;
	std::cin >> n; 
    bin(n);
}
