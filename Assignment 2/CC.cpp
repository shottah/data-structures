/** === LP.cpp === */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Global Variables
#define M 10

typedef struct {
	int value;
	int next;
} node;

// Function Prototypes
void printMenu();
int hash (int k);
void init (node a[], int size);
void insert (node a[], int k);
int search (node a[], int k);
bool deleted (node a[], int k);

int main () {
	
	int o = 0;
	int input;
	node table[M];
	init(table, M);
	
	while (o != 5) {
		printMenu();
		printf("Option: ");
		scanf("%d", &o);
		if (o == 1) {
			printf("Enter a number to input into hash table: ");
			scanf("%d", &input);
			insert(table, input);
		}
		else if (o == 2) {
			printf("Enter a number to search for: ");
			scanf("%d", &input);
			int position = search (table, input);
			if (position>=0 && position < M)
				printf("Found %d at position table[%d].\n", input, position);			
		}
		else if (o == 3) {
			printf("Enter a number to delete from the hash table: ");
			scanf("%d", &input);
			if (!deleted(table, input)) {
				printf("%d doesn't exist to be deleted.\n", input);
			} else {
				printf("%d has been successfully deleted.\n", input);
			}
		}
		else if (o == 4) {
			for (int i = 0; i < M; i++)
				printf("table[%d] = [%d][%d]\n", i, table[i].value, table[i].next);
		}
	}
	
}

void init (node a[], int size) {
	for (int i = 0; i < size; i++) {
		a[i].value = -1;
		a[i].next = -1;
	}
}

int hash (int key) {
	return key%M;
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

void insert (node a[], int k) {
	int i = hash(k);
	if (a[i].value == -1) {
		a[i].value = k;
		return;
	} else {
		int j = M-1;
		while (j >= 0 && a[j].value != -1) {
			j--;
			if (a[i].next != -1) {
				i = a[i].next;
			}
		}
		if (j == -1) {
			return;
		}
		a[i].next = j;
		a[j].value = k;
	}
}

int search (node a[], int k) {
	int i = hash(k);
	if (a[i].value == k) {
		return i;
	} else {
		node t;
		t = a[i];
		while (t.value != -1) {
			i = t.next;
			t = a[t.next];
			if (t.value == k) {
				return i;
			}
		}
	}
	return -1;
}

bool deleted (node a[], int k) {
	
	return false;
}
