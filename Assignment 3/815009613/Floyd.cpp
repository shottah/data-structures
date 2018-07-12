/** === Dstra.cpp === */

/**
	Student Full Name: Matthew Abraham
	Student ID: 815009613
	E-mail: m.abrahamtt@gmail.com
	Course Code: COMP 2000
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

// Global Variables
#define N 3

int sv = 0;

int cost [N][N] = {{
		0,2,9
	},{
		8,0,6
	},{
		1,'I',0
	}
};

int L[N][N] = {INT_MAX};
int p[N][N];

// Function Prototypes

void floyd (int a[][N]);
void findPath (int a[][N]);
void printMatrix (int a[][N], int size);

int main () {
	
	printf("The adjacency matrix cost[] is\n");
	printMatrix (cost, N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			L[i][j] = cost[i][j];
			if (i==j || cost[i][j]=='I' || cost[i][j]==INT_MAX) {
				p[i][j] = -1;
			} else {
				p[i][j] = i;
			}
		}
	}
	
	printf("\n\nExecuting Floyd Algorithm...\n");
	floyd (L);
	
	printf("\nThe distance matrix dist is\n");
	printMatrix (L, N);
	
	printf("\nThe path matrix path is\n");
	printMatrix (p, N);
	
	for (int i = 0; i < N; i++) {
		printf("\nThe path from %d -> %d: %d", sv, i, sv);
		findPath (p);
	}
	
	return 0;
}

void printMatrix (int a[][N], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d:", i);
		for (int j = 0; j < size; j++) {
			if (a[i][j] != 'I' && a[i][j] != INT_MAX) {
				printf("[%d]\t", a[i][j]);
			} else {
				printf("[I]\t");
			}
		}
		printf("\n");
	}
}

void findPath (int a[][N]) {
	
}

void floyd (int a[][N]) {
	
	for (int pivot = 0; pivot < N; pivot++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((a[i][pivot] * a[pivot][j] != 0) && (i != j))
                {
                    if ((a[i][pivot] + a[pivot][j] < a[i][j]) || (a[i][j] == 0))
                    {
                        a[i][j] = a[i][pivot] + a[pivot][j];
                        p[i][j] = p[pivot][j];
                    }
                }
			}
		}
		printf("%d.\tdist[] is\n", pivot);
		printMatrix (a, N);
		printf("\n");
	}	
}
