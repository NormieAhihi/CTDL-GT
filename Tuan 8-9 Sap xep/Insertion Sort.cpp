#include<stdio.h>

void importArray(int a[], int n);
void printArray(int a[], int n); 
void insertionSort(int a[], int array_size); 

int main() {
	int n;
	int a[1000];
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	importArray(a, n); 
	insertionSort(a, n);
	printf("\nDay sau khi thuc hien sap xep chen la: ");
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

void insertionSort(int a[], int array_size) {
	int i, j, last;
	
	for(i = 1; i < array_size; i++) {
		last = a[i];
		j = i;
		while((j > 0) && (a[j-1] > last)) {
			a[j] = a[j-1];
			j = j-1; 
		} a[j] = last; 
	} 
}
