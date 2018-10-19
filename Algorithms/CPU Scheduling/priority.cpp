#include<stdio.h>

 float pid[10],btime[10],wtime[10],ttime[10],n,await=0,atur=0,q=0,pr[10];
 int i,j;
 int main()
 {
    printf("Enter number of processes");
    scanf("%f",&n);

    //burst input
    printf("Enter burst time of %.0f processes",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&btime[i]);
    }

    //priority
    printf("Enter priority of %.0f processes",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&pr[i]);
    }

    //pid allotment
    for(i=0;i<n;i++)
    {
        pid[i]=i+1;
    }

    //sorting
    for(j=0;j<n-1;j++)
    {
        for(int k=0;k<n-j-1;k++)
        {
            if(pr[k]>pr[k+1])
            {
                //priority
                float temp=pr[k];
                pr[k]=pr[k+1];
                pr[k+1]=temp;
                //pid
                float temp1=pid[k];
                pid[k]=pid[k+1];
                pid[k+1]=temp1;
                //btime
                float temp2=btime[k];
                btime[k]=btime[k+1];
                btime[k+1]=temp2;
            }
        }
    }
    printf("sorted elements are: ");
    for(i=0;i<n;i++)
    {
        printf("prio :%f\n",pr[i]);
        printf("pid: %.0f\n",pid[i]);
        printf("btime:  %.0f\n",btime[i]);
    }

    wtime[0]=0;

    //calc wtime and ttime
	for(i=0;i<n;i++)
	{
	    wtime[i+1]=wtime[i]+btime[i];
	    ttime[i]=wtime[i]+btime[i];
	}

	//average
	for(i=0;i<n;i++)
	{
	     await=wtime[i]+await;
	     atur=atur+ttime[i];
	}
	await=await/n;
	atur=atur/n;

	//display
	printf("average wiating time:  %f",await);
	printf("\naverage turn around time:  %f",atur);
    printf("\n\n");
	for(i=0;i<n;i++)
	{
	   //burst time
	   printf("\n burst time of process %.0f is: %f",pid[i],btime[i]);

	   //turn around time
	   printf("\n turn around time of process %.0f is: %f",pid[i],ttime[i]);

	   //wtime
	   printf("\n waiting time of process %.0f is: %f\n\n",pid[i],wtime[i]);
	}

	   printf("\n\n\n\t\t __GANTT CHART__\n\n\n|");
        for(i=0;i<n;i++)
        {
            for(j=0;j<btime[i]/2;j++)
            {
                printf("   ");
            }
            printf(" P%.0f ",pid[i]);
            for(j=0;j<btime[i]/2;j++)
            {
                printf("   ");
            }
            printf("|");
        }
        printf("\n");
        printf("0");

        for(i=0;i<n;i++)
        {
            for(j=0;j<btime[i]/2;j++)
            {
                printf("   ");
            }
            printf("    ");
            for(j=0;j<btime[i]/2;j++)
            {
                printf("   ");
            }
            q=q+btime[i];

            printf("%.0f",q);
        }


    return 0;
 }
