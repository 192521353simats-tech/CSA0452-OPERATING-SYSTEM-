#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd;
    char buffer[100];
    int n;
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);
    printf("Enter some text to write in file: ");
    fgets(buffer, sizeof(buffer), stdin);
    write(fd, buffer, strlen(buffer));
    lseek(fd, 0, SEEK_SET);
    n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("\nContent of file: %s", buffer);
    close(fd);
    return 0;
}
