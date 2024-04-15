#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char time[9];
    char plate[15];
} data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(data_t data) { printf("%s\n", data.plate); }

node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

root_t llPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next){
    showData(p->data);
  }
  return root;
}

node_t* llSeek1(root_t root, char plate[]) {
  for (node_t* p = root; p != NULL; p = p->next) if(strcmp(p->data.plate, plate)) return p;
  return NULL;
}

node_t* llSeekBefore(root_t root, root_t a) {
  for (node_t* p = root; p != NULL; p = p->next) if(p->next==a) return p;
  return NULL;
}

int llSeekdata(root_t root, char plate[]) {
  for (node_t* p = root; p != NULL; p = p->next) if(strcmp(p->data.plate, plate)==0) return 1;
  return 0;
}

root_t llInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
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

int cnt_bicycle(root_t root){
    int cnt=0;
    for (node_t* p = root; p != NULL; p = p->next) if(p->data.plate[0]=='x') cnt++;
    return cnt;
}

int main() { 
    
  data_t data;
  node_t *p;
  root_t root = NULL, out = NULL, output = NULL;
    char com[15]={'\0'};

  for (int i = 0;; i++) {
    scanf("%s",&data.time);
    if(data.time[0]== '*') break;
    scanf("%s",&data.plate);
    root = llInsertTail(root, data);
  }

  while(scanf("%s", com) && strcmp(com, "***") != 0){

    if(strcmp(com, "list")==0){
      llPrint(root);
    }

    else if(strcmp(com, "find")==0){
        char plate[15];
        scanf("%s",&plate);
        if(llSeekdata(root, plate)==1){
            printf("%s", plate);
        } 
        else {
            printf("-1\n");
        }
    }

    else if(strcmp(com, "in")==0){
      scanf("%s %s", &data.time, &data.plate);
      if(llSeekdata(root, data.plate)==0){
        root = llInsertTail(root, data);
        printf("1\n");
      } 
      else{
        printf("0\n");
      }
    }

    else if(strcmp(com, "out")==0){
      scanf("%s %s", &data.time, &data.plate);
      if(llSeekdata(root, data.plate)==1){
        p = llSeekBefore(root, llSeek1(root, data.plate));
        out = llInsertTail(out, data);
        root = llDeleteAfter(root, p);
        printf("1\n");
      } 
      else{
        printf("0\n");
      }
    }

    else if(strcmp(com, "cnt-bicycle")==0){
        printf("%d\n", cnt_bicycle(root));
    }

    else if(strcmp(com, "has-checkout")==0){
        char plate[13];
        scanf("%s", &plate);
        if(llSeekdata(root, plate)==1 && llSeekdata(out, plate)==1) printf("0");
        else{
            printf("-1\n");
        }
    }
  }
    
  llDeleteAll(root);
  llDeleteAll(out);
}