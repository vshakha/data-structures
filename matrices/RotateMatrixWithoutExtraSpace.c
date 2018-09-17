/*
    Problem Name : Rotate Matrix by 90 degrees without using extra space
    Description  : Given a square matrix, turn it by 90 degrees in anti-clockwise direction without using any extra space.
    			   TRANSPOSE - REVERSE COLUMNS/ROWS - Works with NxN matrix
    Complexity	 : O(n2)
    Source		 : https://www.geeksforgeeks.org/rotate-matrix-90-degree-without-using-extra-space-set-2/
*/

#include "stdio.h"

#define ROWS 4
#define COLUMNS 4

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printMatrix(int matrix[][COLUMNS]) {
	printf("\n\n Rotated matrix is : ");
	for(int i = 0; i < ROWS; i++) {
		printf("\n");
		for(int j = 0; j < COLUMNS; j++)
			printf("\t %d", matrix[i][j]);
	} 

}

/* Rotates matrix Anti-Clockwise */
void reverseColumns(int matrix[][COLUMNS]) {
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0, k = COLUMNS-1; j < k; j++, k--)
			swap(&matrix[j][i], &matrix[k][i]);
	}
}

/* Rotates matrix Clockwise */
void reverseRows(int matrix[][COLUMNS]) {
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0, k = COLUMNS-1; j < k; j++, k--)
			swap(&matrix[i][j], &matrix[i][k]);
	}
}

void transposeMatrix(int matrix[][COLUMNS]) {
	for(int i = 0; i < ROWS; i++) {
		for(int j = i; j < COLUMNS; j++)
			swap(&matrix[i][j], &matrix[j][i]);
	}
}

void rotateMatrixBy90Degrees(int matrix[][COLUMNS]) {
	transposeMatrix(matrix);
	//reverseColumns(matrix);
	reverseRows(matrix);
	printMatrix(matrix);
}

void rotateMatrixBy180Degrees(int matrix[][COLUMNS]) {
	transposeMatrix(matrix);
	reverseColumns(matrix);
	transposeMatrix(matrix);
	reverseColumns(matrix);
	printMatrix(matrix);
}

int main (void) {
	int matrix[ROWS][COLUMNS] = 
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	
	//rotateMatrixBy90Degrees(matrix);
	rotateMatrixBy180Degrees(matrix);

	printf("\n\n");
	return 0;
}
