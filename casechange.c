#include<stdio.h>

int main()
{
int size,i=0;
scanf("%d ",&size);
char A[size];
for(i=0;i<size;i++)
scanf("%c%*c",&A[i]);

for(i=0;i<size;i++){
if(A[i]>='a' && A[i]<='z')
A[i]=A[i]-32;
else if(A[i]>='A' && A[i]<='Z')
A[i]=A[i]+32;
}

for(i=0;i<size;i++){
printf("%c",A[i]);}
return 0;
}
