#include<stdio.h>

void importArray(int a[], int n);
void printArray(int a[], int n); 
void swap(int* a, int* b); 
void heapify(int a[], int n , int i);
void heapSort(int a[], int n); 

int main() {
	int n;
	int a[1000];
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	importArray(a, n); 
	heapSort(a, n); 
	printf("\nDay sau khi thuc hien sap xep vun dong la: ");
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

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp; 
}

void heapify(int a[], int n , int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if(left < n && a[left] > a[largest]) {
		largest = left; 
	} 
	if(right < n && a[right] > a[largest]) {
		largest = right; 
	} 
	
	if(largest != i) {
		swap(&a[i], &a[largest]);
		heapify(a, n, largest); 
	} 
	 
}

void heapSort(int a[], int n) {
	for(int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i); 
	} 
	for(int i = n - 1; i >= 0; i--) {
		swap(&a[0], &a[i]);
		heapify(a, i, 0); 
	} 
}






