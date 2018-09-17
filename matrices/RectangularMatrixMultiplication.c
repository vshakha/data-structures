/*
    Problem Name : Rectangular Matrix Multiplication
    Description  : Given two matrices, the task is to multiply them. 
    			   Matrices can either be square or rectangular.
    Complexity	 : O(n3)
    Source		 : https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
*/

#include "stdio.h"

#define SIZE 2

void printMatrix(int result[][SIZE]) {
	printf("\n\n Resultant matrix is : ");
	for(int i = 0; i < SIZE; i++) {
		printf("\n");
		for(int j = 0; j < SIZE; j++)
			printf("\t %d", result[i][j]);
	} 
}

void matrixMultiplication(int m1, int m2, int mat1[][m2], int n1, int n2, int mat2[][n2]) {
	int result[m1][n2];
	
	if(m2 != n1) {
		printf("\n\n Matrices are compatible for multiplication.");
		return;
	}
	
	for(int i = 0; i < m1; i++) {
		for(int j = 0; j < n2; j++) {
		
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
