#include <stdio.h>
#include <string.h>
struct file
{
    char fname[20];
};
int main()
{
    struct file f[10];
    int n, i;
    printf("Enter number of files: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter file %d name: ", i+1);
        scanf("%s", f[i].fname);
    }
    printf("\nFiles in Single Level Directory:\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\n", f[i].fname);
    }
    return 0;
}
