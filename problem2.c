#include <stdio.h>

int main() {
 int n = 5;
int pid[] = {1, 2, 3, 4, 5};           
int at[]  =   {0, 1, 2, 3, 0};           
int bt[]  =  {3, 2, 1, 4, 2};           
 int ct[5], tat[5], wt[5], done[5] = {0};

    int time = 0, completed = 0;

    while (completed < n) {
     int shortest = -1;
     int min_bt = 9999;

        
        for (int i = 0; i < n; i++) {
        if (!done[i] && at[i] <= time && bt[i] < min_bt) {
             min_bt = bt[i];
              shortest = i;
            }
        }

        if (shortest != -1) {
         time += bt[shortest];
    ct[shortest] = time;
    tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];
        done[shortest] = 1;
        completed++;
        } else {
            time++; 
        }
    }

   
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
