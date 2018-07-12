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
#define M 10	// Edges
#define N 6		// Vertexes

int sv = 0;
int cost [N][N] = {
	/*v0*/	{0,1,6,'I','I','I'},
	/*v1*/	{'I',0,3,4,6,'I'},
	/*v2*/	{'I','I',0,2,2,'I'},
	/*v3*/	{'I','I','I',0,2,3},
	/*v4*/	{'I','I','I','I',0,4},
	/*v5*/	{'I','I','I','I','I',0}
};

int L[N];
int p[N-1];
bool s[N-1];

// Function Prototypes

void printArray (int a[]);
void printMatrix (int a[][N]);
void printDistance ();

void dijkstra (int a[][N], int sv);
void findPath (int p[], int x);

int main () {
	
	printf("The Adjacency Matrix: am[][%d]\n", N);
	printMatrix(cost);
	
	// init ()
	for (int i = 0; i < N; i++) {
		L[i] = cost[sv][i];
		p[i] = sv;
		s[i] = false;
	}
	
	printf("\n");
	printArray(L);
	
	dijkstra (cost, sv);
	
	printf("\nThe distance array dist[] is\n");
	printArray(L);
	
	printf("\nThe parent array p[] is\n");
	printArray(p);
	
	printf("\n")
	for (int i = 1; i < N; i++) {
		printf("\nNode %d -> %d \tL[] %d \tPath:%d", sv, i, L[i], sv);
		findPath(p, i);
	}
	
	printf("\n\n");
	printMatrix(cost);
	
	return 0;
}

void printArray (int a[]) {
	for (int i = 0; i < N; i++) {
		if (a[i] != 'I'){
			printf("[%d]\t", a[i]);
		} else {
			printf("[I]\t");
		}
	}
}

void printMatrix (int a[][N]) {
	for (int i = 0; i < N; i++) {
		printf("%d:", i);
		for (int j = 0; j < N; j++) {
			if (a[i][j] != 'I') {
				printf("[%d]\t", a[i][j]);
			} else {
				printf("[I]\t");
			}
		}
		printf("\n");
	}
}

void findPath (int p[], int x) {
	if (p[x] == -1)
	return;
	
	findPath(p, p[x]);
	printf(" --> %d", x);
}

void dijkstra (int a[][N],int sv) {
	int min, u;
	
	s[sv] = true;
	L[sv] = 0;
	p[sv] = -1;
	
	for (int i = 1; i < N; i++) {
		min = L[i];
		u = i;
		
		for (int w = i + 1; w < N; w++) {
			if (min > L[w]) {
				min = L[w];
				u = w;
			}
		}
		
		s[u] = true;
		
		for (int j = 1; j < N; j++) {
			if (cost[u][j] != 'I' && !s[j]) {
				if (L[u] + a[u][j] < L[j]) {
					L[j] = L[u] + a[u][j];
					p[j] = u;
				}
			}
		}
		
		printf("\n%d.\tdist[] is\n", i);
		printArray(L);
	}
}
