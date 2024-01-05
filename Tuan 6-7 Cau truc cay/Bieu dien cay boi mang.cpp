#include<bits/stdc++.h> 

#define MAXLENGTH 100
#define NIL -1

typedef int DataType;
typedef int Node;
typedef struct{
	DataType Data[MAXLENGTH];
	Node Parent[MAXLENGTH];
	int MaxNode; 
} Tree; 
Tree T;

void MakeNull_Tree(Tree *T); // Khoi tao cay rong 
int EmptyTree(Tree T); // Kiem tra cay rong 
Node Parent(Node n, Tree T); // Xac dinh nut cha  
DataType Label_Node(Node n, Tree T); // Xac dinh nhan cua nut  
Node Root(Tree T); // Xac dinh nut goc  
Node LeftMostChild(Node n, Tree T); // Xac dinh con trai nhat 
Node RightSibling(Node n, Tree T); // Xac dinh anh em ruot phai 
void PreOrder(Node n, Tree T); // Duyet theo thu tu truoc 
void InOrder(Node n, Tree T); // Duyet theo thu tu giua  
void PostOrder(Node n, Tree T); // Duyet theo thu tu sau
void InputTree(Tree *T); // Nhap du lieu cho cay

int main() {
	printf("Nhap du lieu cho cay:\n");
	InputTree(&T);
	
	printf("\nDanh sach duyet theo thu tu truoc cua cay la:\n");
	PreOrder(Root(T), T); 
	
	printf("\nDanh sach duyet theo thu tu giua cua cay la:\n");
	InOrder(Root(T), T); 
	
	printf("\nDanh sach duyet theo thu tu sau cua cay la:\n");
	PostOrder(Root(T), T); 
	
	printf("\n"); 
	
	return 0; 
} 

void MakeNull_Tree(Tree *T) {
	(*T).MaxNode = 0;  
}

int EmptyTree(Tree T) {
	return T.MaxNode == 0; 
}

Node Parent(Node n, Tree T) {
	if(EmptyTree(T) || (n > T.MaxNode - 1)) {
		return NIL; 
	} 
	else return T.Parent[n];  
} 

DataType Label_Node(Node n, Tree T) {
	if(!EmptyTree(T) && (n <= T.MaxNode - 1)) {
		return T.Data[n];  
	} 
}  

Node Root(Tree T) {
	if(!EmptyTree(T)) {
		return 0; 
	} 
	else {
		return NIL;  
	} 
} 

Node LeftMostChild(Node n, Tree T) {
	Node i;
	int found;
	
	if(n < 0) {
		return NIL; 
	} 
	i = n + 1;
	found = 0;
	while((i <= T.MaxNode - 1) && !found) {
		if(T.Parent[i] == n) {
			found = 1; 
		} 
		else {
			i++; 
		} 
	} 
	if(found) {
		return i; 
	} 
	else {
		return NIL;  
	} 
}

Node RightSibling(Node n, Tree T) {
	Node i, parent;
	int found;
	
	if(n < 0) {
		return NIL; 
	} 
	parent = T.Parent[n];
	i = n + 1;
	found = 0;
	while((i <= T.MaxNode - 1) && !found) {
		if(T.Parent[i] == parent) {
			found = 1; 
		} 
		else {
			i++; 
		} 
	} 
	if(found) {
		return i; 
	} 
	else {
		return NIL;  
	} 
}

void PreOrder(Node n, Tree T) {
	Node i;
	
	printf("%d ", Label_Node(n, T));
	i = LeftMostChild(n, T);
	while(i != NIL) {
		PreOrder(i, T);
		i = RightSibling(i, T); 
	} 
} 

void InOrder(Node n, Tree T) {
	Node i;
	
	i = LeftMostChild(n, T);
	if(i != NIL) {
		InOrder(i, T);  
	} 
	printf("%d ", Label_Node(n, T));
	i = RightSibling(i, T); 
	while(i != NIL) {
		InOrder(i, T);
		i = RightSibling(i, T); 
	} 
} 

void PostOrder(Node n, Tree T) {
	Node i;
	
	i = LeftMostChild(n, T);
	while(i != NIL) {
		PostOrder(i, T);
		i = RightSibling(i, T); 
	} 
	printf("%d ", Label_Node(n, T));
}

void InputTree(Tree *T) {
	int i;
	MakeNull_Tree(&*T); 
	do {
		printf("Nhap so luong nut cua cay: ");  
		scanf("%d", &(*T).MaxNode);  
	} while (((*T).MaxNode < 1) || ((*T).MaxNode > MAXLENGTH));
	printf("Nhap nhan cua nut goc: "); 
	fflush(stdin);
	scanf("%d", &(*T).Data[0]);
	(*T).Parent[0] = NIL;
	for(i = 1; i <= (*T).MaxNode - 1; i++) {
		printf("Nhap cha cua nut %d: ", i);  
		scanf("%d", &(*T).Parent[i]);  
		printf("Nhap nhan cua nut %d: ", i);  
		fflush(stdin); 
		scanf("%d", &(*T).Data[i]); 
	}
}












