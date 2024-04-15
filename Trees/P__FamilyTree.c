#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char data_t;
typedef struct _TNode{
	data_t data[20];
	struct _TNode* leftMostChild;// con tro tro den nut con trai nhat
	struct _TNode* rightSibling;// con tro tro den nut anh em ben phai
}TNode;

TNode *makeNode(char x[]){
	TNode *p = (TNode*) malloc(sizeof(TNode));
	if(p==NULL){printf("Error in mem allocation\n");exit(1);}
	strcpy(p->data, x);
	p->leftMostChild=NULL;
	p->rightSibling=NULL;
	return p;
}

TNode *InsertSibling(TNode *root, char data[]) {
  TNode* pNewNode = makeNode(data);

  if (root == NULL) return (TNode*)pNewNode;

  TNode* p = NULL;
  for (p = root; p->rightSibling != NULL; p = p->rightSibling)
    ;
  p->rightSibling = pNewNode;
  return root;
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
	printf("%s ",r->data);
	
	TNode *p = r->leftMostChild;
	while(p!=NULL){
		preOrder(p);
		p = p->rightSibling;
	}
}

TNode *find(TNode *r, char x[]){
	if(r == NULL) return NULL;
	if(strcmp(r->data, x)==0) return r;
	
	TNode *p = r->leftMostChild,*q;
	while(p!=NULL){
		q=find(p,x);
		if(q!=NULL) return q;
		p = p->rightSibling;
	}
	
	return NULL;
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

void insert(TNode* root, char p[], char c[]){
	if(find(root, p) == NULL && find(root, c) == NULL){
		if(root->leftMostChild == NULL) root->leftMostChild=makeNode(p);
		else root->leftMostChild = InsertSibling(root->leftMostChild, p);
		find(root, p)->leftMostChild=makeNode(c);
	}
	else if(find(root, p) != NULL && find(root, c) == NULL){
		if(find(root, p)->leftMostChild == NULL) find(root, p)->leftMostChild=makeNode(c);
		else find(root, p)->leftMostChild=InsertSibling(find(root, p)->leftMostChild, c);
	}

	else if(find(root, p) != NULL && find(root, c) != NULL){
		TNode* target = find(root, p);
		TNode* tmp = find(root, c);
		TNode* f = parent(root, find(root, c));
		if(f->leftMostChild->rightSibling==NULL) f->leftMostChild=NULL;
		else{
			f=f->leftMostChild;
			while(f->rightSibling!=find(root, c)) f=f->rightSibling;
			f->rightSibling=f->rightSibling->rightSibling;
		}
		if(target->leftMostChild == NULL) target->leftMostChild=tmp;
		else{
			target=target->leftMostChild;
			while(target->rightSibling!=NULL) target=target->rightSibling;
			target->rightSibling=tmp;
		} 
	}
}

int countNodeKChild(TNode* r, int k){
	if(r == NULL || k<=0) return 0;

	int dem=0,c=0;
	
	TNode *p = r->leftMostChild;
	while(p!=NULL){
		c++;
		dem+=countNodeKChild(p,k);
		p = p->rightSibling;
	}
	
	if(c==k)
		return dem + 1;
	else return dem;
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

int main(){

	TNode *root=makeNode("\0");
	char p[20], c[20], com[20];
	while(scanf("%s", &c) && c[0]!='*'){
		scanf("%s", &p);
		insert(root, p, c);
	}
	while(scanf("%s", &com) && com[0]!='*'){
		if(strcmp(com, "descendants")==0){
			char name[20];
			scanf("%s", &name);
			printf("%d\n", count(find(root, name))-1);
		} 
		if(strcmp(com, "generation")==0){
			char name[20];
			scanf("%s", &name);
			printf("%d\n", height(find(root, name))-1);
		}
	}
	
	//preOrder(root);
}