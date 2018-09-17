/*
    Problem Name : Spiral Printing of a Matrix
    Description  : Given a 2D array, print it in spiral form.
    Complexity	 : O(mn)
    Source		 : https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
*/

#include "stdio.h"

#define SIZE 4

void printMatrixSpirally(int matrix[][SIZE]) {
	int rowStart, rowEnd, colStart, colEnd;
	int i, count = 0;
	int total = SIZE * SIZE;
	
	rowStart = colStart = 0;
	rowEnd = colEnd = SIZE;
	
	printf("\n\n Spirally printed matrix looks like : \n\t");
	while((rowStart < rowEnd) && (colStart < colEnd)) {
		
		for(i = colStart; i < colEnd; ++i)
			printf(" %d ", matrix[rowStart][i]);	
		rowStart++;
		
		for(i = rowStart; i < rowEnd; ++i)
			printf(" %d ", matrix[i][colEnd-1]);
		colEnd--;
		
		if(rowStart < rowEnd) {
			for(i = colEnd-1; i >= colStart; --i)
				printf(" %d ", matrix[rowEnd-1][i]);
			rowEnd--;
		}
		
		if(colStart < colEnd) {
			for(i = rowEnd-1; i >= rowStart; --i)
				printf(" %d ", matrix[i][colStart]);
			colStart++;
		}
	}
}

int main (void) {
	int matrix[SIZE][SIZE] = 
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	
	printMatrixSpirally(matrix);

	printf("\n\n");
	return 0;
}
