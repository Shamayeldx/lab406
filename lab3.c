#include <stdio.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
} Process;

 int main() {
 int n = 5, tq = 2; 
    Process p[5] = {
        {1, 0, 5, 5, 0, 0, 0},
     {2, 1, 3, 3, 0, 0, 0},
        {3, 2, 1, 1, 0, 0, 0},
        {4, 3, 2, 2, 0, 0, 0},
        {5, 4, 3, 3, 0, 0, 0}
 };

 int time = 0, completed = 0;
    int queue[100], front = 0, rear = 0, visited[5] = {0};
  
for (int i = 0; i < n; i++) {
      if (p[i].arrival == 0) {
        queue[rear++] = i;
            visited[i] = 1;
        }
    }

while (completed < n) {
  if (front == rear) {
 time++; 
     for (int i = 0; i < n; i++) {
  if (!visited[i] && p[i].arrival <= time) {
 queue[rear++] = i;
     visited[i] = 1;
          }
     }
     continue;
        }

     int idx = queue[front++];
      if (p[idx].remaining > tq) {
      time += tq;
      p[idx].remaining -= tq;
        } else {
    time += p[idx].remaining;
     p[idx].remaining = 0;
     p[idx].completion = time;
     completed++;
        }

      
        for (int i = 0; i < n; i++) {
        if (!visited[i] && p[i].arrival <= time) {
          queue[rear++] = i;
          visited[i] = 1;
            }
        }

       
    if (p[idx].remaining > 0) {
         queue[rear++] = idx;
        }
    }

 float totalTAT = 0, totalWT = 0;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
        totalTAT += p[i].turnaround;
        totalWT += p[i].waiting;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage TAT = %.2f", totalTAT / n);
    printf("\nAverage WT = %.2f\n", totalWT / n);

    return 0;
}
