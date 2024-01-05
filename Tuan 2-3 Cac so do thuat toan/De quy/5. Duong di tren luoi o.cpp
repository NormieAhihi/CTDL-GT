#include<stdio.h>

int countPaths(int i, int j, int d, int c); 

int main() {
 	int i, j, d, c;
	printf("Nhap gia tri cua i va j: ");
	scanf("%d %d", &i, &j);
	printf("Nhap gia tri cua d va c: ");
	scanf("%d %d", &d, &c);
	printf("So duong di tu nut (%d, %d) den nut (%d, %d) la: %d\n", i, j, d, c, countPaths(i, j, d, c));
	return 0; 
} 

int countPaths(int i, int j, int d, int c) {
	if(i>d || j>c) {
		return 0; 
	} else {
		if(i==d && j==c) {
			return 1; 
		} else {
			return countPaths(i+1, j, d, c) + countPaths(i, j+1, d, c);
		} 
	} 
} 
