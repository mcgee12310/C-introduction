#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(const data_t data);
data_t convert(int n);


void showData(data_t data) { printf("%d ", data); }

// Create a new Node
// return:
//  - on SUCCESS: return a pointer to new Node
//  - on FAIL   : return a NULL pointer


node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}


// Traversing a list and show
root_t llPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return root;
}

data_t convert(int n) {
  return n;
}

root_t llInit() { return NULL; }

node_t* llSeek(root_t root, int index) {
  node_t* p = NULL;
  for (p = root; index > 0 && (p != NULL); index--) p = p->next;
  return p;
}

node_t* llSeek1(root_t root, data_t a) {
  for (node_t* p = root; p != NULL; p = p->next) if(a==p->data) return p;
  return NULL;
}

node_t* llSeekBefore(root_t root, data_t a) {
  for (node_t* p = root; p != NULL; p = p->next) if(a==p->next->data) return p;
  return NULL;
}

int llSeekdata(root_t root, data_t a) {
  for (node_t* p = root; p != NULL; p = p->next) if(a==p->data) return 1;
  return 0;
}

/* === Insert ============================================== */

root_t llInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

root_t llInsertAfter(root_t root, node_t* pAElem, const data_t data) {
  if (pAElem == NULL) return root;

  node_t* pNewNode = createNewNode(data);
  pNewNode->next = pAElem->next;
  pAElem->next = pNewNode;

  return root;
}

/* === Delete ============================================== */

root_t llDelete(root_t root, data_t a) {
  if (root == NULL) return NULL;

  for (root_t pA = root; pA != NULL; pA = pA->next){
    if (pA->next->data == a){
        node_t* pToDelElem = pA->next;
        pA->next = pA->next->next;

        free(pToDelElem);
        return root;
    } 
    else return root;
  }
}

root_t llDeleteHead(root_t root) {
  if (root == NULL) return NULL;

  node_t* p = root->next;
  free(root);
  return (root_t)p;
}

root_t llDeleteTail(root_t root) {
  if (root == NULL) return NULL;
  if (root->next == NULL) {
    free(root);
    return NULL;
  }

  node_t* p;
  // Find previous node of Tail
  for (p = root; p->next->next != NULL; p = p->next)
    ;

  free(p->next);
  p->next = NULL;
  return (root_t)root;
}

root_t llDeleteAfter(root_t root, node_t* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;

  node_t* pToDelElem = pA->next;
  pA->next = pA->next->next;

  free(pToDelElem);
  return root;
}

root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

/* === Tools ========================================= */
int llLength(root_t root) {
  int count;
  for (count = 0; root != NULL; root = root->next) count++;
  return count;
}

root_t LLReverse(root_t root) {
  node_t *cur, *prev;

  for (cur = prev = NULL; root != NULL;) {
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  return cur;
}

int main() { 
  int a,b;
  data_t data;
  node_t *p;
  root_t root = llInit();
  char com[20]={'\0'};

  scanf("%d",&a);
  for (int i = 0; i < a; i++) {
    scanf("%d",&b);
    root = llInsertTail(root, convert(b));
  }

  do{
    scanf("%s",&com);

    if(strcmp(com, "addlast")==0){
      scanf("%d",&a);
      a=convert(a);
      if(llSeekdata(root, a)==0) root = llInsertTail(root, a);
    }

    else if(strcmp(com, "addfirst")==0){
      scanf("%d",&a);
      a=convert(a);
      if(llSeekdata(root, a)==0) root = llInsertHead(root, a);
    }

    else if(strcmp(com, "addafter")==0){
      scanf("%d %d",&a,&b);
      a=convert(a);
      b=convert(b);
      if(llSeekdata(root, a)==0 && llSeekdata(root, b)==1) root = llInsertAfter(root, llSeek1(root, b), a);
    }

    else if(strcmp(com, "addbefore")==0){
      scanf("%d %d",&a,&b);
      a=convert(a);
      b=convert(b);
      p=llSeekBefore(root, convert(b));
      if(llSeekdata(root, a)==0 && llSeekdata(root, b)==1) root = llInsertAfter(root, p, a);
    }

    else if(strcmp(com, "remove")==0){
      scanf("%d",&a);
      if (llSeek1(root, a)==NULL) continue;
      else if(root->data == convert(a)) root = llDeleteHead(root);
      else {
        p=llSeekBefore(root, convert(a));
        root = llDeleteAfter(root, p);
      }
    }

    else if(strcmp(com, "reverse")==0){
      root=LLReverse(root);
    }

    else continue;

  } while (com[0] != '#');

  llPrint(root);
  llDeleteAll(root);
}