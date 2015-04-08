#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 10

sem_t sem;
int sem_val;

long *sqr(long *a)
{
    *a *= *a;
    return a;
}

int main(void)
{
    int i, value = 0, *ret = NULL;
    void *exit_status = NULL;
    pthread_t parr[SIZE];

    sem_init(&sem, 0, 1);
    /* Where sem is a semaphore with an initial value "1" and "0" means it is shared between threads of a process */

    sem_getvalue(&sem, &sem_val);
    printf("Current Sem Value: [%d]\n", sem_val);

    for (i=0; i<SIZE; i++) 
    {	
	value = i;
	sem_wait(&sem);

	pthread_create(&parr[i], NULL, (void *) sqr, &value);

	pthread_join(parr[i], &exit_status);	
	ret = (int *) exit_status;

	printf("Thread %d returned value %d\n", i, *ret);
	sem_post(&sem);
    }
    return 0;
}
