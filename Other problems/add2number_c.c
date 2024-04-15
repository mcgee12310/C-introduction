#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ull unsigned long long

typedef int data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(data_t data) { printf("%d", data); }

node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
// Traversing a list and show
void llPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
}

data_t convert(int n) {
  return n;
}

root_t llInit() { return NULL; }

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

/* === Stack ============================================== */

int top(root_t root){
    return root->data;
}

int main(){
    int count = 0;
    root_t total = llInit(), num1= llInit(), num2= llInit();
    char s1[100000], s2[100000];

    scanf("%s", &s1);
    for(int i=0;; i++){
        if(s1[i]=='n'||s1[i]=='\0') break;
        num1=llInsertHead(num1, convert(s1[i])-'0');
    }
    scanf("%s", &s1);
    for(int i=0;; i++){
        if(s1[i]=='n'||s1[i]=='\0') break;
        num2=llInsertHead(num2, convert(s1[i])-'0');
    }

    while(num1!=NULL && num2!=NULL){
        int sum = top(num1) + top(num2) + count;
        count = sum/10;
        num1=llDeleteHead(num1);
        num2=llDeleteHead(num2);
        total=llInsertHead(total, sum%10);
    }
    while(num1!=NULL){
        int sum = top(num1) + count;
        count/=10;
        num1=llDeleteHead(num1);
        total=llInsertHead(total, sum);
    }
    while(num2!=NULL){
        int sum = top(num2) + count;
        count/=10;
        num2=llDeleteHead(num2);
        total=llInsertHead(total, sum);
    }
    if (count != 0) {
        total=llInsertHead(total, count);
    }

    llPrint(total);
    num1=llDeleteAll(num1);
    num2=llDeleteAll(num2);
    total=llDeleteAll(total);
}