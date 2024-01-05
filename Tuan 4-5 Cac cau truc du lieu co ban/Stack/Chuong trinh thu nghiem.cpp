#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct StackNode {
	float item;
	StackNode *next; 
}; 

struct Stack {
	StackNode *top; 
}; 

Stack *StackConstruct();
int StackEmpty(const Stack *s);
int StackFull(const Stack *s);
int StackPush(Stack *s, float item);
float StackPop(Stack *s);
void Disp(Stack *s); 

int main() {
	int ch, n;
	float m;
	Stack *stackPtr; 
	
	while(1) {
		printf("\n\n======================\n");
		printf("CHUONG TRINH THU STACK\n");
		printf("======================\n");
		printf("1. Create\n2. Push\n3. Pop\n4. Display\n5. Exit\n"); 
		printf("---------------\n"); 
		printf("Chon chuc nang: ");
		scanf("%d", &ch);
		printf("\n");
		
		switch(ch) {
			case 1: 
			  printf("Da khoi tao STACK");
			  stackPtr = StackConstruct();
			  break;
			  
			case 2:
			  printf("Vao gia tri phan tu: ");
			  scanf("%f", &m);
			  printf("Gia tri phan tu nhap vao: %8.3f\n", m); 
			  StackPush(stackPtr, m);
			  break;
			  
			case 3:
			  m = StackPop(stackPtr);
			  if(m != NULL) {
			  	printf("\n Gia tri phan tu lay ra: %8.3f\n", m); 
			  } else {
			  	printf("\n >>> Empty Stack, can't pop <<<\n"); 
			  } 
			  break;
			  
			case 4: 
			  Disp(stackPtr);
			  break;
			  
			case 5:
			  printf("\nBye!Bye! \n");
			  getch();
			  exit(0);
			  break;
			  
			default:
			  printf("Wrong choice");
			  getch(); 
		} 
	} 
	
	return 0; 
} 

Stack *StackConstruct() {
	Stack *s;
	s = (Stack *)malloc(sizeof(Stack));
	if(s == NULL) {
		return NULL; 
	}
	s->top = NULL; 
	return s; 
}

int StackEmpty(const Stack *s) {
	return (s->top == NULL); 
}

int StackFull() {
	printf("\n NO MEMORY! STACK IS FULL");
	getch();
	return 1; 
}

int StackPush(Stack *s, float item) {
	StackNode *node;
	node = (StackNode *)malloc(sizeof(StackNode));
	if(node == NULL) {
		StackFull();
		return 1; 
	} 
	node->item = item;
	node->next = s->top;
	s->top = node;
	return 0; 
}

float StackPop(Stack *s) {
	float item;
	StackNode *node;
	if(StackEmpty(s)) {
		return NULL; 
	} 
	node = s->top;
	item = node->item;
	s->top = node->next;
	free(node);
	return item; 
}

void Disp(Stack *s) {
	StackNode *node;
	int ct = 0;
	float m;
	printf("\n\n DANH SACH CAC PHAN TU CUA STACK \n\n");
	if(StackEmpty(s)) {
		printf("\n\n >>>> EMPTY STACK <<<<\n");
		getch(); 
	} else {
		node = s->top;
		do {
			m = node->item;
			printf("%8.3f", m);
			ct++;
			if(ct % 9 == 0) {
				printf("\n"); 
			} 
			node = node->next; 
		} while(!(node == NULL)); 
		printf("\n"); 
	} 
}















