#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], ct[n], tat[n], wt[n];
    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    int current_time = 0;
    for(i = 0; i < n; i++) {
        current_time += bt[i];
        ct[i] = current_time;
        
        tat[i] = ct[i];      
        wt[i] = tat[i] - bt[i];
        
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nPID\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], ct[i], tat[i], wt[i]);
    printf("\nAverage Waiting Time: %.2f", total_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}
