/*
* Name: Linear Search
*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main () {
	
	int sz = 10;
	int arr [10] = {9,3,2,8,7,1,4,7,6,5};
	
	int key = 1;
	
	for (int i = 0; i < sz; i++) {
		if (arr[i] == key) {
			printf("Key found at arr[%d] = %d", i, key);
		}
	}
	
	return 0;
}
