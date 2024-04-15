#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Polynom {
	int data;
	struct _Polynom *next;
} Polynom;

Polynom *makeNode(const int a){
	Polynom *p = (Polynom*) malloc(sizeof(Polynom));
	if(p==NULL){printf("Error in mem allocation\n");exit(1);}
	p->data=a;
	p->next=NULL;
	return p;
}

void printList(Polynom *h){
	Polynom *p=h;
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}

Polynom *insertHead(Polynom *h,int co){
	Polynom* q = makeNode(co);

	if(h == NULL){
		return q;
	}
	
	q->next = h;
	return q;
}

Polynom *insertTail(Polynom *h,const int a) {
  Polynom* q = makeNode(a);

  if (h == NULL) return q;

  Polynom *p = NULL;
  for (p = h; p->next != NULL; p = p->next)
    ;
  p->next = q;
  return h;
}


Polynom *removeHead(Polynom *h){
	if(h==NULL) return NULL;
	
	Polynom* q = h->next;

	free(h);
	
	return q;
}

Polynom *Reverse(Polynom *h) {
  Polynom *cur, *prev;

  for (cur = prev = NULL; h != NULL;) {
    cur = h;
    h = h->next;
    cur->next = prev;
    prev = cur;
  }
  return cur;
}

Polynom *SumTwoPol(Polynom *px, Polynom *qx){
	if(px==NULL && qx==NULL) return NULL;
	Polynom *fx=NULL;
		
	while(px!=NULL && qx!=NULL){
		fx=insertHead(fx, px->data + qx->data);
		px=removeHead(px);
		qx=removeHead(qx);
	}
	
	while(px!=NULL){
		fx=insertHead(fx, px->data);
		px=removeHead(px);
	} 
	
	while(qx!=NULL){
		fx=insertHead(fx, qx->data);
		qx=removeHead(qx);
	} 

	int check=0;
	while(fx!=NULL){
		if(fx->data==0) ;
		else{
			check = 1;
			break;
		} 
		fx=fx->next;
	}	
	if(check==0) {
		Polynom* zero = makeNode(0);
		return zero;
	}	
	return fx;
}

Polynom *MinusTwoPol(Polynom *px, Polynom *qx){
	if(px==NULL && qx==NULL) return NULL;
	Polynom *fx=NULL;
		
	while(px!=NULL && qx!=NULL){
		fx=insertHead(fx, px->data - qx->data);
		px=removeHead(px);
		qx=removeHead(qx);
	}
	
	while(px!=NULL){
		fx=insertHead(fx, px->data);
		px=removeHead(px);
	} 
	
	while(qx!=NULL){
		fx=insertHead(fx, (qx->data)*-1);
		qx=removeHead(qx);
	} 

	int check=0;
	while(fx!=NULL){
		if(fx->data==0) fx=fx->next;
		else{
			check = 1;
			break;
		} 
	}	
	if(check==0) {
		Polynom* zero = makeNode(0);
		return zero;
	}
	
	return fx;
}

int count(Polynom *fx){
	int i=0;
	if(fx->data==0&&fx->next==NULL) return 1;
	while(fx!=NULL){
		if(fx->data!=0) i++;
		fx=fx->next;
	}
	return i;
}

int main(){
	Polynom *px=NULL,*qx=NULL, *fx=NULL;
	int n,a;
	char com[6];

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		px=insertTail(px, a);
	}
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		qx=insertTail(qx, a);
	}

	scanf("%s", &com);

	/*printList(px);
	printf("\n");
	printList(qx);
	printf("\n");*/
	
	
	if(strcmp(com, "plus")==0) fx=SumTwoPol(px,qx);
	if(strcmp(com, "minus")==0) fx=MinusTwoPol(px,qx);
	
	printf("%d ", count(fx));
	printList(Reverse(fx));

	return 0;
}