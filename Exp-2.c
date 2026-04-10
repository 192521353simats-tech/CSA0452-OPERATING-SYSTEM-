#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int src, dst;
    char buf[1024];
    ssize_t n;

    if (argc != 3) return printf("Usage: %s <src> <dst>\n", argv[0]), 1;
    src = open(argv[1], O_RDONLY);
    dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (src < 0 || dst < 0)
    {
        perror("Error opening files");
        return 1;
    }
    while ((n = read(src, buf, sizeof(buf))) > 0)
    {
        write(dst, buf, n);
    }
    close(src);
    close(dst);
    printf("Copy complete.\n");
    return 0;
}
