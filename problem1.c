#include <stdio.h>

struct Process {
int pid;
int arrival_time;
int burst_time;
int completion_time;
int turnaround_time;
int waiting_time;
};

int main() {
  int n = 4;
  struct Process p[] = {
       {1, 0, 3},
       {2, 1, 2},
       {3, 2, 1},
      {4, 3, 4}
    };

    int time = 0;

    for (int i = 0; i < n; i++) {
        
 if (time < p[i].arrival_time) {
           time = p[i].arrival_time;
        }

    p[i].completion_time = time + p[i].burst_time;
                time = p[i].completion_time;

    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
          for (int i = 0; i < n; i++) {
           printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
            p[i].pid, 
            p[i].arrival_time, 
            p[i].burst_time, 
            p[i].completion_time, 
            p[i].turnaround_time, 
            p[i].waiting_time
        );
    }

    return 0;
}
