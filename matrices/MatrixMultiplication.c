/*
    Problem Name : Matrix Multiplication
    Description  : Given two matrices, the task is to multiply them. 
    			   Matrices can either be square or rectangular.
    Complexity	 : O(n3)
    Source		 : https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
*/

#include "stdio.h"

#define SIZE 4

void printMatrix(int result[][SIZE]) {
	printf("\n\n Resultant matrix is : ");
	for(int i = 0; i < SIZE; i++) {
		printf("\n");
		for(int j = 0; j < SIZE; j++)
			printf("\t %d", result[i][j]);
	} 
}

void matrixMultiplication(int mat1[][SIZE], int mat2[][SIZE], int result[][SIZE]) {
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			result[i][j] = 0;
		
			for(int k = 0; k < SIZE; k++)
				result[i][j] += mat1[i][k] * mat2[k][j];
		}
	}
}

int main (void) {
	int mat1[SIZE][SIZE] = 
	{
		{1, 1, 1, 1},
		{2, 2, 2, 2},
		{3, 3, 3, 3},
		{4, 4, 4, 4}
	};

	int mat2[SIZE][SIZE] = 
	{
		{1, 1, 1, 1},
		{2, 2, 2, 2},
		{3, 3, 3, 3},
		{4, 4, 4, 4}
	};
	
	int result[SIZE][SIZE];
	
	matrixMultiplication(mat1, mat2, result);
	printMatrix(result);

	printf("\n\n");
	return 0;
}
