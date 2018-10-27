#include<stdio.h>
main()
{
    int n,i,sn,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&sn);
        for(j=1;j<=18;j=j+2)
        {
        if(sn==6*j)
        {
            printf("%d",6*j+6*1-5);
            printf(" WS\n");
            
        }
        else if(sn==(6*j+1))
        {
            printf("%d",6*j);
            printf(" WS\n");
            
        }
        else if(sn==(6*j+2))
        {
            printf("%d",6*j-1);
            printf(" MS\n");
            
        }
        else if(sn==(6*j+3))
        {
            printf("%d",6*j-2);
            printf(" AS\n");
            
        }
        else if(sn==6*j+4)
        {
        	printf("%d",6*j-3);
        	printf(" AS\n");
		}
		else if(sn==6*j+5)
        {
        	printf("%d",6*j-4);
        	printf(" MS\n");
		}
        }
        for(j=0;j<=18;j=j+2)
        {
        if(sn==6*j)
        {
        	printf("%d",6*(j-1)-5);
        	printf(" WS\n");
		}
           else if(sn==(6*j+1))
        {
            printf("%d",6*(j+2));
            printf(" WS\n");
            
        }
        else if(sn==(6*j+2))
        {
            printf("%d",6*(j+2)-1);
            printf(" MS\n");
            
        }
        else if(sn==(6*j+3))
        {
            printf("%d",6*(j+2)-2);
            printf(" AS\n");
            
        }
        else if(sn==(6*j+4))
        {
            printf("%d",6*(j+2)-3);
            printf(" AS\n");
            
        }
        else if(sn==(6*j+5))
        {
            printf("%d",6*(j+2)-4);
            printf(" MS\n");
            
        }

        }
    }
}
