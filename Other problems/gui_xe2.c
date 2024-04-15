#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ngay 1954608
#define dem 1997808

int bill_all=0;

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

int timeConvert(char *time){
    int a = time[7] + time[6]*10 + time[4]*60 + time[3]*60*10 + time[1]*60*60 + time[0]*10*60*60;
    return a;
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
    if(root == a) return root;
    for (node_t* p = root; p != NULL; p = p->next) if(p->next==a) return p;
    return NULL;
}

root_t llSeekdata(root_t root, char plate[]) {
  for (node_t* p = root; p != NULL; p = p->next) if(strcmp(p->data.plate, plate)==0) return p;
  return NULL;
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

root_t llDeleteHead(root_t root) {
    node_t* p = root->next;
    free(root);
    return p;
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

int bill(char *plate, char *in, char *out){
    int a = timeConvert(in);
    int b = timeConvert(out);
    if(plate[0]=='x'){
        if(a>=ngay && b<dem) return 1;
        else if ((a<ngay && b<ngay) || (a>=dem && b>=dem)) return 2;
        else if (a>ngay && a<dem && b>=dem) return 3;
        else if (a<ngay && b<dem && b>=ngay) return 3;
        else if (a<ngay && b>=dem) return 5;
    }
    else{
        if(a>=ngay && b<dem) return 3;
        else if ((a<ngay && b<ngay) || (a>=dem && b>=dem)) return 5;
        else if (a>ngay && a<dem && b>=dem) return 8;
        else if (a<ngay && b<dem && b>=ngay) return 8;
        else if (a<ngay && b>=dem) return 13;
    }
}

int cnt_bicycle(root_t root){
    int cnt=0;
    for (node_t* p = root; p != NULL; p = p->next) if(p->data.plate[0]=='x') cnt++;
    return cnt;
}

int cnt_moto(root_t root){
    int cnt=0;
    for (node_t* p = root; p != NULL; p = p->next) if(p->data.plate[0]!='x') cnt++;
    return cnt;
}

int main() { 
    
  data_t data;
  node_t *p;
  root_t root = NULL, out = NULL;
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
        if(llSeekdata(root, plate)!=NULL){
            printf("%s", plate);
        } 
        else {
            printf("-1\n");
        }
    }

    else if(strcmp(com, "in")==0){
      scanf("%s %s", &data.time, &data.plate);
      if(llSeekdata(root, data.plate)==NULL){
        root = llInsertTail(root, data);
        printf("1\n");
      } 
      else{
        printf("0\n");
      }
    }

    else if(strcmp(com, "out")==0){
        scanf("%s %s", &data.time, &data.plate);
        if(llSeekdata(root, data.plate)!=NULL){
            if(root = llSeekdata(root, data.plate)){
                p = root;
                int a = bill(p->data.plate, p->data.time, data.time);
                bill_all += a;
                root = llDeleteHead(root);
                out = llInsertTail(out, data);
                printf("1\n");
            }
            else {
                p = llSeekdata(root, data.plate);
                int a = bill(p->data.plate, p->data.time, data.time);
                bill_all += a;
                p = llSeekBefore(root, llSeekdata(root, data.plate));
                out = llInsertTail(out, data);
                root = llDeleteAfter(root, p);
                printf("1\n");
            }
        } 
        else{
            printf("0\n");
        }
    }

    else if(strcmp(com, "cnt-bicycle")==0){
        printf("%d\n", cnt_bicycle(root));
    }
    else if(strcmp(com, "cnt-moto")==0){
        printf("%d\n", cnt_moto(root));
    }

    else if(strcmp(com, "has-checkout")==0){
        char plate[13];
        scanf("%s", &plate);
        if(llSeekdata(root, plate)!=NULL && llSeekdata(out, plate)!=NULL) printf("0");
        else{
            printf("-1\n");
        }
    }
    else if(strcmp(com, "time")==0){
        char time[9];
        scanf("%s", &time);
        printf("%d\n", timeConvert(time));
    }
    else if(strcmp(com, "bill")==0){
        char plate[13], time[9];
        scanf("%s %s", &time, &plate);
        p = llSeekdata(root, plate);
        if(p!=NULL){
            printf("%d\n", bill(p->data.plate, p->data.time, time));
        }
        else printf("-1");
    }
    else if(strcmp(com, "billall")==0){
        printf("%d\n", bill_all);
    }
  }
    
  llDeleteAll(root);
  llDeleteAll(out);
}
