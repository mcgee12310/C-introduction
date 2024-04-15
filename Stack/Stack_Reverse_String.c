#include <stdio.h>
#include <stdlib.h>

//tạo stack
typedef struct node_s {
  char data;
  struct node_s *next;
} node_t, *head_t;

node_t* createNewNode(const char data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

//push thêm vào đầu dslk

head_t push(head_t head, const char data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = head;
  return (head_t)pNewNode;
}

int empty(head_t head){
    if(head == NULL) return 1;
    else return 0;
}

void showData(char data) { printf("%c", data); }

head_t print(head_t head) {
  for (node_t* p = head; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return head;
}

head_t DeleteAll(head_t head) {
  node_t* p = NULL;
  for (; head != NULL; head = p) {
    p = head->next;
    free(head);
  }
  return NULL;
}

int main()
{
    node_t *head = NULL;
    char a[500]={'\0'};
    int n=0;
    for(int i=0;;i++){
        scanf("%c", &a[i]);
        if(a[i]=='\n') break;
        else n++;
    }

    if(a[499]!='\0'&&a[499]!='\n'){
        printf("2");
        return 0;
    }

    if(a[0]=='\n'){
        printf("1");
        return 0;
    }

    for(int i=0; i<n; i++){
        head = push(head,a[i]);
    }
    
    print(head);

    DeleteAll(head);

    return 0;
}