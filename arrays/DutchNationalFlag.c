/*
    Problem Name : Dutch National Flag Problem or 3-Way Partitioning Problem
    Description  : Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[]. 
    			   The functions should put all 0s first, then all 1s and all 2s in last.
    Complexity	 : O(n)
    Source		 : https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
*/

#include "stdio.h"

void printArray(int arr[], int arrSize) {
	printf("\n\n Sorted array is : \n");
	for(int i = 0; i < arrSize; i++) 
		printf("\t %d\n", arr[i]);

}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void dutchNationalFlag(int arr[], int arrSize) {
	int low, mid, high;
	
	low = mid = 0;
	high = arrSize - 1;
	
	while(mid < high) {
		switch(arr[mid]) {
			case 0 :
				swap(&arr[low], &arr[mid]);
				low++;
				mid++;
				break;
				
			case 1 :
				mid++;
				break;
				
			case 2 :
				swap(&arr[mid], &arr[high]);
				high--;
				break;
		}	
	}
}

int main (void) {
	int arr[] = {1, 0, 0, 2, 0, 2, 1, 1, 0, 2, 0};
	int arrSize = sizeof(arr)/sizeof(int);
	
	dutchNationalFlag(arr, arrSize);
	
	printArray(arr, arrSize);

	return 1;
}
