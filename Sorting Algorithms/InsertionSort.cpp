/*
* Name: Insertion Search
*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main () {
	
	int sz = 10;
	int arr[10] = {2,4,6,8,1,3,9,7,5};
	
	int x, j;
	
	for (int i = 0; i < sz - 1; i++) {
		 x = arr[i];
		 j = i - 1;
		while (j >= 0 && arr[i] > x) {
			arr[j+1] = arr[j];
			j--;
			printf("Current number is %d at arr[%d]", arr[j], j);
		}
		arr[j+i] = x;
	}
	
	return 0;
}
