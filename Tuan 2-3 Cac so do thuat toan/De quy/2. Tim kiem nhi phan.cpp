#include<stdio.h>

int bSearch(int low, int high, int a[], int k); 

int main() {
	int n, a[1000], k;
	printf("Nhap gia tri cua n: ");
	scanf("%d", &n);
	printf("Nhap gia tri cua day: ");
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]); 
	} 
	printf("Nhap gia tri cua k: ");
	scanf("%d", &k);
	printf("Gia tri %d nam o vi tri thu: %d\n", k, bSearch(0, n-1, a, k)); 
	
	return 0; 
} 

int bSearch(int low, int high, int a[], int k) {
	int middle = (low+high) / 2;
	if(low == high) {
		if(a[middle] == k) {
			return middle + 1; 
		} else {
			return -1; 
		} 
	} 
	if(a[middle] == k) {
		return middle; 
	} else if(a[middle] > k) {
		return bSearch(low, middle-1, a, k); 
	} else {
		return bSearch(middle+1, high, a, k); 
	} 
} 
