/** === [mergeSort.cpp]=======================/
* author:Matthew Abraham
* id: 815009613
* email: m.abrahamtt@gmail.com
* course: COMP 2000
* date:Feb 20, 2017
* details: Merge sort algorithm on an array
* ==============================================*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// Global Variables
#define sz 20
int arr [sz];

// Function Declarations
void print(int arr[], int l, int r);
void merge(int arr[], int lp, int rp, int re);
void mergeSort(int arr[], int l, int r);

int main () {
	
	srand(time(NULL));
	
	for (int i = 0; i < sz; i++) {
		arr [i] = rand() % 21;
	}
	
	printf("UNSORTED:\t");
	print (arr, 0, sz);
	mergeSort(arr, 0, sz-1);
	printf("SORTED:\t\t");
	print (arr, 0, sz);

	return 0;
}

void print (int arr[], int l, int r) {
	for (int i = l; i < r; i++) {
		printf("[%d]", arr[i]);
	}
	printf("\n");
}

void mergeSort(int arr[], int l, int r) {
	if (l<r) {
		int m = (l+r)/2;
		mergeSort(arr,l,m); 	// Recursively split left sides
		mergeSort(arr,m+1,r);	// Recursively split right side
		merge(arr,l,m+1,r);		// Merge after split
	}
}

void merge (int arr[], int lp, int rp, int re) {
	// Create temporary array to store sorted values
	int t [sz];
	
	int le = rp-1; 	// End of Left side
	int i = lp;		// Counter for temp indices
	int n = re - lp + 1;	// Number of elements
	while (lp <= le && rp <= re) {	// Scan left pos to left end
									// Scan right pos to right end
		if (arr[lp] < arr[rp])	// If left pos # < right pos #	
			t[i++] = arr[lp++];	// Store the left number in t[i]
		else
			t[i++] = arr[rp++];	// Store the right number in t[i]
	}
	while (lp<=le)				// Scan remainder of left side
		t[i++] = arr[lp++];		// Add remainder
	while (rp<=re)				// Scan remainder of right side
		t[i++] = arr[rp++];		// Add remainder
		
	for (int j = 0; j < n; j++, re--)	// Copy temp into original
		arr[re] = t[re];
}
