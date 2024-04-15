#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _TNode{
	int data;
	struct _TNode* leftChild;
	struct _TNode* rightChild;
}TNode;

TNode *makeNode(int x){
	TNode *p = (TNode*) malloc(sizeof(TNode));
	if(p==NULL){printf("Error in mem allocation\n");exit(1);}
	p->data=x;
	p->leftChild=NULL;
	p->rightChild=NULL;
	return p;
}

TNode* Insert(TNode *root, int u) {
    if(root==NULL){
        root = makeNode(u);
        return root;
    }  
    if (u == root->data) return root;
    else if (u < root->data) {
        root->leftChild = Insert(root->leftChild, u);
    }
    else {
        root->rightChild = Insert(root->rightChild, u);
    }
}

void preOrder(TNode* r) {
	if(r == NULL) return;
	printf("%d ",r->data);
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}

void postOrder(TNode* r) {
	if(r == NULL) return;
	postOrder(r->leftChild);
	postOrder(r->rightChild);
	printf("%d ",r->data);
}

void inOrder(TNode* r) {
	if(r == NULL) return;
	inOrder(r->leftChild);
	printf("%d ",r->data);
	inOrder(r->rightChild);
}

TNode* find(TNode* root, int u){
    if(root == NULL){
        printf("Not found\n");
        return root;
    }
    if(root->data==u){
        return root;
    }
    if(u > root->data){
        return find(root->rightChild, u);
    } 
    if(u < root->data){
        return find(root->leftChild, u);
    } 
}

TNode* deleteNode(TNode* root, int u){
    // Base case
    if (root == NULL){
        return root;
    }
        
    // Recursive calls for ancestors of
    // node to be deleted
    if (u < root->data) {
        root->leftChild = deleteNode(root->leftChild, u);
        return root;
    }
    else if (u > root->data) {
        root->rightChild = deleteNode(root->rightChild, u);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->leftChild == NULL) {
        TNode* temp = root->rightChild;
        free(root);
        return temp;
    }
    else if (root->rightChild == NULL) {
        TNode* temp = root->leftChild;
        free(root);
        return temp;
    }
    
    // If both children exist
    else {
 
        TNode* succParent = root;
 
        // Find successor
        TNode* succ = root->rightChild;
        while (succ->leftChild != NULL) {
            succParent = succ;
            succ = succ->leftChild;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->leftChild = succ->rightChild;
        else
            succParent->rightChild = succ->rightChild;
 
        // Copy Successor Data to root
        root->data = succ->data;
 
        // Delete Successor and return root
        free(succ);
        return root;
    } 
}

void freeTree(TNode* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

int main(){
	TNode *root=NULL;
	char com[20];
	int u;
	while(scanf("%s", &com) && com[0]!='#'){
        if(strcmp(com, "insert")==0){
            scanf("%d", &u);
            root = Insert(root, u);
        }
        if(strcmp(com, "find")==0){
            scanf("%d", &u);
            printf("%d", find(root, u)->data);
        }
        if(strcmp(com, "delete")==0){
            scanf("%d", &u);
                if(find(root, u)==NULL) ;
                else {
                    root = deleteNode(root, u);
                    inOrder(root);
                    printf("\n");
                }
        }
        if(strcmp(com, "preorder")==0){ preOrder(root); printf("\n"); }

		if(strcmp(com, "postorder")==0){ postOrder(root); printf("\n"); }
    }
    freeTree(root);
    root=NULL;
}