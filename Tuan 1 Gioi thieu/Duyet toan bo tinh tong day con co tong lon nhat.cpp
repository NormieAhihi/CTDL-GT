#include<stdio.h>
int main() {
    int a[1000], n;
	printf("Nhap vao gia tri cua n: "); 
	scanf("%d", &n);
	printf("Nhap day so: "); 
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]); 
	} 
	int maxSum = a[0];
	for(int i = 0;i < n;i++) {
		int sum = 0; 
		for(int j = i;j < n;j++) {
			{
				sum += a[j]; 
				if(sum > maxSum) {
				    maxSum = sum; 
			    } 
			} 
		} 
	} 
	printf("Tong cua day con co tong lon nhat la: %d", maxSum); 
	return 0; 
}
