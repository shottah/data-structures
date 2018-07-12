/** === [zigZag.cpp]=======================/
* author:Matthew Abraham
* id: 815009613
* email: m.abrahamtt@gmail.com
* course: COMP 2000
* date:Feb 20, 2017
* details: 	Traverse the 2D array in a Zig Zag fashion
			and store the concurrent values into a 2D 
			array following the Zig Zag fashion.
* comments: There must be a simpler algorithm.
* ==============================================*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// Global Variables
#define H 4
#define W 5
int arr[H][W];

// Function Prototypes
void print (int a[], int n);
void print2D (int a[][W], int m, int n);
void zigzag_2D_to_1D (int a[][W], int m, int n, int b[]);

int main() {
	srand(time(NULL));
						// Initialize 2D array with arbitrary values
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			arr[i][j] = rand() % 10+1;
		}
	}
	
	int b [H*W];		// 1D array to store 2D ZigZag Traversal
	
	print2D (arr,H,W);				// Print 2D Array
	
	zigzag_2D_to_1D(arr, H, W, b);	// Store 2D Array in 1D Array
	
	print (b, H*W);		// Print 1D ZigZag Array
	
	return 0;
}

void print (int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%d]", a[i]);
	}
	printf("\n\n");
}

void print2D (int a[][W], int m, int n) {
	int i, j = 0;
	for ( i = 0; i < m; i++) {
		for ( j = 0; j < n; j++) {
			printf("[%d]",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void zigzag_2D_to_1D (int a[][W], int m, int n, int b[]) {
	int x = 0, y = 0, i, j;
	int k = 0;
	while (x < H && y < W) {
		for (i = x, j = y; i >= 0 && j < W; --i, ++j) {
			b[k++] = a[i][j];
		}
		if (j >= W) {
			x = i+2;
			y = j-1;
		}
		else {
			x = i+1;
			y = j;
		}
		for (i = x, j = y; i < H && j >= 0; ++i, --j) {
			b[k++] = a[i][j];
		}
		if (i >= H) {
			x = i-1;
			y = j+2;
		}
		else {
			x = i;
			y = j+1;
		}
	}
}
