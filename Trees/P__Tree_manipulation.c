#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;
typedef struct _TNode{
	data_t data;
	struct _TNode* leftMostChild;// con tro tro den nut con trai nhat
	struct _TNode* rightSibling;// con tro tro den nut anh em ben phai
}TNode;

TNode *makeNode(int x){
	TNode *p = (TNode*) malloc(sizeof(TNode));
	if(p==NULL){printf("Error in mem allocation\n");exit(1);}
	p->data=x;
	p->leftMostChild=NULL;
	p->rightSibling=NULL;
	return p;
}

TNode *find(TNode *r, int x){
	if(r == NULL) return NULL;
	if(r->data == x) return r;
	
	TNode *p = r->leftMostChild,*q;
	while(p!=NULL){
		q=find(p, x);
		if(q!=NULL) return q;
		p = p->rightSibling;
	}
	
	return NULL;
}

void insert(TNode* r, int u, int v){
    TNode* p = find(r,v);
    if(p == NULL) return;
    // insert new node to the end of the linked list children of p
    if(p->leftMostChild == NULL){
        p->leftMostChild = makeNode(u);
        return;
    }
    else {
        TNode* h;
        for (h = p->leftMostChild; h->rightSibling != NULL; h = h->rightSibling) ;
        h->rightSibling = makeNode(u);
    }
}

void freeTree(TNode *r){
	if(r == NULL) return;
	
	TNode *p = r->leftMostChild;
	while(p!=NULL){
		freeTree(p);
		p = p->rightSibling;
	}

	free(r);
}

void preOrder(TNode *r){
	if(r == NULL) return;
	printf("%d ",r->data);
	
	TNode *p = r->leftMostChild;
	while(p!=NULL){
		preOrder(p);
		p = p->rightSibling;
	}
}

void postOrder(TNode *r){
	if(r == NULL) return;
	
	TNode *p = r->leftMostChild;
	while(p!=NULL){
		postOrder(p);
		p = p->rightSibling;
	}

	printf("%d ",r->data);
}

void inOrder(TNode *r){
	if(r == NULL) return;
	
	TNode *p = r->leftMostChild;
	inOrder(p);
	printf("%d ",r->data);
	
	if(p!=NULL) p = p->rightSibling;
	while(p!=NULL){
		inOrder(p);
		p = p->rightSibling;
	}
}

TNode* parent(TNode* r, TNode* q){
	if(r == NULL) return NULL;
	
	TNode *p = r->leftMostChild;
	while(p!=NULL){
		if(p==q) return r;
		p = p->rightSibling;
	}
	
	p = r->leftMostChild;
	TNode *pp=NULL;
	while(p!=NULL){
		pp=parent(p,q);
		if(pp!=NULL) return pp;
		p = p->rightSibling;
	}
	
	return NULL;
}

int count(TNode* r){
	if(r == NULL) return 0;
	int dem=1;
	
	TNode *p = r->leftMostChild;
	while(p!=NULL){
		dem+=count(p);
		p = p->rightSibling;
	}
	
	return dem;
}

int height(TNode* p){
	if(p == NULL) return 0;
	int hc, maxh=0;
	
	TNode *pp = p->leftMostChild;
	while(pp!=NULL){
		hc=height(pp);
		if(hc>maxh) maxh=hc;
		pp = pp->rightSibling;
	}
	
	return maxh+1;
}

int stepdepth(TNode* r, int u, int level){
	if(r == NULL) return 0;
	if(r->data == u) return 1;
	
	TNode *p = r->leftMostChild;
	int lv=0;
	while(p!=NULL){
		lv=stepdepth(p,u,level+1);
		if(lv!=0) return lv+1;
		p = p->rightSibling;
	}
	return 0;
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
		if(strcmp(com, "Insert")==0){
			scanf("%d %d", &u, &v);
			insert(root, u, v);
		}
		if(strcmp(com, "PreOrder")==0){ preOrder(root); printf("\n"); }

		if(strcmp(com, "PostOrder")==0){ postOrder(root); printf("\n"); }

		if(strcmp(com, "InOrder")==0){ inOrder(root); printf("\n"); }
	}
}