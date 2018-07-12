/** === LP.cpp === */

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
struct Node {
	int key;
	struct Node * next;
};

typedef Node * ptr;

// Function Prototypes
int hash (int k);
void printMenu();
void init (ptr a[]);
ptr createNode (int k);
void printList(ptr head);
int search (ptr a[], int k);
void insert (ptr a[], int k);
bool deleted (ptr a[], int k);
ptr deleteNode (ptr head, int k);
ptr searchList (ptr head, int k);
ptr insertInOrder (ptr head, int k);


int main () {
	
	ptr heads[M];
	init (heads);
	
	int o = 0;
	int input;
	
	while (o != 5) {
		printMenu();
		printf("Option: ");
		scanf("%d", &o);
		switch (o) {
			case 1: {
				printf("Enter a number to place into the table: ");
				scanf("%d", &input);
				insert(heads, input);
				break;
			}
			case 2: {
				printf("Enter a number to search for in the table: ");
				scanf("%d", &input);
				int pos  = search (heads, input);
				if (pos >= 0 && pos < M-1) {
					printf("%d has been found in list[%d].\n", input, pos);
				} else {
					printf("%d does not exist in the table.\n", input);
				}
				break;
			}
			case 3: {
				printf("Enter a number to delete from the table: ");
				scanf("%d", &input);
				if (deleted(heads, input)) {
					printf("%d has been successfully deleted from the table.\n", input);
				} else {
					printf("%d does not exist to be deleted.\n", input);
				}
				break;
			}
			case 4: {
				for (int i = 0; i < M; i++) {
					printf("list[%d]:\t", i);
					printList (heads[i]);
					printf("\n");
				}
				break;
			}
		}
	}
	
	return 0;
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

void printList (ptr head) {
	ptr curr;
	
	if (head == NULL) {
		printf("List empty!");
	} else {
		curr = head;
		while (curr != NULL) {
			printf("%d-->", curr->key);
			curr = curr->next;
		}
		printf("NULL");
	}
}

void init (ptr a[]) {
	for (int i = 0; i < M; i++) {
		a[i] = NULL;
	}
}

int hash (int k) {
	return k%M;
}

ptr createNode (int k) {
	ptr temp;
	temp = (ptr)malloc(sizeof(Node));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

ptr insertInOrder (ptr head, int k) {
	ptr temp, curr, pre;
	
	temp = createNode (k);
	if (head == NULL) {
		head = temp;
		return head;
	} else {
		bool found = false;
		curr = head;
		pre = NULL;
		while (curr != NULL && !found) {
			if (k > curr->key) {
				pre = curr;
				curr = curr->next;
			} else found = true;
		}
		if (head == curr) {
			temp->next = curr;
			head = temp;
		} else {
			pre->next = temp;
			temp->next = curr;
		}
	}
	return head;
}

ptr searchList (ptr head, int k) {
	return (head == NULL || head->key == k) ? head : searchList(head->next, k);
}

void insert (ptr a[], int k) {
	int i = hash(k);
	
	if (i >= 0 && i < M) {
		a[i] = insertInOrder(a[i], k);
	}
}

int search (ptr a[], int k) {
	int i = hash(k);
	
	ptr temp = searchList (a[i], k);
	
	return (temp->key == k) ? i : -1;
}

ptr deleteNode (ptr head, int k) {
	ptr curr = head, pre = NULL;
	if (head == NULL) {
		return head;
	} else {
		while (curr != NULL) {
			if (curr->key == k) {
				if (pre == NULL) {
					head = head->next;
				} else pre->next = curr->next;
				free(curr);
				return head;
			}
			pre = curr;
			curr = curr->next;
		}
	}
	return head;
}

bool deleted (ptr a[], int k) {
	int i = hash(k);
	
	a[i] = deleteNode (a[i], k);
	return (a[i] != NULL);
}
