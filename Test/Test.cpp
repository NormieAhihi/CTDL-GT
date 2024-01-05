#include<stdio.h>

void swap(int* a, int* b); 
int partition(int a[], int low , int high);
void quickSort(int a[], int low, int high); 
void solve(int a[], int low, int high); 

int main() {
	int n, dem = 0; 
	int a[1000];
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	printf("Nhap vao %d phan tu cua day: ", n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]); 
	} 
	quickSort(a, 0, n-1); 
	printf("\nDay sau khi thuc hien sap xep nhanh la: ");
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]); 
	}  
	for(int j = 0; j < n; j++) {
		if(a[j] - a[j + 1] != 0) {
			dem++; 
		} 
	} 
	solve(a, 0, n-1); 
	printf("\nDay sau khi loai bo cac phan tu trung lap la: ");
	for(int i = 0; i < dem - 1; i++) {
		printf("%d ", a[i]);
	} 
	printf("%d ", a[n-1]); 
	printf("\n"); 
	
	return 0; 
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

void solve(int a[], int low, int high) {
	int b[1000];
	int i = 0, dem = 0; 
	for(int j = low; j < high; j++) {
		if(a[j] - a[j + 1] != 0) {
			b[i] = a[j];
			i++; 
			dem++; 
		} 
	} 
	for(int k = low; k < low + dem; k++) {
		a[k] = b[k - low]; 
	} 
}

















