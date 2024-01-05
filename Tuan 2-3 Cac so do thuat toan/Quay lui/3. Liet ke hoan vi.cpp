#include<stdio.h>

int n, m, count;
int a[100]; 

void Ghinhan();
bool UCV(int j, int k);
void Hoanvi(int i); 

int main() {
	printf("Nhap gia tri cua n: ");
	scanf("%d", &n);
	count = 0;
	Hoanvi(1);
	printf("So hoan vi la: %d", count); 
	return 0; 
} 

void Ghinhan() {
	int i, j;
	count++;
	printf("Hoan vi thu %d: ", count);
	for(i = 1; i <= n; i++) {
		printf("%d ", a[i]); 
	} printf("\n"); 
} 

bool UCV(int j, int k) {
	int i;
	for(i = 1; i <= k-1; i++) {
		if(j == a[i]) {
			return false; 
		} 
	} return true; 
} 

void Hoanvi(int i) {
	int j;
	for(j = 1; j <= n; j++) {
		if(UCV(j, i)) {
			a[i] = j;
			if(i == n) {
				Ghinhan(); 
			} else {
				Hoanvi(i+1); 
			} 
		} 
	} 
} 





