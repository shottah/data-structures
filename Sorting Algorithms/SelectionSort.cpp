/*
* Name: Selection Sort
*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main () {
	
	int sz = 10;
	int arr [10] = {9,3,8,1,2,4,7,6,5};
	
	for (int i = 0; i < sz - 2; i++) {
		int k = i;
		for (int j = i+1; j < sz - 1; j++) {
			if (arr[j] < arr[k]) {
				k = j;
			}
		}
		if (k != i) {
			int temp = arr[k];
			arr[k] = arr[i];
			arr[i] = temp;
		}
	}
	
	for (int i = 0; i < sz; i++) {
		printf("[%d]", arr[i]);
	}
	
	return 0;
}
