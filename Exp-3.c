#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n];
    float avg_wt = 0, avg_tat = 0;

    for(i = 0; i < n; i++) 
    {
        printf("P%d Arrival & Burst: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    for(i = 0; i < n; i++)
    {
        if (i == 0 || at[i] > ct[i-1]) 
            ct[i] = at[i] + bt[i];
        else 
            ct[i] = ct[i-1] + bt[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    printf("\nAvg Waiting Time: %.2f\n", avg_wt/n);
    return 0;
}
