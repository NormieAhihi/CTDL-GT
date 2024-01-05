#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	Node* left;
	Node* right;  
};
typedef struct Node* Tree;  
Tree root;

void Init(Tree &root); // Khoi tao cay rong  
Node* CreateNode(int x);
int InsertNode(Tree &root, Node* p); 
void Input(Tree &root);
void NLR(Tree root); // NLR - Node -> Left -> Right  
Node* SearchNode(Tree root, int x);

int main() {
	Tree root;
	int x; 
	
	Init(root);
	Input(root);
	printf("\nDuyet cay theo NLR\n"); 
	NLR(root);
	printf("\n\nNhap gia tri can tim: ");
	scanf("%d", &x); 
	Node *k = SearchNode(root, x);
	if(k == NULL) {
		printf("Khong tim thay!"); 
	} 
	else {
		printf("Tim thay phan tu %d", x); 
	} 
	printf("\n");
	 
	return 0; 
} 

void Init(Tree &root) {
	root = NULL;  
}

Node* CreateNode(int x) {
	Node* p = new Node;  
	if(p != NULL) {
		p->left = NULL;
		p->right = NULL;
		p->data = x;  
	} 
	
	return p;  
}

int InsertNode(Tree &root, Node* p) {
	if(root != NULL) {
		if(root->data == p->data) {
			return 0;  
		} 
		else if(root->data > p->data) {
			return InsertNode(root->left, p);  
		} 
		else {
			return InsertNode(root->right, p); 
		} 
	} 
	else {
		root = p;  
	} 
}

void Input(Tree &root) {
	int n, x;  
	printf("Nhap so luong Node can them: ");
	scanf("%d", &n); 
	for(int i = 1; i <= n; i++) {
		printf("Nhap data cua Node %d: ", i);
		scanf("%d", &x); 
		Node* p = CreateNode(x);
		InsertNode(root, p);  
	} 
}

void NLR(Tree root) {
	if(root != NULL) {
		printf("%d ", root->data);
		NLR(root->left);
		NLR(root->right);  
	} 
}

Node* SearchNode(Tree root, int x) {
	Node *p = root;
	
	while(p != NULL) {
		if(p->data == x) {
			return p;  
		} 
		else {
			if(x < p->data) {
				p = p->left; 
			} 
			else {
				p = p->right; 
			} 
		} 
	} 
	return NULL;  
}








