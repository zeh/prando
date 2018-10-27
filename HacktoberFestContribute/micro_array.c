#include <stdio.h>
int main()
{
int n,t,i,j;
long int k,min,arr[100000];
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%d %ld",&n,&k);
for(j=0;j<n;j++)
{
scanf("%ld",&arr[j]);
}
min=arr[0];
for(j=1;j<n;j++)
{
if(arr[j]<=min)
min=arr[j];
}
if(min>=k)
printf("0\n");
else
printf("%ld\n",k-min);
} 
return 0;
}
