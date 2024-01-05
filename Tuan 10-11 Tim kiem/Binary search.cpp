#include<stdio.h>

void importArray(int a[], int n);
int binarySearch(int a[], int n, int k);

int main() {
	int n, k, check; 
	int a[1000];
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	importArray(a, n);
	printf("Nhap vao gia tri can tim: ");
	scanf("%d", &k);
	
	check = binarySearch(a, n, k);
	if(check == -1) {
		printf("\nKhong tim thay gia tri %d!", k); 
	} 
	else {
		printf("\nGia tri k o vi tri thu %d", check + 1); 
	} 
	printf("\n"); 
	
	return 0; 
} 

void importArray(int a[], int n) {
	printf("Nhap vao %d phan tu cua day: ", n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]); 
	} 
}

int binarySearch(int a[], int n, int k) {
	int lower = 0, upper = n - 1, mid;
	
	while(lower <= upper) {
		mid = (lower + upper) / 2;
		if(a[mid] > k) {
			upper = mid - 1; 
		} 
		else if (a[mid] < k) {
			lower = mid + 1; 
		} 
		else {
			return mid; 
		} 
	} 
	return -1;  
}





