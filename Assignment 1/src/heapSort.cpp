/** === [heapSort.cpp]=======================/
* author:Matthew Abraham
* id: 815009613
* email: m.abrahamtt@gmail.com
* course: COMP 2000
* date:Feb 20, 2017
* details: Heapsort algorithm on an array.
* comments: Uses max heapify on 1D array and stores 
			values in ascending order.
* ==============================================*/

#include <cstdlib>
#include <stdio.h>
#include <time.h>

using namespace std;

// Global Variables
#define sz 20
int arr[sz];

// Function Declarations
void print (int arr[], int n);
void heapSort (int arr[], int n);
void createHeap (int arr[], int n);
void shiftDown (int arr[], int i, int n);

int main () {
	
	srand(time(NULL));
	
	for (int i = 0; i < sz; i++) {
		arr [i] = rand() % 10+1;
	}
	
	printf("UNSORTED:\t");
	print (arr, sz);
	heapSort (arr, sz);
	printf("SORTED:\t\t");
	print (arr, sz);
	
	return 0;
}

void print (int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%d] ",arr[i]);
	}
	printf("\n");
}

void heapSort(int arr[], int n) {
	createHeap(arr, n);
	int temp;
	for (int j = n-1; j >= 0; j--) { // (n-1) Iterations
		temp = arr[0];				// Interchange first and last
		arr[0] = arr[j];			// elements in the heap array
		arr[j] = temp;
		shiftDown(arr, 0, j-1);
	}
}

void createHeap (int arr[], int n) {
	int r = n - 1;
	for (int i = (n/2)-1; i >= 0; i--) {
		shiftDown(arr,i,r);
	}
}

void shiftDown (int arr[], int i, int r) {
	bool done = false;
	int j = 2*i + 1;	// Left child arr[j] of parent arr[i]
	int temp;
	while (!done && j<=r) {
		if (j < r && arr[j] < arr[j+1]) { // Find index of max
			j++;					// Between arr[j] and arr[j+1]
		}
		if (arr[i] < arr[j]) {		// If current parent arr[i] <
			temp = arr[i];			// left child arr[j] and arr[j+1]
			arr[i] = arr[j];		// Swap arr[i] and arr[j]
			arr[j] = temp;
			i = j;					// Update current parent node
			j = 2*j + 1;			// Update left child arr[j]
									// of current parent arr[i]
		}
		else
			done = true;
	}
}
