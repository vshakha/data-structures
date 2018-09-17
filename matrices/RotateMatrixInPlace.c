/*
    Problem Name : Rotate Matrix by 90 degrees in-place
    Description  : Given an square matrix, rotate it 90 degrees without using any extra space.
    Complexity	 : O(n2)
    Source		 : https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
*/

#include "stdio.h"

#define ROWS 4
#define COLUMNS 4

void printMatrix(int matrix[][COLUMNS]) {
	printf("\n\n Rotated matrix is : ");
	for(int i = 0; i < ROWS; i++) {
		printf("\n");
		for(int j = 0; j < COLUMNS; j++)
			printf("\t %d", matrix[i][j]);
	} 

}

/* Rotates matrix Anti-Clockwise */
void rotateMatrixAntiClockwise(int matrix[][COLUMNS]) {
	for(int i = 0; i < COLUMNS/2; i++) {
		for(int j = i; j < COLUMNS-i-1; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][COLUMNS-i-1];
			matrix[j][COLUMNS-i-1] = matrix[COLUMNS-i-1][COLUMNS-j-1];
			matrix[COLUMNS-i-1][COLUMNS-j-1] = matrix[COLUMNS-j-1][i];
			matrix[COLUMNS-j-1][i] = temp;
		}
	}
}

/* Rotates matrix Clockwise */
void rotateMatrixClockwise(int matrix[][COLUMNS]) {
	for(int i = 0; i < ROWS/2; i++) {
		for(int j = i; j < ROWS-i-1; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[ROWS-j-1][i];
			matrix[ROWS-j-1][i] = matrix[ROWS-i-1][ROWS-j-1];
			matrix[ROWS-i-1][ROWS-j-1] = matrix[j][ROWS-i-1];
			matrix[j][ROWS-i-1] = temp;
		}
	}
}

int main (void) {
	int matrix[ROWS][COLUMNS] = 
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	
	//rotateMatrixAntiClockwise(matrix);
	rotateMatrixClockwise(matrix);
	printMatrix(matrix);

	printf("\n\n");
	return 0;
}
