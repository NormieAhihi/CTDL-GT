#include<stdio.h>

void importArray(int a[], int n);
int linearSearch(int a[], int n, int k);

int main() {
	int n, k, check; 
	int a[1000];
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	importArray(a, n);
	printf("Nhap vao gia tri can tim: ");
	scanf("%d", &k);
	
	check = linearSearch(a, n, k);
	if(check == -1) {
		printf("\nKhong tim thay gia tri %d!", k); 
	} 
	else {
		printf("\nGia tri k o vi tri thu %d", check + 1); 
	} 
	
	return 0; 
} 

void importArray(int a[], int n) {
	printf("Nhap vao %d phan tu cua day: ", n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]); 
	} 
}

int linearSearch(int a[], int n, int k) {
	for(int i = 0; i < n; i++) {
		if(a[i] == k) {
			return i; 
		} 
	} return -1; 
}


