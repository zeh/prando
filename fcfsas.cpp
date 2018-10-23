pbt=[]
n=input("Enter number of processes")
print("Enter burst time for each")
n=int(n)
i=0
for i in range(n):
	pbt.append(input("Burst time"))
tat=[pbt[0]]
t=pbt[0]
for i in range(1,n):
	t=t+pbt[i]
	tat.append(t)
print(tat)
wt=[]
for i in range(n):
	c=tat[i]-pbt[i]
	wt.append(c)
print(wt)
atat=0
awt=0
for i in range(n):
	atat=atat+tat[i]
	awt=awt+wt[i]
print("Average turnaround",atat/n)
print("Average waiting",awt/n)
	
