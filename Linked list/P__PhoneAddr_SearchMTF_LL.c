#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char tel[20];
    char email[32];
} phoneAddr_t;

typedef struct node_s {
  phoneAddr_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(const phoneAddr_t data);

void showData(phoneAddr_t data) { 
    printf("%s ", data.name); 
    printf("%s ", data.tel); 
    printf("%s\n", data.email); 
}

// Create a new Node
// return:
//  - on SUCCESS: return a pointer to new Node
//  - on FAIL   : return a NULL pointer


node_t* createNewNode(const phoneAddr_t data) {
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

root_t llInit() { return NULL; }

/* === Insert ============================================== */

root_t llInsertHead(root_t root, const phoneAddr_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const phoneAddr_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

root_t llInsertAfter(root_t root, node_t* pAElem, const phoneAddr_t data) {
  if (pAElem == NULL) return root;

  node_t* pNewNode = createNewNode(data);
  pNewNode->next = pAElem->next;
  pAElem->next = pNewNode;

  return root;
}

/* === Delete ============================================== */

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

node_t* llSearchName(root_t root, const char a[]) {
  for (node_t* p = root; p != NULL; p = p->next) if(strcmp(p->data.name,a)==0) return p;
  return NULL;
}

int llSearchKey(root_t root, const char a[]) {
    int i=0;
    for (node_t* p = root; p != NULL; p = p->next){
        if(strcmp(p->data.name,a)==0){
            printf("%d ", i);
            showData(p->data);
            return 0;
        } 
        i++;
    } 
    printf("Not found\n");
}

root_t MovetoFront(root_t root, node_t* target){
  if(root == target) return root;
  if(target == NULL) return root;
    root_t tmp;
    for (node_t* p = root; p != NULL; p = p->next){
        if(p->next==target){
            tmp=p->next;
            p->next=p->next->next;
        }
    } 
    tmp->next=root;
    return tmp;
}

int main() { 
    char key[20];
    phoneAddr_t data;
    node_t *p;
    root_t root = llInit();

    for (int i = 0;; i++) {
        scanf("%s",&data.name);
        if(strcmp(data.name, "#")==0) break;
        scanf("%s %s",&data.tel, &data.email);
        root = llInsertHead(root, data);
    }

    scanf("%s", &key);

    llSearchKey(root, key);

    root=MovetoFront(root, llSearchName(root, key));
    llPrint(root);
    llDeleteAll(root);
}