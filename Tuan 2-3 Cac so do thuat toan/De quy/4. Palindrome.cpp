#include<stdio.h>
#include<string.h> 

bool palindrome(char xau[], int start, int stop); 

int main() {
	char xau[1000];
	printf("Nhap xau ky tu: "); 
	fgets(xau, sizeof(xau), stdin); 
	bool ok = palindrome(xau, 0, sizeof(xau)-1);
	if(ok) {
		printf("Xau da cho la palindrome\n"); 
	} else {
		printf("Xau da cho khong la palindrome\n"); 
	} 
	return 0; 
} 

bool palindrome(char xau[], int start, int stop) {
	if(start-stop == 1) {
		return true; 
	} else {
		return xau[start]==xau[stop] && palindrome(xau, start+1, stop-1); 
	} 
} 
