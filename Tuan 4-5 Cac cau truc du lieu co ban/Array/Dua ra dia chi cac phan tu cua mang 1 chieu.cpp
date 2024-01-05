#include<stdio.h>
#include<conio.h>
int main() {
	int one[] = {0, 1, 2, 3, 4};
	int *ptr;
	int rows = 5;
	ptr = one;
	
	printf("Address   Contents\n");
	for(int i = 0; i < rows; i++) {
		printf("%6u%7d\n", ptr+i, *(ptr+i));
        printf("\n"); 
	} 
 	getch(); 
} 
