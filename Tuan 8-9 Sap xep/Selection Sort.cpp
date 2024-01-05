#include<stdio.h>

void importArray(int a[], int n);
void printArray(int a[], int n); 
void swap(int &a, int &b); 
void selectionSort(int a[], int n);

int main() {
	int n;
	int a[1000];
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	importArray(a, n); 
	selectionSort(a, n);
	printf("\nDay sau khi thuc hien sap xep chon la: ");
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

void selectionSort(int a[], int n) {
	int i, j, min, temp; 
	
	for(i = 1; i < n-1; i++) {
		min = i;
		for(j = i+1; j < n; j++) {
			if(a[j] < a[min]) {
				min = j; 
			} 
		} 
		swap(a[i], a[min]); 
	} 
}

 
