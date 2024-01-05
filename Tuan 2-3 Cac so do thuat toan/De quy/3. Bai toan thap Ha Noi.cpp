#include<stdio.h>

int i = 0; 
void hanoiTower(int n, char start, char finish, char spare); 

int main() {
 	int n;
	printf("Nhap gia tri cua n: ");
	scanf("%d", &n);
	hanoiTower(n, 'a', 'b', 'c');
	printf("Tong so lan chuyen dia la: %d\n", i); 
 	
 	return 0; 
} 

void hanoiTower(int n, char start, char finish, char spare) {
	if(n == 1) {
		printf("Dich chuyen dia tu coc %c sang coc %c\n", start, finish);
		i++;
		return; 
	} else {
		hanoiTower(n-1, start, spare, finish);
		hanoiTower(1, start, finish, spare);
	    hanoiTower(n-1, spare, finish, start);
	} 
} 
