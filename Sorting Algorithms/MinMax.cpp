#include <stdio.h>
#include <stdlib.h>

using namespace std;

void minmax (int arr[], int L, int r, int &min, int &max) {
	if (L==r) {
		min = arr[L];
		max = arr[r];
	}
	else {
		int m = (L+r)/2;		// Find middle of Array
		minmax(arr,L,m,min,max);		// minmax L. Subarray
		int Lmin = min;					// Store left min
		int Lmax = max;					// Store left max
		
		minmax(arr,m+1,r,min,max);	// minmax R. subarray
		int Rmin = min;					// Store right min
		int Rmax = max;					// Store right max
		
		if (Lmin < Rmin) {			// Is L < R ?
			min = Lmin;					// Update proper min
		}
		else {
			min = Rmin;					// Update proper min
		}
		
		if (Lmax > Rmax) {			// Is L > R ?
			max = Lmax;					// Update proper max
		}
		else {
			max = Rmax;					// Update proper max
		}
	}
}

int main () {
	int arr[10] = {9,11,16,3,8,1,6,22,23,45};
	int min, max;
	
	minmax(arr,0,9,min,max);
	
	printf("min:%d\tmax:%d", min, max);
	
	return 0;
}
