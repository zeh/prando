#include <stdio.h>
#include <stdlib.h>
int main()
{
int n,i,j;
scanf("%d",&n);
int a[n],b[n];
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
b[n-1]=a[n-1];
for(i=n-2;i>=0;i--)
{
if(a[i]<b[i+1])
b[i]=b[i+1];
else
b[i]=a[i];
}
for(i=0;i<n;i++)
{
if(a[i]>=b[i]) printf("%d ",a[i]);
}

return 0;
}
