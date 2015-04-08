/*
Program to print Even and Odd Numbers using two Threads
Threads have to Snycronised using Mutex and Semaphore
*/


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_NUM 25

pthread_mutex_t cond_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t thread_cond_var = PTHREAD_COND_INITIALIZER;

int counter = 1;

void wait_on_cond_var (void)
{
	pthread_mutex_lock (&cond_mutex);
	pthread_cond_wait(&thread_cond_var, &cond_mutex);
	pthread_mutex_unlock (&cond_mutex);
}

void signal_on_cond_var (void)
{
	pthread_mutex_lock (&cond_mutex);
	pthread_cond_signal(&thread_cond_var);
	pthread_mutex_unlock (&cond_mutex);
}		

void *print_odd (void *data)
{
	int i = 1;
	while (i <= MAX_NUM) {
		while (counter != i) {
			wait_on_cond_var ();
		}
		printf ("odd   %d\n", i);
		i += 2;
		++counter;
		signal_on_cond_var ();
	}
	pthread_exit (NULL);
}

void *print_even (void *data)
{
	int i = 2;
	while (i <= MAX_NUM) 
	{
		while (counter != i) 
		{
			wait_on_cond_var ();
		}
		printf ("even  %d\n", i);
		i += 2;
		++counter;
		signal_on_cond_var ();
	}
	pthread_exit (NULL);
}


int main (int argc, char *argv[])
{
	pthread_t odd_thread, even_thread;
	printf ("Printing Numbers\n");

	if (pthread_create (&even_thread, NULL, print_even, NULL) != 0) {
		printf ("Can't print numbers. Sorry ;-)\n");
		exit (-1);
	}

	if (pthread_create (&odd_thread, NULL, print_odd, NULL) != 0) {
		printf ("Can't print numbers. Sorry ;-)\n");
		exit (-1);
	}

	pthread_join (odd_thread, NULL);
	pthread_join (even_thread, NULL);
	
	printf ("We are done! bye.\n");
	return 0;
}
