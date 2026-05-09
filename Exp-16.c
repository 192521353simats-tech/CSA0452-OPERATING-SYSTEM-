#include <stdio.h>
struct employee
{
    int id;
    char name[20];
    float salary;
};
int main()
{
    FILE *fp;
    struct employee e;
    fp = fopen("employee.dat", "wb+");
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Employee Name: ");
    scanf("%s", e.name);
    printf("Enter Salary: ");
    scanf("%f", &e.salary);
    fwrite(&e, sizeof(e), 1, fp);
    rewind(fp);
    fread(&e, sizeof(e), 1, fp);

    printf("\nEmployee Details\n");
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Salary: %.2f\n", e.salary);
    fclose(fp);

    return 0;
}
