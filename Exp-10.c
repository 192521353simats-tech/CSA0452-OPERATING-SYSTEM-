#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    struct message msg;

    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

    msg.msg_type = 1;

    printf("Enter message: ");
    fgets(msg.msg_text, 100, stdin);

    msgsnd(msgid, &msg, sizeof(msg), 0);

    msgrcv(msgid, &msg, sizeof(msg), 1, 0);

    printf("Message Received: %s", msg.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
