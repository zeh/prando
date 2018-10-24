// Priority Scheduling Algorithm
#include <iostream>

int main() {

  int* bt  = nullptr; // burst time
  int* wt  = nullptr; // wait time
  int* tat = nullptr; // turn around time
  int* pr  = nullptr; // priority
  int* p   = nullptr; // process number

  int n; // number of processes

  int i, j;

  int total   = 0;
  int avg_wt  = 0; // average waiting time
  int avg_tat = 0; // average turnaround time

  std::cout << "\nEnter total number of processes\n";
  std::cin >> n;

  bt  = new int[n]; // Allocate n ints and save ptr in array
  wt  = new int[n];
  tat = new int[n];
  pr  = new int[n];
  p   = new int[n];

  for(int i = 0; i < n; ++i) {
    bt[i]  = 0; // Initialize all elements to zero
    wt[i]  = 0;
    tat[i] = 0;
    pr[i]  = 0;
    p[i]   = 0;
  }

  std::cout << "\nEnter Burst Time and Priority:\n";
  for(i = 0; i < n; ++i) {
    std::cout<<"\nP["<<i+1<<"]\n";
    std::cout<<"Burst Time:";
    std::cin>>bt[i];
    std::cout<<"Priority:";
    std::cin>>pr[i];
    p[i]=i+1;           //contains process number
  }

  //sorting burst time, priority and process number in ascending order using selection sort
  for(i = 0; i < n; ++i) {
    int pos = i;
    for(j = i + 1; j < n; ++j) {
      if(pr[j] < pr[pos])
        pos = j;
    }

    int temp = pr[i];
    pr[i] = pr[pos];
    pr[pos] = temp;

    temp = bt[i];
    bt[i] = bt[pos];
    bt[pos] =temp;

    temp = p[i];
    p[i] = p[pos];
    p[pos] = temp;
  }

  wt[0] = 0; //waiting time for first process is zero

  //calculate waiting time
  for(i = 1; i < n; ++i) {
    wt[i] = 0;
    for(j = 0; j < i; ++j)
      wt[i] += bt[j];

    total += wt[i];
  }

  avg_wt = total/n; //average waiting time
  total = 0;

  std::cout<<"\nProcess\tBurst Time\tWaiting Time\tTurnaround Time";
  for(i = 0; i < n; ++i) {
    tat[i] = bt[i] + wt[i]; //calculate turnaround time
    total += tat[i];
    std::cout<<"\nP[" << p[i] << "]\t\t" << bt[i] << "\t\t" <<wt[i] << "\t\t\t" <<tat[i];
  }

  avg_tat=total/n; //average turnaround time
  std::cout<<"\n\nAverage Waiting Time="<<avg_wt;
  std::cout<<"\nAverage Turnaround Time="<<avg_tat;

  // Free memory and clear to prevent access to invalid memory
  bt = nullptr;
  delete bt;
  wt = nullptr;
  delete wt;
  tat = nullptr;
  delete tat;
  return 0;
  delete pr;
  return 0;
  delete p;
  return 0;
}
