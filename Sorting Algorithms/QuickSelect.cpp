#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int partition (int arr[], int L, int r) {
	int p = arr[L];		// Choose a pivot, random or left.
	int i = L + 1;		// Left Increment Tracker
	int j = r;			// Right Increment Tracker
	int temp;			// Temporary int
	
	while (true) {			// Infinite Loop
		while (i < r && arr[i] < p) {	// While numbers on left
			i++;					// are < pivot, move right
		}
		while (j > L && arr[j] > p) {	// While numbers on right
			j--;					// are > pivot, move left
		}
		if (i>=j) {				// If you've traversed entire array
			break;					// break
		}
		else {					// If there are still existing
			temp = arr[i];		// untraversed numbers, swap the
			arr[i] = arr[j];	// numbers that are at the L&R marks
			arr[j] = temp;
		}
	}
	
	temp = arr[L];
	arr[L] = arr[j];
	arr[j] = temp;
	
	return j;
}

int quickselect (int arr[], int L, int r, int k) {
	if (L==r) {			// If array is size 1
		printf("true");
		return arr[L];		// Only one element
	}
	
	int p = partition (arr, L, r);	// Pivot Element
	int x = p - L + 1;			// Length of required subarray for k
	if (x==k) {					// If k = 3rd element, x = 3 (Found)
		return arr[p];
	}
	else if (k < x) {			// If element is in L. subarray
		return quickselect (arr, L, p-1, k);
	}
	else {						// If element is in R. subarray
		return quickselect (arr, p+1, r, k - x);
	}
}

int main () {
	int a [10] = {1,9,2,8,3,8,4,7,6,5};
	int k = 5;
	int ans = quickselect (a, 0, 7, 5);
	printf("%d", ans);
	return 0;
}
