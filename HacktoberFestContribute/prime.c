#include<stdio.h>
main()
{
    int num,i,j,sum;
    scanf("%d",&num);
    for(i=2;i<num;i++)
    {
        sum=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            sum++;
        }
        if(sum==2)
        printf("%d ",i);
    }
    
}
