#include <stdio.h>
int main() {
    int n, i, j, temp, bt[20], p[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        p[i] = i + 1; 
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0; 
    printf("\nPID\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        if(i > 0) wt[i] = wt[i-1] + bt[i-1];
        tat[i] = bt[i] + wt[i];
        
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);
    return 0;
}
