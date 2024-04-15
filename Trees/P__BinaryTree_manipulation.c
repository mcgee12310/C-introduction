#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;
typedef struct _TNode{
	data_t data;
	struct _TNode* leftChild;// con tro tro den nut con trai 
	struct _TNode* rightChild;// con tro tro den nut con phai
}TNode;

TNode *makeNode(int x){
	TNode *p = (TNode*) malloc(sizeof(TNode));
	if(p==NULL){printf("Error in mem allocation\n");exit(1);}
	p->data=x;
	p->leftChild=NULL;
	p->rightChild=NULL;
	return p;
}

TNode *find(TNode *r, int x){
	if(r == NULL) return NULL;
	if(r->data == x) return r;
	
	TNode *left, *right;

	left=find(r->leftChild, x);
	if(left != NULL) return left;
	right=find(r->rightChild, x);
	if(right != NULL) return right;
	
	return NULL;
}	

void InsertLeft(TNode *root, int u, int v) {
	TNode* p = find(root, v);
    if(p == NULL) return;               // E1: Not found
    if(p->leftChild != NULL) return;    // E2
    TNode* q = find(root, u);               // Kiểm tra xem cây đã có nút có key = id chưa
    if(q != NULL) return;               // E3: node having id = u exists -> do not insert more
    p->leftChild = makeNode(u);
}

void InsertRight(TNode *root, int u, int v) {
	TNode* p = find(root, v);
    if(p == NULL) return;               // E1: Not found
    if(p->rightChild != NULL) return;    // E2
    TNode* q = find(root, u);               // Kiểm tra xem cây đã có nút có key = id chưa
    if(q != NULL) return;               // E3: node having id = u exists -> do not insert more
    p->rightChild = makeNode(u);
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


int height(TNode* p){
	if(p == NULL) return 0;
	
	int hl=height(p->leftChild);
	int hr=height(p->rightChild);
	
	if(hl>hr) return hl+1;
	else return hr+1;
}

int isBalanced(TNode* root)
{
    /* for height of left subtree */
    int lh;
 
    /* for height of right subtree */
    int rh;
 
    /* If tree is empty then return true */
    if (root == NULL)
        return 1;
 
    /* Get the height of left and right sub trees */
    lh = height(root->leftChild);
    rh = height(root->rightChild);
 
    if (abs(lh - rh) <= 1 && isBalanced(root->leftChild) && isBalanced(root->rightChild)) return 1;
 
    /* If we reach here then tree is not height-balanced */
    return 0;
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
	int u, v;
	while(scanf("%s", &com) && com[0]!='*'){
		if(strcmp(com, "MakeRoot")==0){
			scanf("%d", &u);
			root = makeNode(u);
		}
		if(strcmp(com, "AddLeft")==0){
			scanf("%d %d", &u, &v);
			InsertLeft(root, u, v);
		}
		if(strcmp(com, "AddRight")==0){
			scanf("%d %d", &u, &v);
			InsertRight(root, u, v);
		}
		if(strcmp(com, "PreOrder")==0){ preOrder(root); printf("\n"); }

		if(strcmp(com, "PostOrder")==0){ postOrder(root); printf("\n"); }

		if(strcmp(com, "InOrder")==0){ inOrder(root); printf("\n"); }
	}
	freeTree(root);
	root = NULL;
}