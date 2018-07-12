/** === [merge.cpp]=======================/
* author:Matthew Abraham
* id: 815009613
* email: m.abrahamtt@gmail.com
* course: COMP 2000
* date:Feb 20, 2017
* details: Merge two sorted arrays into a single array
* comments: To return the array to a variable as instructed,
			c was made an int pointer instead of an int array,
			the function's return type was int pointer.
* ==============================================*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// Global Variables
#define sza 8
#define szb 11
int a[sza];
int b[szb];

// Function Declarations
void setArray (int arr[], int n);
void swap (int arr[], int a, int b);
void print (int arr[], int n);
int * merge (int a[], int sa, int b[], int sb);

int main () {
	srand(time(NULL));
	
	setArray(a, sza);
	setArray(b, szb);
	
	printf("A:");
	print(a, sza);
	
	printf("B:");
	print(b, szb);
	
	int * c, i; 	// Int pointer used to return array from merge
					// c = merge (int a[], int n, int b[], int m);
	
	c = merge (a, sza, b, szb);		// Call function that returns array to c
	
	int r[sza+szb];			// Optionally read data from new array instead of pointer
	
	for (i = 0; i < sza+szb; i++) {
		r[i] = * (c+i);		// *(c+i) <---> c[i];
		printf("[%d]", r[i]);	
	}
	
	return 0;
}

void setArray (int arr[], int n) {
	int k = rand() % 40;
	for (int i = 0; i < n; i++) {
		arr [i] = k++;
	}
}

void print (int arr[], int n) {
	for (int i = 0; i < n; i ++) {
		printf("[%d]", arr[i]);
	}
	printf("\n");
}

int * merge (int a[], int sa, int b[], int sb) {
	static int temp [sza+szb];
	
	int ia = 0, ib = 0, it = 0; // Indexes for A, B, TEMP
	
	while (ia < sa && ib < sb) {	// Traverse Array A & B
		if (a[ia] < b[ib]) {
			temp [it++] = a[ia++];	// Set the next smaller from A
		}
		else {					// Else
			temp [it++] = b[ib++];	// Set the next smaller from B
		}
	}
	
	while (ia < sa) {			// Empty Array A into TEMP
		temp [it++] = a[ia++];
	}
	while (ib < sb) {			// Empty Array B into TEMP
		temp [it++] = b[ib++];
	}
	
	return temp;				// Return TEMP to * c
}

