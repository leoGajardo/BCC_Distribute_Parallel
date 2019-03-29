#include <stdio.h>
#include <stdlib.h>

int a[3][3] = {{1,2,3},{4,5,6},{5,4,3}};
int b[3][3] = {{1,2,3},{4,5,6},{5,4,3}};
int c[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

#define MATRIX_A_ROW_SIZE 3
#define MATRIX_LENGTH 3
#define MATRIX_B_COL_SIZE 3

int main(){

	#pragma omp prallel for
	for(int line = 0; line < MATRIX_A_ROW_SIZE; line++){
		for(int col = 0; col < MATRIX_B_COL_SIZE; col++){
			int sum = 0;
			for(int index = 0; index < MATRIX_LENGTH; index++){
				sum += a[line][index] * b[index][col];
			}	
			c[line][col] = sum;
		}
	}



	for(int line = 0; line < MATRIX_A_ROW_SIZE; line++){
	
		for(int col = 0; col < MATRIX_B_COL_SIZE; col++){
			printf ("%d \t", c[line][col]);
		}
		printf("\n");
	}
}
