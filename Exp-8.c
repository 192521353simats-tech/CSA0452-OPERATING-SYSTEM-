#include <stdio.h>
int main() {
    int n, i, tq, time = 0, count = 0, bt[10], rt[10], wt[10], tat[10];
    float awt = 0, atat = 0;
    printf("Enter n and Quantum: ");
    scanf("%d %d", &n, &tq);
    for(i = 0; i < n; i++) {
        printf("P%d BT: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; 
    }
    while(count < n) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    tat[i] = time;
                    rt[i] = 0;
                    count++;
                }
            }
        }
    }
    printf("\nPID\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
        awt += wt[i]; atat += tat[i];
    }
    printf("\nAvg WT: %.2f\nAvg TAT: %.2f\n", awt/n, atat/n);
    return 0;
}
