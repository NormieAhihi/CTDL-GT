#include<stdio.h>

int n, count, k;
int b[100], s[100];

void Ghinhan();
void Xau();

int main() {
	printf("Nhap gia tri cua n: ");
	scanf("%d", &n);
	count = 0; 
	Xau();
	printf("So luong xau la: %d\n", count); 
	return 0; 
} 

void Ghinhan() {
	int i, j;
	count++;
	printf("Xau thu %d: ", count);
	for(i = 1; i <= n; i++) {
		j = b[i];
		printf("%d ", j); 
	} printf("\n"); 
} 

void Xau() { 
	k = 1;
	s[k] = 0;
	while(k > 0) {
		while(s[k] <= 1) {
			b[k] = s[k];
			s[k] = s[k]+1;
			if(k == n) {
				Ghinhan(); 
			} else {
				k++;
				s[k] = 0; 
			} 
		}  
		k--; 
	} 
} 
