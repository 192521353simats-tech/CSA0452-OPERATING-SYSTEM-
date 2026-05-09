#include <stdio.h>
struct directory
{
    char user[20];
    char file[20];
};
int main()
{
    struct directory d[10];
    int n, i;
    printf("Enter number of entries: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter user name: ");
        scanf("%s", d[i].user);
        printf("Enter file name: ");
        scanf("%s", d[i].file);
    }
    printf("\nTwo Level Directory Structure:\n");
    for(i = 0; i < n; i++)
    {
        printf("User: %s -> File: %s\n", d[i].user, d[i].file);
    }
    return 0;
}
