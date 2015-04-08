#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */

static int st;
pthread_mutex_t mtx;

void *start_routine1(int ptr)
{
    int s = 0;
    pthread_mutex_lock(&mtx);
    st++;
    printf("Thread [%d]\t[%d]\n", ptr, st);
    s = pthread_mutex_unlock(&mtx);
    if (s < 0)
	printf("[%s]\n", strerror(s));
    return NULL;
}

void *start_routine2(int ptr)
{
    int s = 0;
    pthread_mutex_lock(&mtx);
    st++;
    printf("Thread [%d]\t[%d]\n", ptr, st);
    s = pthread_mutex_unlock(&mtx);
    if (s < 0)
	printf("[%s]\n", strerror(s));
    return NULL;
}

void *start_routine3(int ptr)
{
    int s = 0;
    pthread_mutex_lock(&mtx);
    st++;
    printf("Thread [%d]\t[%d]\n", ptr, st);
    s = pthread_mutex_unlock(&mtx);
    if (s < 0)
	printf("[%s]\n", strerror(s));
    return NULL;
}

int main(void)
{
    pthread_t p[3];
    int i = 0;
    void *(*fp[3])(int) = {start_routine1, start_routine2, start_routine3};

    for (i = 0; i < 3; i++)
    {
	pthread_create(&p[i], NULL, fp[i], (void *) i);
//	pthread_join(p[i], NULL);
    }
sleep(10);
    return 0;
}
