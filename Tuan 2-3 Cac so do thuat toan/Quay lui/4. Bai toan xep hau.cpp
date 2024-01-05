#include<bits/stdc++.h>

int n, dem;
int a[20];

void Ghinhan();
int UCVh(int j, int k);
void Hau(int k); 

int main() {
	printf("Nhap kich thuoc ban co: n = ");
	scanf("%d", &n);
	printf("\n==== CAC CACH XEP QUAN HAU ====\n");
	dem = 0;
	Hau(1);
	if(dem == 0) {
		printf("Khong co cach xep nao!\n"); 
	} 
	 
	return 0; 
} 

void Ghinhan() {
	int i; 
	dem++;
    printf("%d) ", dem); 
    for(i = 1; i <= n; i++) {
    	printf("%d ", a[i]); 
	} printf("\n"); 
}

int UCVh(int j, int k) {
	int i;
	for(i = 1; i < k; i++) {
		if((j == a[i]) || (fabs(j-a[i]) == k-i)) {
			return 0; 
		} 
	} 
	
	return 1; 
}

void Hau(int k) {
	for(int j = 1; j <= n; j++) {
		if(UCVh(j, k)) {
			a[k] = j;
			if(k == n) {
				Ghinhan(); 
			} else {
				Hau(k+1); 
			} 
		} 
	} 
}








