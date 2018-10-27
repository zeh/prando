#include<iostream>

using namespace std;

int main()
{
	int n;
	long long int sum = 0;
	scanf("%d", &n);
	for(int i=3 ; i<=n ; i++ )
	{
		if(i%3==0 || i%5==0)
			sum += i;
	}
	printf("%lld\n", sum);
}
