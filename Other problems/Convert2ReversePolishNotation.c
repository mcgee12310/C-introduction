#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(data_t data) { printf("%c ", data); }

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

int main() { 
    char a[1000];
    int s1=0, s2=0;
    data_t data;
    node_t *p;
    root_t root = llInit();

    fgets(a,sizeof(a),stdin);
    // printf("%s", a);
    for(int i=0;; i++){
        if(a[i]=='\n' || a[i]=='\0') break;
        if(a[i]==' ') continue;
        else{
            if(a[i]=='+'){
                if(root==NULL) root=llInsertHead(root, a[i]);
                else if(root->data=='*'){
                    for(int i=0;;i++){
                        if(root==NULL || root->data!='*') break;
                        showData(root->data);
                        root=llDeleteHead(root);
                    }
                    root=llInsertHead(root, a[i]);
                }
                else root=llInsertHead(root, a[i]);
            }
            else if (a[i]=='*'){
                root=llInsertHead(root, a[i]);
            }
            else{
                printf("%c ", a[i]);
            }
        }

    }
    llPrint(root);
    root=llDeleteAll(root);
}