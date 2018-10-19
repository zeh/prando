#include <stdio.h>
#include <conio.h>

void main() {
	int n;

	int pid[20],btime[20],wtime[20],ttime[20],i=0,avgwtime,avgttime;
	printf("Enter the number of processes");
	scanf("%d",&n);
	printf("Enter burst time of each process\n");
	while(i<n) {
		scanf("%d",&btime[i]);
		i++;
	}
	wtime[0] = 0;
	while (i<n) {
		wtime[i+1] = wtime[i] + btime[i];
		ttime[i] = wtime[i] + btime[i];
		i++;
	}
	
	printf("Process id\t Burst time\t Wait time\t Turn around time\n");
	while (i<n) {
		//printf("The burst time, wait time, turn around time of process %d is\n",pid[i] );
		printf("%d\t",pid[i]);
		printf("%d\t",btime[i] );
		printf("%d\t",wtime[i] );
		printf("%d\n",ttime[i] );
		avgwtime+=wtime[i];
		avgttime+=ttime[n];
		i++;
	}
	avgttime = avgttime/n;
	avgwtime = avgwtime/n;
	printf("The average turn around time is %d seconds\n",&avgttime );
	printf("The average wait time is %d seconds\n",&avgwtime );


	

}