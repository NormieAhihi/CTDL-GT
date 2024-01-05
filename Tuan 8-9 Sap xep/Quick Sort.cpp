#include<stdio.h>

void importArray(int a[], int n);
void printArray(int a[], int n); 
void swap(int* a, int* b); 
int partition(int a[], int low , int high);
void quickSort(int a[], int low, int high); 

int main() {
	int n;
	int a[1000];
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	importArray(a, n);
	quickSort(a, 0, n-1); 
	printf("\nDay sau khi thuc hien sap xep nhanh la: ");
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

int partition(int a[], int low , int high) {
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j < high; j++) {
		if(a[j] < pivot) {
			i++;
			swap(&a[i], &a[j]); 
		} 
	} 
	swap(&a[i+1], &a[high]);
	return (i+1); 
}

void quickSort(int a[], int low, int high) {
	if(low < high) {
		int pi = partition(a, low, high);
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high); 
	} 
}






