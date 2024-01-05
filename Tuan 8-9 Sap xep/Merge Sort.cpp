#include<stdio.h>

void importArray(int a[], int n);
void printArray(int a[], int n); 
void merge(int a[], int low , int mid, int high);
void mergeSort(int a[], int low, int high); 

int main() {
	int n;
	int a[1000];
	
	printf("Nhap vao gia tri cua n: ");
	scanf("%d", &n);
	importArray(a, n); 
	mergeSort(a, 0, n-1); 
	printf("\nDay sau khi thuc hien sap xep tron la: ");
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

void merge(int a[], int low , int mid, int high) {
	int L[1000], R[1000];
	int i, j, k; 
	int n1 = mid - low + 1;
	int n2 = high - mid; 
	
	for(i = 0; i < n1; i++) {
		L[i] = a[i + low]; 
	} 
	for(j = 0; j < n2; j++) {
		R[j] = a[j + mid + 1]; 
	} 
	L[n1 + 1] = 9999;
	R[n2 + 2] = 9999;
	i = 0;
	j = 0; 
	k = low; 
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			a[k] = L[i];
			i++; 
		} else {
		    a[k] = R[j];
			j++;	
		} k++; 
	} 
	while(i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while(i < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
} 


void mergeSort(int a[], int low, int high) {
	int mid; 
	if(low < high) {
	   mid = (low + high) / 2;
	   mergeSort(a, low, mid);
	   mergeSort(a, mid + 1, high);
	   merge(a, low, mid, high); 
	} 
} 










