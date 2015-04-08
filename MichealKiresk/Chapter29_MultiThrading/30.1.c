#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */

static int global;

void *start_routine(void *ptr)
{
    int j, local;
    int loops =  *((int *)ptr);
    for (j = 0; j < loops; j++) 
    {
	local = global;
	local++;
	global = local;
    }
    return NULL;
}

int main(void)
{
    pthread_t p1, p2;
    int loop = 1000;

    pthread_create(&p1, NULL, start_routine, &loop);
    pthread_create(&p2, NULL, start_routine, &loop);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Value of global: [%d]\n", global);
    return 0;
}
