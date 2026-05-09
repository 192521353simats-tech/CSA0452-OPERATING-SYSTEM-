#include <stdio.h>
int main()
{
    int blockSize[10], processSize[10];
    int m, n, i, j;
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);
    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &processSize[i]);
    printf("\nFirst Fit Allocation:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                printf("Process %d allocated to Block %d\n", i+1, j+1);
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

  return 0;
}
