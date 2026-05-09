#include <stdio.h>
int main()
{
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10];
    int safe[10];
    int n, m, i, j, k = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);
    for(i = 0; i < n; i++)
    {
        finish[i] = 0;
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;
                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    safe[k] = i;
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                }
            }
        }
    }
    printf("\nSafe Sequence:\n");
    for(i = 0; i < n; i++)
        printf("P%d ", safe[i]);

    return 0;
}
