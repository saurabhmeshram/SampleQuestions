#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */

void *start_routine(void *p)
{
    pid_t tid = syscall(SYS_gettid);
    printf("In Thread ID: [%ld]\n", (long int)tid);
    pthread_join(tid, NULL);
    return NULL;
}

int main(void)
{
    pthread_t p1;
    printf("In Main\n");
    pthread_create(&p1, NULL, start_routine, NULL);
    pthread_join(p1, NULL);

    return 0;
}
