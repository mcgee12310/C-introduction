#include<stdio.h>
#include <string.h>

#define MAX_ELEMENT 5

typedef struct {
  char name[20];
  char tel[20], email[32];
} phoneAddr_t;
// todo: viết hàm search để tìm kiếm theo name, trả về chỉ số, -1 nếu không thấy

void MovetoFront(phoneAddr_t a[], int i){
    phoneAddr_t tmp;
    tmp = a[i];
    for(int j=i; j>=0; j--){
      a[j]=a[j-1];
    }
    a[0]=tmp;
}

int search(phoneAddr_t a[], int n, char key[]){
  for(int i=0; i<n; i++){
    if(strcmp(a[i].name,key)==0){
      MovetoFront(a, i);
      return i;
    } 
  }
  return -1;
}

int main() {
  char key[20];

  phoneAddr_t a[MAX_ELEMENT] = { {"A", "1", "1@"},
                                 {"B", "2", "2@"},
                                 {"C", "3", "3@"},
                                 {"D", "4", "4@"},
                                 {"E", "5", "5@"}};

  scanf("%s", &key);                     

  printf("%d", search(a, 5, key));
  /* in các key của mảng a sau khi tìm*/
  return 0;
}