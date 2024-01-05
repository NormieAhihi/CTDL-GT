#include<stdio.h>

int maxSub(int a[], int low, int high);
int maxLeft(int a[], int low, int mid);
int maxRight(int a[], int mid, int high); 
int max2(int a, int b);
int max3(int a, int b, int c); 

int main() {
	int a[1000], n;
	printf("Nhap vao gia tri cua n: "); 
	scanf("%d", &n);
	printf("Nhap day so: "); 
	for(int i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]); 
	} 
	printf("Tong cua day con co tong lon nhat la: %d", maxSub(a, 0, n-1));
	return 0; 
} 

int max2(int a1, int b1) {
	if(a1 >= b1) {
		return a1; 
	} else {
		return b1; 
	} 
} 

int maxLeft(int a[], int low, int mid) {
	int maxSum = -99;
	int sum = 0;
	for(int k = mid ; k >= low ; k--) {
		sum += a[k];
		maxSum = max2(sum, maxSum); 
	} 
	return maxSum; 
}

int maxRight(int a[], int mid, int high) {
	int maxSum = -99;
	int sum = 0;
	for(int k = mid+1 ; k <= high ; k++) {
		sum += a[k];
		maxSum = max2(sum, maxSum); 
	} 
	return maxSum; 
}

int max3(int a1, int b1, int c1) {
	if(a1 >= b1 && a1 >= c1) {
		return a1; 
	} else {
		if(b1 >= c1) {
			return b1; 
		} else {
			return c1; 
		} 
	} 
} 

int maxSub(int a[], int low, int high) {
	int mid, wL, wR, wM; 
	if(low == high) {
		return a[low]; 
	} else {
		mid = (low+high) / 2;
		wL = maxSub(a, low, mid);
		wR = maxSub(a, mid, high);
		wM = maxLeft(a, low, mid) + maxRight(a, mid, high);
		return max3(wL, wR, wM); 
	} 
} 







