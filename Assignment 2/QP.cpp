/** === QP.cpp === */

/**
	Student Full Name: Matthew Abraham
	Student ID: 815009613
	E-mail: m.abrahamtt@gmail.com
	Course Code: COMP 2000
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Global Variables
#define M 10
typedef struct {
	int data;
}Node;

// Function Prototypes
void printMenu();
int hash (int k);
void init (Node a[], int size);
int insert (Node a[], int k);
int search (Node a[], int k);
bool deleted (Node a[], int k);

int main () {
	
	int o = 0;
	int input;
	Node table[M];
	init(table, M);
		
	while (o != 5) {
		printMenu();
		printf("Option: ");
		scanf("%d", &o);
		if (o == 1) {
			printf("Enter a number to input into hash table: ");
			scanf("%d", &input);
			table[insert(table, input)].data = input;
		}
		else if (o == 2) {
			// Search
			printf("Enter a number to search for (k): ");
			scanf("%d", &input);
			int position = search(table, input);
			if (position>=0 && position < M)
				printf("Found %d at position table[%d].\n", input, position);			
		}
		else if (o == 3) {
			// Delete
			printf("Enter a numberto delete from the hash table: ");
			scanf("%d", &input);
			if (!deleted(table, input)) {
				printf("%d does not exist to be deleted.\n", input);
			} else {
				printf("%d has been successfully deleted.\n", input);
			}
		}
		else if (o == 4) {
			for (int i = 0; i < M; i++)
				printf("table[%d] = %d\n", i, table[i]);
		}
	}	
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

int insert (Node a[], int k) {
	int index = hash(k);
	int i, e;
	if (a[index].data == -1 || a[index].data == -999) {
		return index;
	}
	else {
		e = 1;
		i = index;
		while (a[index].data != -1) {
			index += (e*e);
			e++;
			if (index == M) {
				index = M%index;
			}
		}
	}
	//printf("%d is placed in table[%d]\n", k, index);
	return index;
}

int search (Node a[], int k) {
	int probe;
	int index = hash(k);
	int e = 1;
	
	if (a[index].data == -1) {
		return -1;
	} else if (a[index].data == k) {
		return index;
	} else {
		if (index > M-1) {
			probe = M%index;
		} else {
			probe = index + e*e;
		}
	}
	
	while ((probe != -1) && (probe != index)) {
		if (a[probe].data == -1) {
			return -1;
		} else if (a[probe].data == k) {
			return probe;
		} else {
			if (probe > M-1) {
				probe = M%probe;
			} else {
				probe += e*e;
				e++;
			}
		}
	}
	return false;
}

bool deleted (Node a[], int k) {
	int probe;
	int index = hash(k);	// returns k%m w/out linear probe
	int e = 1;
	
	if (a[index].data == -1) {	// if base case is empty, fail
	  return false;
	}
	
	else if (a[index].data == k) {	// if found, delete
	  a[index].data = -999;
	  probe = -1;
	  return true;
	}
	else {							// not found
	  if (index > (M - 1) ) {
	  	probe = M%index;				// reset probe to front
	  }
	  else {
	  	probe = index + e*e;			// increment probe linear
	  }
	}
	
	while ((probe != -1) && (probe != index)) {
	  if (a[probe].data == -1) {
	  	//printf("not found");
	  	return false;
	  } else if (a[probe].data == k) {
	  	//printf("found\n");
	     a[probe].data = -999;
	     probe = -1;
	     return true;
	  } else {
	  		e++;			// formula: i+(t*t) quadratic
	     	probe += e*e;
	     if (probe > (M - 1) ) {	// Increment probe cyclically
	     	probe = M%probe;
	     }
	  }
	}
	//printf("terminate");	
	return false;
}
