#include<stdio.h> 

int C(int n, int k);

int main() {
	int n, k;
	printf("Nhap gia tri cua n: ");
	scanf("%d", &n);
	printf("Nhap gia tri cua k: ");
	scanf("%d", &k);
	while(n<0 || k>n) {
		printf("Nhap lai gia tri cua n va k: ");
		scanf("%d%d", &n, &k); 
	} 
	printf("C(%d,%d)=%d", n, k, C(n,k)); 
	
	return 0; 
} 

int C(int n, int k) {
	if(k==0 || k==n) {
		return 1; 
	} else {
		return C(n-1, k) + C(n-1, k-1); 
	} 
} 
