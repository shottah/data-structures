/** === DH.cpp === */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Global Variables
#define M 11
#define C 5

typedef struct {
	int data;
} Node;

// Function Prototypes
void printMenu();
int hash (int k);
void init (Node a[], int size);
void insert (Node a[], int k);
int search (Node a[], int k);
bool deleted (Node a[], int k);

int main () {
	
	int o = 0;
	int count = 0;
	int input;
	Node table[M];
	init (table, M);
	
	while (o!=5) {
		printMenu();
		printf("Option: ");
		scanf("%d", &o);
		switch (o) {
			case 1: {
				if (count >= M-1) {
					printf("Hash table is full! You must delete an entry.\n");
					break;
				}
				printf("Enter a number to input into hash table: ");
				scanf("%d", &input);
				insert (table, input);
				count++;
				break;
			}
			case 2:{
				printf("Enter a number to search for: ");
				scanf("%d", &input);
				int position = search (table, input);
				if (position >= 0 && position < M) {
					printf("%d has been found in table[%d]", input, position);
				}
				break;
			}
			case 3: {
				printf("Enter a number to delete from the hash table: ");
				scanf("%d", &input);
				if (deleted(table, input)) {
					printf("%d has been successfully deleted.\n", input);
				} else {
					printf("%d does not exist to be deleted.\n", input);
				}
				break;
			}
			case 4: {
				for (int i = 0; i < M; i++) {
					printf("table[%d] = %d\n", i, table[i]);
				}
				break;
			}
			default:
				break;
		}
	}
	
	return 0;
}

void init (Node a[], int size) {
	for (int i = 0; i < size; i++) {
		a[i].data = -1;
	}
}

void printMenu () {
	printf("//*=====[M=%d]=====*//\n", M);
	printf("1. Insert a new key.\n");
	printf("2. Search for a given key.\n");
	printf("3. Delete a given key.\n");
	printf("4. Display hash table.\n");
	printf("5. Quit.\n");
	printf("//*===================*//\n");
}

int hash (int k) {
	return k%M;
}

int hash2 (int k) {
	return C-(k%C);
}

void insert (Node a[], int k) {
	int i = hash(k);
	int j = 0;
	printf("%d mod %d is %d\t", k, M, i);
	if (a[i].data == -1 || a[i].data == -999) {
		printf("%d placed in table[%d]\n", k, i);
		a[i].data = k;
		return;
	} else {
		while (a[i].data != -1) {
			j = hash2(k);
			i = (i+j)%M;
		}
	}
	printf("%d placed in table[%d]\n", k, i);
	a[i].data = k;
}

int search (Node a[], int k) {
	int i = hash(k);
	int j;
	
	while (i != -1) {
		if (a[i].data == -1) {
			return -1;
		} else if (a[i].data == k) {
			return i;
		} else {
			if (i > M-1) {
				i = M%i;
			} else {
				j = hash2(k);
				i = (i+j)%M;
			}
		}
	}
	return -1;
}

bool deleted (Node a[], int k) {
	
	int position = search (a, k);
	if (position >= 0 && position < M) {
		a[position].data = -999;
		return true;
	} else {
		return false;
	}
}
