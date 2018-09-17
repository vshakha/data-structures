/*
    Problem Name : Leaders in an array
    Description  : An element is leader if it is greater than all the elements to its right side. 
    			   The rightmost element is always a leader. 
    Complexity	 : O(n)
    Source		 : https://www.geeksforgeeks.org/leaders-in-an-array/
*/

#include "stdio.h"

void leadersInArray(int arr[], int arrSize) {
	int maxSoFar = arr[arrSize-1];
	
	printf("\n The leaders in the array are : \n");
	printf("\t %d \n", maxSoFar);
	
	for(int i = arrSize-1; i >= 0; --i) {
		if(maxSoFar < arr[i]) {
			maxSoFar = arr[i];
			printf("\t %d \n", maxSoFar);
		}
	}
}

int main (void) {
	int arr[] = {56, 3, 39, 4, 28, 9, 3, 2, 6, 1, -1, -3 };
	int arrSize = sizeof(arr)/sizeof(int);
	
	leadersInArray(arr, arrSize);

	printf("\n");
	return 0;
}
