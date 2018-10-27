#include <stdio.h>
#include <string.h>

void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*y;
	*y=temp;
}

void permute(char *s,int l,int r)
{
	int i;
	if(l==r)
		printf("%s\n",s);

	else
	{
		for(i=l;i<=r;i++)
		{
			swap((s+l),(s+i));
			permute(s,l+1,r);
			swap((s+l),(s+i));
		}
	}
}

int main()
{
	char str[]="permutations";
	int n=strlen(str);
	permute(str,0,n-1);
	return 0;
}