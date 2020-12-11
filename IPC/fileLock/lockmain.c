// #include "unpipc.h"


#define SEQFILE "seqno" /* file name */

void my_lock(int), my_unlock(int);

int main(int argc, char **argv) {
    int fd;
    long i, seqno;
    pid_t pid;
    ssize_t n;
    char line[MAXLINE + 1];

    pid = getpid();
    // fd = 





}