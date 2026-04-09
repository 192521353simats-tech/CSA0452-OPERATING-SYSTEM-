#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    } else if (pid == 0) {
        // Child process
        printf("Child  | PID: %d | Parent PID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent | PID: %d | Child PID: %d\n", getpid(), pid);
    }

    return 0;
}
