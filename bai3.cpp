#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

int X = 0;

void* ProcessA(void* mess) {
	while (1){
		X = X + 1;
		if (X==20)
		X = 0;
		printf ("x(pA) = %d\n", X) ;
	}
}

void* ProcessB(void* mess) {
	while (1){
		X = X + 1;
		if (X==20){
			X = 0;
		}
		printf("x(pB) = %d\n", X);
	}
}

int main (){
	pthread_t pA, pB;
	pthread_create(&pA, NULL, &ProcessA, NULL); 
	pthread_create(&pB, NULL, &ProcessB, NULL);
	while (1){}
	return 0;
}
