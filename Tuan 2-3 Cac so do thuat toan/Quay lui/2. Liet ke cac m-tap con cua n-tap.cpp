#include<stdio.h>

int n, m, count, k;
int a[100], s[100];

void Ghinhan();
void MSet(int i); 

int main() {
	printf("Nhap gia tri cua n va m: ");
	scanf("%d %d", &n, &m);
	a[0] = 0;
	count = 0;
	MSet(1); 
	printf("So tap con %d phan tu cua tap %d phan tu la: %d\n", m, n, count); 
	return 0; 
} 

void Ghinhan() {
	int i;
	count++;
	printf("Tap con thu %d: ", count);
	for(i = 1; i <= m; i++) {
		printf("%d ", a[i]); 
	} printf("\n"); 
} 

void MSet(int i) {
	k = 1;
	s[k] = 1;
	while(k > 0) {
		while(s[k] < n-m+k) {
			a[k] = s[k];
			s[k] = s[k]+1;
			if(k == m) {
				Ghinhan(); 
			} else {
				k++;
				s[k] = a[k-1]+1; 
			} 
		} k--; 
	} 
}





