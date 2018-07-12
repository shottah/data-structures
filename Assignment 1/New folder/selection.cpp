/** === [qSortHoare.cpp]=======================/
* author:Matthew Abraham
* id: 815009613
* email: m.abrahamtt@gmail.com
* course: COMP 2000
* date:Feb 20, 2017
* details: Quicksort Algorithm using Hoare's Partition scheme
* comments: Utilizes Hoare's partition scheme to find the k-th 
			smallest 'pivot' element.
* ==============================================*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// Global Variables
#define sz 7
int arr[sz];

// Function Prototypes
void print (int a[], int n);
int partition (int a[], int l, int r);
int selection (int a[], int l, int r, int k);

int main () {
	
	srand(time(NULL));
	
	for (int i = 0; i < sz; i++) {	// Initialize the given array with
		arr[i] = rand() % 10+1;		// arbitrary values
	}
	
	printf("UNSORTED:\t");
	print(arr,sz);
	
	printf("Enter a value 'k' to find (i.e. 3rd smallest value)");
	int k = -1;
	while (!(k > 0 && k < sz)){
		printf("\nEnter a valid integer between [%d] and [%d] (index + 1)",1,sz-1);
		scanf("%d",&k);
	}
	
	int ans = selection (arr, 0, sz-1, k);
	printf("\n%d-th Smallest Number: %d", k, ans);
	return 0;
}

void print (int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%d]", a[i]);
	}
	printf("\n");
}

int partition (int a[], int l, int r) {
	int p, i, j, t;
	p = a[l];
	i = l-1;
	j = r+1;
	while (true) {
		do {
			j--;
		} while (a[j] > p);
		do {
			i++;
		} while (a[i] < p);
		if (i<j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		else {
			return j;
		}
	}
	return j;
}

int  selection (int a[], int l, int r, int k) {
	/*	if (k > 0 && k <= r-l+1) -- Redundant due to user input validation */
	int p = partition (a, l, r);	// Position of pivot eleent in sorted array
	if (p-l == k-1) {			// If position = k
		return a[p];
	}
	else if (p-l > k-1) {		// If pos > k; check left subarray
		return selection(arr,l,p-1,k);
	}							// If pos < k; check right subarray
	return selection(arr, p+1, r, k-p+l-1);
	
	
	return arr[sz]; // This will return if k > sz; -- Redundant
}
