#include<stdio.h>
#include<stdlib.h>

struct TreeNodeRec {
	float key;
	struct TreeNodeRec* leftPtr;
	struct TreeNodeRec* rightPtr;  
}; 
typedef struct TreeNodeRec TreeNode;

TreeNode* makeTreeNode(float value);
TreeNode* find_min(TreeNode* T);
TreeNode* find_max(TreeNode* T);
TreeNode* insert(TreeNode* nodePtr, float item); 
TreeNode* del(TreeNode* T, float item);
TreeNode* search(TreeNode* nodePtr, float item);
void printInorder(const TreeNode* nodePtr); 
void printPreorder(const TreeNode* nodePtr); 
void printPostorder(const TreeNode* nodePtr); 

int main() {
	
	return 0; 
} 

TreeNode* makeTreeNode(float value) {
	TreeNode* newNodePtr = NULL;
	newNodePtr = (TreeNode*)malloc(sizeof(TreeNode));
	if(newNodePtr == NULL) {
		fprintf(stderr, "Out of memory\n");
		exit(1);  
	} 
	else {
		newNodePtr->key = value;
		newNodePtr->leftPtr = NULL;
		newNodePtr->rightPtr = NULL;  
	} 
	return newNodePtr;  
}

TreeNode* find_min(TreeNode* T) {
	if(T == NULL) {
		return NULL; 
	} 
	else {
		if(T->leftPtr == NULL) {
			return T; 
		} 
		else {
			return find_min(T->rightPtr);  
		} 
	} 
}

TreeNode* find_max(TreeNode* T) {
	if(T != NULL) {
		while(T->rightPtr != NULL) {
			T = T->rightPtr;  
		} 
	} 
	return T;  
}

TreeNode* insert(TreeNode* nodePtr, float item) {
	if(nodePtr == NULL) {
		nodePtr = makeTreeNode(item);  
	} 
	else if(item < nodePtr->key) {
		nodePtr->leftPtr = insert(nodePtr->leftPtr, item);  
	} 
	else if(item > nodePtr->key) {
		nodePtr->rightPtr = insert(nodePtr->rightPtr, item);  
	} 
	return nodePtr;  
}

TreeNode* del(TreeNode* T, float item) {
	TreeNode tmp;
	if(T == NULL) {
		printf("Not found\n"); 
	} 
	else if(item < T->key) {
		T->leftPtr = del(T->leftPtr, item);  
	} 
	else if(item > T->key) {
		T->rightPtr = del(T->rightPtr, item); 
	} 
	else {
		if(T->leftPtr && T->rightPtr) {
			// phan tu the cho la phan tu min o cay con phai
			tmp = find_min(T->rightPtr);
			T->key = tmp->key;
			T->rightPtr = del(T->key, T->rightPtr);  
		} 
		else {
			// co 1 con hoac khong co con nao
			tmp = T;
			if(T->leftPtr == NULL) {
				T = T->rightPtr; 
			} 
			else {
				if(T->rightPtr == NULL) {
					T = T->leftPtr;  
				} 
			} 
		} 
		free(tmp); 
	} 
	return T;  
}

TreeNode* search(TreeNode* nodePtr, float item) {
	
}

void printInorder(const TreeNode* nodePtr) {
	
} 

void printPreorder(const TreeNode* nodePtr) {
	
}

void printPostorder(const TreeNode* nodePtr) {
	
} 








