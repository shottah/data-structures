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
#define N 7

int sv = 0;

int cost [][N] = {
	{0,6,5,5,'I','I','I'},
	{'I',0,'I','I',-1,'I','I'},
	{'I',-2,0,'I',1,'I','I'},
	{'I','I',-2,0,'I',-1,'I'},
	{'I','I','I','I',0,'I',3},
	{'I','I','I','I','I',0,3},
	{'I','I','I','I','I','I',0}
};
int L[N] = {0};
int p[N-1];
// Function Prototypes

void findPath (int p[], int x);
void printArray (int a[], int size);
void printMatrix (int a[][N], int size);
void bellmanford (int a[][N], int L[], int sv, int n);

int main () {
	
	bellmanford (cost, L, sv, N);
	
	printf("\nThe distance array is \n");
	printArray(L, N);
	
	printf("\nThe parent array is \n");
	printArray (p, N);
	
	printf("\n");
	for (int i = 1; i < N; i++) {
		printf("\nNode %d -> %d \tL[] %d \tPath:%d", sv, i, L[i], sv);
		findPath(p, i);
	}
	
	return 0;
}

void printArray (int a[], int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] != 'I' && a[i] != INT_MAX) {
			printf("[%d]\t", a[i]);
		} else {
			printf("[I]\t");
		}
	}
}

void printMatrix (int a[][N], int size) {
	for(int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i][j] != 'I') {
				printf("[%d]\t", a[i]);
			} else {
				printf("[I]\t");
			}
		}
	}
}

void findPath (int p[], int x) {
	if (p[x] == -1)
		return;
	
	findPath(p, p[x]);
	printf(" --> %d", x);
}

void bellmanford (int c[][N], int L[], int sv, int n) {
	
	for (int i = 0; i < n; i++) {
		L[i] = INT_MAX;
		p[i] = -1;
	}
	
	L[sv] = 0;
	
	int u;
	int v;
	
	for (int z = 1; z < N; z++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (c[i][j] != 'I' && j!=i) {
					u = i;
					v = j;
					if (L[u] + c[u][v] < L[v]) {
						L[v] = L[u] + c[u][v];
						p[v] = u;
					} else {}
				}
			}
		}
		printf("\n%d.\t dist[] is\n", z);		
		printArray(L, n);
	}
	
}

