/** === [hbCurve.cpp]=======================/
* author:Matthew Abraham
* id: 815009613
* date:Feb 20, 2017
* details:
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

int main() {
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
