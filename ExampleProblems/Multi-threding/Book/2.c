#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 3

sem_t sem;
int semid;                                                              
union semun un;                                                         
un.val = 0;                                                             
struct sembuf sops[3]; 

void foo(void)
{
 
}

int main(void)
{
    int i;
    pthread_t p[SIZE];

for (i=0; i<SIZE; i++) 
{
    pthread_create(&p[i], NULL, (void *) foo, i);
    pthread_join(p[i], NULL);	
}

    return 0;
}
