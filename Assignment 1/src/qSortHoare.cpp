/** === [qSortHoare.cpp]=======================/
* author:Matthew Abraham
* id: 815009613
* email: m.abrahamtt@gmail.com
* course: COMP 2000
* date:Feb 20, 2017
* details: Quicksort Algorithm using Hoare's Partition scheme
* comments: Pivot was chosen as the first element in the array,
			not the last one.
* ==============================================*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// Global Variables
#define sz 20
int arr[sz];

// Function Declarations
void swap (int a[], int x, int y);
void print (int a[], int n);
void quickSort (int a[], int l, int r);
int partition (int a[], int l, int r);

int main () {
	
	srand(time(NULL));
	
	for (int i = 0; i < sz; i++) {		// Initialize the array with
		arr [i] = rand() % 10+1;		// Arbitrary values
	}
	printf("UNSORTED:\t");
	print(arr, sz);
	quickSort(arr, 0, sz-1);
	printf("SORTED:\t\t");
	print(arr, sz);
	
	return 0;
}

void print (int a[], int n) {
	for (int i = 0; i < n; i ++) {
		printf("[%d]", arr[i]);
	}
	printf("\n");
}

void quickSort (int a[], int l, int r) {
	if (l < r) {
		int p = partition(a,l,r);
		quickSort(a,l,p);
		quickSort(a,p+1,r);
	}
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
