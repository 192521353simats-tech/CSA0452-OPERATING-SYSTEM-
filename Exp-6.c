#include <stdio.h>
int main() {
    int n, i, time = 0, count = 0, short_p;
    int at[10], bt[10], pr[10], rt[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("P%d Arrival, Burst, Priority: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i]; 
    }
    pr[9] = 9999; 
    printf("\nProcess Execution Sequence:\n");
    while(count != n) {
        short_p = 9; 
        for(i = 0; i < n; i++) {
            if(at[i] <= time && pr[i] < pr[short_p] && rt[i] > 0)
                short_p = i;
        }

        rt[short_p]--; 
        if(rt[short_p] == 0) {
            count++;
            printf("P%d finished at %d\n", short_p + 1, time + 1);
        }
        time++;
    }
    return 0;
}
