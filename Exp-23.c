#include <stdio.h>
int main()
{
    int block[10], process[10];
    int m, n, i, j;
    printf("Enter number of blocks: ");
    scanf("%d", &m);
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);
    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &process[i]);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(block[j] >= process[i])
            {
                printf("Process %d allocated to Block %d\n", i+1, j+1);
                block[j] -= process[i];
                break;
            }
        }
    }
    return 0;
}
