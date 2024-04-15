#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
  char data[50];
  struct node_s *next;
} node_t, *root_t;

void showData(char data[]) { printf("%s", data); }

node_t* createNewNode(char a[]) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  strcpy(newNode->data, a);
  newNode->next = NULL;
  return newNode;
}

root_t llPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
  return root;
}

root_t llInsertTail(root_t root, char data[]) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
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

root_t replace(root_t root, char a[], char b[]) {
    node_t* p = NULL;
    for (p = root; p != NULL; p = p->next){
        if(strcmp(p->data, a)==0) strcpy(p->data, b);
    }
    return root;
}

int main(){ 

    root_t root = NULL;
    char input[1000], a[50]={'\0'}, b[50], c[50];
    int min=0, max;

    fgets(b, sizeof(b), stdin);
    fgets(c, sizeof(c), stdin);
    fgets(input, sizeof(input), stdin);

    for(int i=0; i<50; i++){
        if(b[i]=='\n') b[i]=' ';
        if(c[i]=='\n') c[i]=' ';
    }


    for(int i=0;; i++){
        if(input[i]==' '){
            max=i;
            for(int j=0; min<=max; j++, min++){
                a[j]=input[min];
            }
            min=i+1;
            root = llInsertTail(root, a);
            for(int j=0; j<50; j++) a[j]='\0';
            continue;
        }
        else if(input[i]=='\n' || input[i]=='\0'){
            max=i;
            for(int j=0; min<=max; j++, min++){
                a[j]=input[min];
            }
            min=i+1;
            root = llInsertTail(root, a);
            for(int j=0; j<50; j++) a[j]='\0';
            break;
        }
    }

    root = replace(root, b, c);
    llPrint(root);
}