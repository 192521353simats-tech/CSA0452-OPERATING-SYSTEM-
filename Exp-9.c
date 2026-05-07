#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int shmid;
    char *str;
    shmid = shmget((key_t)1122, 1024, 0666 | IPC_CREAT);
    str = (char*) shmat(shmid, NULL, 0);
    strcpy(str, "Hello from Parent Process");

    if(fork() == 0)
    {
        sleep(1);
        printf("Child Process Reads: %s\n", str);
    }
    else
    {
        printf("Parent Process Writes: %s\n", str);
    }
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
