#include<stdio.h>

void importArray(int a[], int n);
void printArray(int a[], int n); 
void swap(int &a, int &b);
void bubbleSort(int a[], int n); 

int main() {
	int n;
	int a[1000];
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	importArray(a, n);
	bubbleSort(a, n);
	printf("\nDay sau khi thuc hien sap xep noi bot la: ");
	printArray(a, n);
	
	return 0; 
} 

void importArray(int a[], int n) {
	printf("Nhap vao %d phan tu cua day: ", n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]); 
	} 
}

void printArray(int a[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]); 
	} 
	printf("\n"); 
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp; 
}

void bubbleSort(int a[], int n) {
	int i, j;
	
	for(i = n-1; i >= 0; i--) {
		for(j = 1; j <= i; j++) {
			if(a[j-1] > a[j]) {
				swap(a[j-1], a[j]); 
			} 
		} 
	} 
}




















