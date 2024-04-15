#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(data_t data) { printf("%d ", data); }

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
  return root;
}

data_t convert(int n) {
  return n;
}

root_t llInit() { return NULL; }

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

/* === Delete ============================================== */

root_t llDeleteHead(root_t root) {
  if (root == NULL) return NULL;

  node_t* p = root->next;
  free(root);
  return (root_t)p;
}

root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

int main() { 

  root_t list1 = llInit();
  root_t list2 = llInit();
  root_t merge = llInit();

  int n;
  char com[6];
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    int a;
    scanf("%d", &a);
    list1 = llInsertTail(list1, a);
  }

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    int a;
    scanf("%d", &a);
    list2 = llInsertTail(list2, a);
  }

  scanf("%s", &com);

  if(strcmp(com, "iSort")==0 && list1->data >= list1->next->data){
    list1 = LLReverse(list1);
  }

  if(strcmp(com, "dSort")==0 && list1->data <= list1->next->data){
    list1 = LLReverse(list1);
  }

  if(strcmp(com, "iSort")==0 && list2->data >= list2->next->data){
    list2 = LLReverse(list2);
  }

  if(strcmp(com, "dSort")==0 && list2->data <= list2->next->data){
    list2 = LLReverse(list2);
  }

  if(strcmp(com, "iSort")==0){
    while(list1 != NULL && list2 != NULL){
      if(list1->data <= list2->data){
        merge = llInsertTail(merge, list1->data);
        list1 = llDeleteHead(list1);
      }
      else{
        merge = llInsertTail(merge, list2->data);
        list2 = llDeleteHead(list2);
      } 
    }
  }
  if(strcmp(com, "dSort")==0){
    while(list1 != NULL && list2 != NULL){
      if(list1->data >= list2->data){
        merge = llInsertTail(merge, list1->data);
        list1 = llDeleteHead(list1);
      }
      else{
        merge = llInsertTail(merge, list2->data);
        list2 = llDeleteHead(list2);
      } 
    }
  }

  llPrint(merge);

  if(list1 != NULL){
    llPrint(list1);
  }

  if(list2 != NULL){
    llPrint(list2);
  }

  list1=llDeleteAll(list1);
  list2=llDeleteAll(list2);
  merge=llDeleteAll(merge);
}