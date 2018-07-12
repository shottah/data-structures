/**
	Student Full Name: Matthew Abraham
	Student ID: 815009613
	E-mail: m.abrahamtt@gmail.com
	Course Code: COMP 2000
*/

#include <time.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Global Variables
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef Node* tree;

// Function Prototypes
void printMenu ();

void bft (tree root);
int max_I (tree root);
int max_R (tree root);
tree min_I (tree root);
tree min_R (tree root);
void init (tree *root);
int max (int a, int b);
int countNodes (tree root);
int countLeaves (tree root);
int height (tree root, int a);
tree getSuccessor (tree root);
int delete_I (tree *root, int key);
tree delete_R (tree root, int key);
tree search_I (int key, tree root);
tree search_R (int key, tree root);
void insert_I (int key, tree *root);
void insert_R (int key, tree *root);
void traversal (tree root, int mode);
tree ioSuccessor (tree root, int key);

int main () {
	
	int o = 0;
	int input = 0;
	tree node = NULL;
	
	tree root;
	init (&root);
	
	while (o!=18) {
		printMenu();
		printf("Option: ");
		scanf("%d",&o);
		while (o < 1 || o > 18) {
			printf("Enter a valid option (1-18): ");
			scanf("%d", &input);
		}
		if (o == 1 || o == 2) {
			printf("Enter a number to insert: ");
			scanf("%d", &input);
			if (o == 1) {
				insert_I (input, &root);
			} else if (o == 2) {
				insert_R (input, &root);
			}
		}
		else if (o == 3) {
			printf("Enter the type of traversal: ");
			scanf("%d", &input);
			traversal (root, input);
			printf("\n");
		}
		else if (o == 4 || o == 5) {
			printf("Enter a number to search for: ");
			scanf("%d", &input);
			if (o == 4) {
				node = search_I (input, root);
			} else if (o == 5) {
				node = search_R (input, root);
			}
			
			if (node!=NULL) {
				printf("Node has been found.\n");
			} else if (node == NULL) {
				printf("Node does not exist.\n");
			}
		}
		else if (o == 6) {
			input = countNodes (root);
			printf("There are %d nodes in this tree.\n", input);
		}
		else if (o == 7) {
			input = countLeaves (root);
			printf("There are %d leaves in this tree.\n", input);
		}
		else if (o == 8 || o == 9) {
			if (o == 8) {
				input = height (root, 0);
				printf("The height of the tree is %d.\n", input);
			} else if (o == 9) {
				input = height (root, 1);
				printf("There are %d levels in the tree.\n", input);
			}
		}
		else if (o == 10 || o == 11) {
			if (o == 10) {
				node = min_I (root);
			} else if (o == 11) {
				node = min_R (root);
			}
			printf("The minimum node in the tree is %d.\n", node->data);
		}
		else if (o == 12 || o == 13) {
			if (o == 12) {
				input = max_I (root);
			} else if (o == 13) {
				input = max_R (root);
			}
			printf("The maximum node in the tree is %d.\n", input);
		}
		else if (o == 14 || o == 15) {
			printf("Enter a node value to delete: ");
			scanf("%d", &input);
			if (o == 14) {
				if (delete_I(&root, input)){
					printf("The node holding %d has been deleted.\n", input);
				} else {
					printf("The node could not be found.\n");
				}
			} else if (o == 15) {
				root = delete_R (root, input);
				if (root == NULL) {
					printf("Tree is now empty after deletion.\n");
				} else if (root != NULL) {
					printf("The node holding %d has been deleted.\n", input);
				}
			}
		}
		else if (o == 16) {
			printf("Enter a node value to find the in-order successor for: ");
			scanf("%d", &input);
			node = ioSuccessor (root, input);
			if (node != NULL) {
				printf("The in-order successor of %d is %d.\n", input, node->data);
			} else {
				printf("The node holding %d does not have a successor.\n", input);
			}
		}
		else if (o == 17) {
			bft(root);
		}
		
	}
	
	return 0;
}

void printMenu () {
	printf("1. Insert a new node (iteration).\n");
	printf("2. Insert a new node (recursion).\n");
	printf("3. Tree traversal.\n");
	printf("4. Search for a node (iteration).\n");
	printf("5. Search for a node (recursion).\n");
	printf("6. Count number of nodes in a tree.\n");
	printf("7. Count number of leaves in a tree.\n");
	printf("8. Height of tree (root = 0).\n");
	printf("9. Levels of tree (root = 1).\n");
	printf("10. Find the node with minimum value (iteration).\n");
	printf("11. Find the node with minimum value (recursion).\n");
	printf("12. Find the node with maximum value (iteration).\n");
	printf("13. Find the node with maximum value (recursion).\n");
	printf("14. Delete a node from BST (iteration).\n");
	printf("15. Delete a node from BST (recursion).\n");
	printf("16. Find the in-order successor (without parent link).\n");
	printf("17. Breadth-first traversal (BFT).\n");
	printf("18. Exit.\n");
}

void init (tree *root) {
	*root = NULL;
}

void insert_I (int key, tree *root) {
	tree newNode = (tree)malloc(sizeof(Node));
	newNode->data = key;
	newNode->left = NULL;
	newNode->right = NULL;
	
	if (*root == NULL)
		*root = newNode;
	else {
		tree parent = NULL;
		tree curr = *root;
		
		while (true) {
			parent = curr;
			if (key < curr->data) {
				curr = curr->left;
				if (curr == NULL) {
					parent->left = newNode;
					break;
				}
			}
			else {
				curr = curr->right;
				if (curr == NULL) {
					parent->right = newNode;
					break;
				}
			}
		}
	}
	
}

void insert_R (int key, tree *root) {
	tree newNode;
	if (*root == NULL) {
		*root = (tree)malloc(sizeof(Node));
		(*root)->data = key;
		(*root)->left = NULL;
		(*root)->right = NULL;
	} else if (key < (*root)->data) {
		insert_R (key, &(*root)->left);
	} else if (key > (*root)->data) {
		insert_R (key, &(*root)->right);
	} else {
		
	}
}

void traversal (tree root, int mode) {
	/**
		1. In-order
		2. Pre-order
		3. Post-order
	*/
	if (mode == 1) {
		if (root != NULL){
			traversal(root->left, mode);
			printf("%d\t", root->data);
			traversal(root->right, mode);
		}
	} else if (mode == 2) {
		if (root != NULL){
			printf("%d\t", root->data);
			traversal(root->left, mode);
			traversal(root->right, mode);
		}
	} else if (mode == 3) {
		if (root != NULL){
			traversal(root->left, mode);
			traversal(root->right, mode);
			printf("%d\t", root->data);
		}
	}
}

tree search_I (int key, tree root) {
	tree curr = root;
	if (root != NULL) {
		while (curr->data != key) {
			if (key < curr->data) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
			if (curr == NULL) {
				return NULL;
			}
		}
		return curr;
	}
}

tree search_R (int key, tree root) {
	if (root == NULL)
		return NULL;
	else if (key < root->data)
		return search_R(key, root->left);
	else if (key > root->data)
		return search_R(key, root->right);
	else
		return root;
}

int countNodes (tree root) {
	if (root == NULL)
		return 0;
	else
		return 1+
		countNodes(root->left)+
		countNodes(root->right);
}

int countLeaves (tree root) {
	if (root == NULL)
		return 0;
	if ( (root->left == NULL) && root->right == NULL)
		return 1;
	return countLeaves(root->left)+
	countLeaves(root->right);
}

int max (int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}

int height (tree root, int a) {
	if (root == NULL)
		return -1+a;
	else
		return 1 + max(
		height(root->left, a), 
		height(root->right, a));
}

tree min_I (tree root) {
	tree min = NULL;
	tree curr = root;
	while (curr!=NULL) {
		min = curr;
		curr = curr->left;
	}
	return min;
}

tree min_R (tree root) {
	tree min = NULL;
	if (root->left == NULL)
		return root;
	else
		return min = min_R (root->left);
}

int max_I (tree root) {
	int max = 0;
	tree curr = root;
	while (curr!=NULL) {
		max = curr->data;
		curr = curr->right;
	}
	return max;
}

int max_R (tree root) {
	int max = 0;
	if (root->right == NULL)
		return root->data;
	else
		return max = max_R (root->right);
}

int delete_I (tree *root, int key) {
	tree p = NULL;
	tree curr = *root;
	int isLeftChild = 1;
	
	while (curr->data != key) {
		p = curr;
		if (key < curr->data) {
			isLeftChild = 1;
			curr = curr->left;
		} else {
			isLeftChild = 0;
			curr = curr->right;
		}
		if (curr == NULL)
			return 0;
	}
	
	if ((curr->left == NULL) && (curr->right == NULL)) {
		if (curr == *root)
			*root = NULL;
		else if (isLeftChild)
			p->left = NULL;
		else
			p->right = NULL;
	}
	
	else if (curr->right == NULL) {
		if (curr == *root)
			*root = curr->left;
		else if (isLeftChild)
			p->left = curr->left;
		else
			p->right = curr->left;
	}
	
	else if (curr->left == NULL) {
		if (curr == *root)
			*root = curr->right;
		else if (isLeftChild)
			p->left = curr->right;
		else
			p->right = curr->right;
	}
	
	else {
		tree q = getSuccessor (curr);
		if (curr == *root)
			*root = q;
		else if (isLeftChild)
			p->left = q;
		else
			p->right = q;
		
		q->left = curr->left;
	}
	return 1;
}

tree getSuccessor (tree del) {
	tree sp = del;
	tree s = del;
	tree curr = NULL;
	
	curr = del->right;
	while (curr!=NULL) {
		sp = s;
		s = curr;
		curr = curr->left;
	}
	
	if (s != del->right) {
		sp->left = s->right;
		s->right = del->right;
	}
	
	return s;
}

tree delete_R (tree root, int key) {
	tree temp, s;
	if (root == NULL) {
		return NULL;
	}
	else if (key < root->data)
		root->left = delete_R (root->left, key);
	else if (key > root->data)
		root->right = delete_R (root->right, key);
	else {
		if ( (root->left != NULL) && (root->right != NULL)) {
			s = min_R(root->right);
			root->data = s->data;
			root->right = delete_R (root->right, root->data);
		}
		else {
			temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			tree(temp);
		}
	}
	return root;
}

tree ioSuccessor (tree root, int key) {
	tree s = NULL, curr = root;
	if (root == NULL)
		return NULL;
	while (key != curr->data) {
		if (key < curr->data) {
			s = curr;
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	
	if ( (curr != NULL) && (curr->right != NULL))
		s = min_R(curr->right);
	
	return s;
}

void bft (tree root) {
	queue <tree> q;
	tree temp;
	if (root)
		q.push(root);
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		printf("%d\t", temp->data);
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	printf("\n");
}
