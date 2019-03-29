#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[8];

int a[8] = {1,2,3,4,5,6,7,8};

int b[8] = {1,2,3,4,5,6,7,8};
int c[8] = {0,0,0,0,0,0,0,0};


typedef struct {
	int a, b;
	int index; 
} thread_arg, *ptr_thread_arg;

void *process_sum(void* args){
	ptr_thread_arg targ = (ptr_thread_arg)args;

	c[targ->index] = targ->a + targ->b;	
	printf("\n result %d + %d =  %d", targ->a, targ->b, c[targ->index]);
}


int main(){

	thread_arg args[8];

	int i = 0;
	for(i; i < 8; i++){
		args[i].a = a[i];
		args[i].b = b[i];
		args[i].index = i;
		pthread_create(&(threads[i]), NULL, process_sum, &(args[i]));
	}

	for(i = 0; i < 8; i++){
		pthread_join(threads[i], NULL);
	}

	
	for(i = 0; i < 8; i++){
		printf("\n c => %d", c[i]);
	}

}




