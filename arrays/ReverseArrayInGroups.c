/*
    Problem Name : Reverse an array in groups of given size
    Description  : Given an array, reverse every sub-array formed by consecutive k elements.
    Complexity	 : O(n)
    Source		 : https://www.geeksforgeeks.org/reverse-an-array-in-groups-of-given-size/
*/

#include "stdio.h"

void printArray(int arr[], int arrSize) {
	printf("\n\n Sorted array is : \n");
	for(int i = 0; i < arrSize; i++) 
		printf("\t %d \n", arr[i]);

}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int minimum (int a, int b) {
	return (a < b ? a : b);
}

void reverseArrayInGroups(int arr[], int arrSize, int groupSize) {
	for(int i = 0; i < arrSize; i += groupSize) {
		int low = i;
		int high = minimum(low+groupSize-1, arrSize-1);
		
		while(low < high) 
			swap(&arr[low++], &arr[high--]);
	}

	printArray(arr, arrSize);
}

int main (void) {
	int arr[] = {1 , 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int arrSize = sizeof(arr)/sizeof(int);

	reverseArrayInGroups(arr, arrSize, 3);
	
	printf("\n");
	return 0;
}
