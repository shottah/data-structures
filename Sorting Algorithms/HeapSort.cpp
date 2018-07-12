#include <stdio.h>
#include <stdlib.h>

using namespace std;

void heapify (int arr[], int L, int r) {
	int j, temp;
	temp = arr[L];
	j = 2*L;
	while (j<=r) {
		if (j < r && arr[j+1] > arr[j]) {
			j++;
		}
		if (temp > arr[j]) {
			break;
		}
		else if(temp <= arr[j]) {
			arr[j/2] = arr[j];
			j = 2*j;
		}
	}
	arr[j/2] = temp;
}

void heapsort (int arr[], int n) {
	int temp;
	for (int i = n; i >= 2; i--) {
		temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;
		heapify(arr, 1, i-1);
	}	
}

void buildheap (int arr[], int n) {
	for (int i = n/2; i >= 1; i--) {
		heapify (arr, i, n);
	}
}

int main () {
	int a[11] = {0,9,1,8,2,8,3,7,4,6,5};
	
	for (int i = 1; i < 11; i++) {
		printf("[%d]",a[i]);
	}
	
	printf("\n");
	
	buildheap(a,11-1);
	
	for (int i = 1; i < 11; i++) {
		printf("[%d]",a[i]);
	}
	
	printf("\n");
	
	heapsort (a,11-1);
	
	for (int i = 1; i < 11; i++) {
		printf("[%d]",a[i]);
	}
	
}
