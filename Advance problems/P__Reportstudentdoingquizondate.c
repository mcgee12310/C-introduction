#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    int yyyy, mm, dd;
    int cnt;
} data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(data_t data) { 
    printf("%s %d\n", data.date, data.cnt); 
}

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

root_t llInit() { return NULL; }

void swap (node_t *a, node_t *b) {
    data_t tmp;
    tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

root_t AscSort(root_t root){
    root_t i, j, min_idx; 
  
    for (i = root; i->next != NULL; i=i->next) { 
        min_idx = i; 
        for (j = i -> next; j != NULL; j=j->next) {
            if (j->data.yyyy < min_idx->data.yyyy) swap(min_idx, j); 
            else if(j->data.yyyy == min_idx->data.yyyy){
              if(j->data.mm < min_idx->data.mm) swap(min_idx, j); 
              else if(j->data.mm == min_idx->data.mm){
                if(j->data.dd < min_idx->data.dd) swap(min_idx, j); 
              }
            }
        } 
    } 
    return root;
}


/* === Insert ============================================== */

root_t llInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

/* === Delete ============================================== */

root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

int main() { 
    char a[9], b[100], c[100];
    data_t data;
    node_t *p;
    root_t root = llInit();

    for (int i = 0;; i++) {
        int check=0;
        scanf("%s",&data.date);
        if(strcmp(data.date, "*")==0) break;
        scanf("%s %s %s", &a, &b, &c);
        data.yyyy = 1000*(data.date[0]-'0')+100*(data.date[1]-'0')+10*(data.date[2]-'0')+data.date[3]-'0';
        data.mm = 10*(data.date[5]-'0')+data.date[6]-'0';
        data.dd = 10*(data.date[8]-'0')+data.date[9]-'0';
        for(p = root; p!=NULL; p=p->next){
            if(strcmp(data.date, p->data.date)==0){
                check=1;
                p->data.cnt+=1;
                break;
            } 
        }
        if(check == 0){
            data.cnt = 1;
            root = llInsertHead(root, data);
        }
        
    }
    root = AscSort(root);

    llPrint(root);
    root = llDeleteAll(root);
}
