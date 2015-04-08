#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<pthread.h>


void * func(int a)
{
    printf("\t\tinside function: [%d]\n", a);
    return NULL;
}

int main()
{
    pthread_t *ptr;
    int i, val=10;
    ptr = malloc (sizeof(pthread_t) * val);

    for(i=0; i<val; i++) 
    {
	printf("creating thread %d\n",i);
	pthread_create(&ptr[i],NULL, &func, i);
    }
    return 0;
}
