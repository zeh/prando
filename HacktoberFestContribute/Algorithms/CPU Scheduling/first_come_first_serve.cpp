/*
- Jobs are executed on first come, first serve basis.
- It is a non-preemptive, pre-emptive scheduling algorithm.
- Easy to understand and implement.
- Its implementation is based on FIFO queue.
- Poor in performance as average wait time is high.
*/

#include <iostream>

int main() {

  int* bt  = nullptr; // burst time
  int* wt  = nullptr; // wait time
  int* tat = nullptr; // turn around time

  int n; // number of processes

  int average_wait_time  = 0;
  int average_turnaround = 0;

  int i, j;

  std::cout << "\nEnter total number of processes\n";
  std::cin >> n;

  bt  = new int[n]; // Allocate n ints and save ptr in array
  wt  = new int[n];
  tat = new int[n];

  for(int i = 0; i < n; ++i) {
    bt[i] = 0; // Initialize all elements to zero
    wt[i] = 0;
    tat[i] = 0;
  }

  std::cout << "\nEnter process burst time\n";
  for(i = 0; i < n; ++i) {
    std::cout << "P[" << i + 1 << "]:";
    std::cin >> bt[i];
  }

  wt[0] = 0; // waiting time for first process is zero

  // calculate wait time
  for(i = 1; i < n; ++i) {
    wt[i] = 0;
    for(j = 0; j < i; ++j) {
      wt[i] += bt[j];
    }
  }

  std::cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
  // calculate turnaround time
  for(i = 0; i < n; ++i) {
    tat[i] = bt[i] + wt[i];
    average_wait_time += wt[i];
    average_turnaround += tat[i];
    std::cout << "\nP[" << i + 1 << "]\t\t" << bt[i] << "\t\t" << wt[i] <<
    "\t\t" << tat[i];
  }

  std::cout << "\nAverage waiting time: " << average_wait_time / i;
  std::cout << "\nAverage turn around time: " << average_turnaround /i;

  bt = nullptr;
  delete bt;
  wt = nullptr;
  delete wt;
  tat = nullptr;
  delete tat;

  return 0;
}
