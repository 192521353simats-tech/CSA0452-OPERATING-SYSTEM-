#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int source, dest;
    char buffer[100];
    int n;
    source = open("source.txt", O_RDONLY);
    dest = open("dest.txt", O_WRONLY | O_CREAT, 0644);
    if (source < 0 || dest < 0) {
        printf("Error opening file\n");
        return 1;
    }
    while ((n = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, n);
    }
    close(source);
    close(dest);
    printf("File copied successfully\n");
    return 0;
}
