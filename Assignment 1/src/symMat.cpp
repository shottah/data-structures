/** === [symMat.cpp]=======================/
* author:Matthew Abraham
* id: 815009613
* email: m.abrahamtt@gmail.com
* course: COMP 2000
* date:Feb 20, 2017
* details: Convert a Symmetrical Matrix (2D Array) to 1D form.
* comments: Does not store the 1D array back into the
			original 2D array (arr), but a new array (c).
* ==============================================*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// Global Variables
#define sz 3
int arr[sz][sz];

// Function Prototypes
void print (int a[], int n);
void print2D (int a[][sz], int n);
void t_1D_to_2D_SM (int a[][sz], int m, int n, int b[]);
void t_2D_SM_to_1D (int a[][sz], int m, int n, int b[]);

int main() {
	srand(time(NULL));

	int i, j = 0;			// Initialize 2D array with arbitrary values
	for ( i = 0; i < sz; i++) {			// Set ROW values
		for ( j = 0; j < sz; j++) {		// Set COL values
			arr[i][j] = rand() % 10+1;	// SM Form		
			arr[j][i] = arr[i][j];		//{{1 1 1 1},
										// {1 2 2 2},
										// {1 2 3 3},
										// {1 2 3 4}}
		}
	}
	
	print2D (arr, sz);				// Print 2D Array
	
	int size = sz*(sz+1)/2;			// Prepare 1D Array
	int b [size];			// Formula: m = n * (n + 1) /2;
							// n --> a[n][n];
	t_2D_SM_to_1D (arr, sz, sz, b);	// Store 2D in 1D
	
	print (b, size);
	
	int c [sz][sz];					// New 2D to Store 1D
	
	t_1D_to_2D_SM (c, sz, sz, b); 	// Store 1D in new 2D (SM)
	
	print2D (c, sz);				// Print New 2D (SM)
	
	return 0;
}

void print (int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%d]", a[i]);
	}
	printf("\n\n");
}

void print2D (int a[][sz], int n) {
	int i, j = 0;
	for ( i = 0; i < sz; i++) {
		for ( j = 0; j < sz; j++) {
			printf("[%d]",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void t_2D_SM_to_1D (int a[][sz], int m, int n, int b[]) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i*(i+1)/2+j] = a[i][j];
        }
    }
}

void t_1D_to_2D_SM (int a[][sz], int m, int n, int b[]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				a[i][j] = b[j*(j+1)/2+i];
			} else {
				a[i][j] = b[i*(i+1)/2+j];
			}
		}
	}
}
