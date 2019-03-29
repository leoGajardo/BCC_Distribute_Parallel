#include <stdio.h>
#include <stdlib.h>

int a[8] = {1,2,3,4,5,6,7,8};
int b[8] = {6,3,8,3,6,7,7,2};
int c[8] = {0,0,0,0,0,0,0,0};

int main(){
	#pragma omp parallel for
	for(int i = 0; i< 8; i++){
		c[i] = a[i] + b[i];
	}



	for(int z = 0; z < 8; z++){
		printf("%d + %d = %d\n", a[z], b[z], c[z]);
	}
}
