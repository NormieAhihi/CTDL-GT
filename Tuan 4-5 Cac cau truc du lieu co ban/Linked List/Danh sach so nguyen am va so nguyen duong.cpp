#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h> 

typedef long ElementType;

struct PointerType {
	ElementType Inf;
	PointerType *Next; 
}; 

PointerType *Insert_ToHead(PointerType *First, ElementType X);
PointerType *Insert_Middle(PointerType *Pred, ElementType X);
PointerType *Delete_Head(PointerType *First);
ElementType Delete(PointerType *Pred);
void Print(PointerType *First);
int IsEmpty(PointerType *First);
PointerType *MakeNull(PointerType *First);
long random1(long min, long max);

int main() {
	PointerType *S1, *S2, *S3, *V1, *V2, *V3;
	ElementType a;
	int n;
	system("cls"); 
    
	S1 = NULL;
	// Tao phan tu dau tien 
	a = -100 + random1(0, 201);
	S1 = Insert_ToHead(S1, a);
	printf("Nhap vao so luong phan tu n = "); 
	scanf("%i", &n);
	printf("\n");
	// Tao ngau nhien danh sach va dua ra man hinh
	V1 = S1; 
	for(int i = 2; i <= n; i++) {
		a = -100 + random1(0, 201);
		V1 = Insert_Middle(V1, a); 
	} 
	printf("====> Danh sach ban dau: \n");
	Print(S1);
	printf("\n");
	
	V1 = S1;
	S2 = NULL;
	S3 = NULL;
	while(V1) {
		if(V1->Inf > 0) {
			if(!S2) {
				S2 = Insert_ToHead(S2, V1->Inf);
				V2 = S2; 
			} else {
				Insert_Middle(V2, V1->Inf);
				V2 = V2->Next; 
			} 
		} 
		if(V1->Inf < 0) {
			if(!S3) {
				S3 = Insert_ToHead(S3, V1->Inf);
				V3 = S3; 
			} else {
				Insert_Middle(V3, V1->Inf);
				V3 = V3->Next; 
			} 
		} 
		V1 = V1->Next; 
	}  
	
	printf("====> Danh sach so duong: \n");
	Print(S2);
	printf("\n"); 
	printf("====> Danh sach so am: \n");
	Print(S3);
	printf("\n");
	S1 = MakeNull(S1);
	S2 = MakeNull(S2);
	S3 = MakeNull(S3);
	getchar();
	getchar(); 	
	return 0; 
} 

PointerType *Insert_ToHead(PointerType *First, ElementType X) {
	PointerType *TempNode;
	
	TempNode = (PointerType *) malloc(sizeof(PointerType));
	TempNode->Inf = X;
	TempNode->Next = First;  
	First = TempNode;
	return First; 
} 

PointerType *Insert_Middle(PointerType *Pred, ElementType X) {
	PointerType *TempNode;
	
	TempNode = (PointerType *) malloc(sizeof(PointerType));
	TempNode->Inf = X;
	TempNode->Next = Pred->Next;
	Pred->Next = TempNode; 
	return TempNode; 
} 

PointerType *Delete_Head(PointerType *First) {
	PointerType *TempNode;
	
	TempNode = First->Next;
	free(First);
	return TempNode; 
} 

ElementType Delete(PointerType *Pred) {
	ElementType X;
	PointerType *TempNode;
	
	TempNode = Pred->Next;
	Pred->Next = Pred->Next->Next;
	X = TempNode->Inf;
	free(TempNode);
	return X; 
} 

void Print(PointerType *First) {
	PointerType *TempNode;
	TempNode = First;
	int count = 0;
	while(TempNode) {
		printf("%6d", TempNode->Inf);
		count++;
		TempNode = TempNode->Next;
		if(count%12 == 0) {
			printf("\n"); 
		} 
	} printf("\n"); 
} 

int IsEmpty(PointerType *First) {
	return !First; 
} 

PointerType *MakeNull(PointerType *First) {
	while(!IsEmpty(First)) {
		First = Delete_Head(First); 
	} return First; 
} 

long random1(long min, long max) {
	return min + rand() % (max + 1 - min); 
} 

