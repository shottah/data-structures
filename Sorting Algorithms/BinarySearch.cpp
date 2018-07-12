/*
* Name: Binary Search
*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main () {
	
	int sz = 10;
	int arr[10] = {1,2,3,4,5,6,7,8,9};
	
	int l = 0, r = sz;
	int m;
	int i = -1;
	int key = 4;
	
	while (l<=r && i==-1) {
		m = (l+r)/2;
		if (key == arr[m]) {
			i = m;
		}
		else if (key < arr[m]) {
			r = m-1;
		}
		else {
			l = m+1;
		}
	}
	
	if (i == m) {
		printf("Key was found at arr[%d] = %d", i, key);
	}
	else {
		printf("Key was not found arr[%d] = %d", i, key);
	}
	
	
	return 0;
}
