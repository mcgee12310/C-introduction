#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000

typedef struct DataItem {
  char data[20];
  int key;
  struct DataItem *next;
} DataItem;

DataItem* hashArray[SIZE] = {NULL}; 

int hashCode(char* data){
    int c=0;
    int n=strlen(data);
    for(int i=0; i<n; i++){
      c = (c*255 + data[i]) % SIZE;
    }
    return c;
}

DataItem *search(char data[]) {
   //get the hash 
   int hashIndex = hashCode(data);  
   DataItem* p = hashArray[hashIndex];
	
   while(p != NULL) {
      if(strcmp(data, p->data)==0) return hashArray[hashIndex]; 
			
      //go to next cell
      p = p->next;
   }        
	
   return NULL;        
}

void insert(int key,char data[]) {

   DataItem *item = (DataItem*) malloc(sizeof(DataItem));
   strcpy(item->data, data);
   item->key = key;
   item->next = NULL;
   //get the hash 
   int hashIndex = hashCode(data);

   //move in array until an empty or deleted cell
   if(hashArray[hashIndex] != NULL) {
      item->next = hashArray[hashIndex];
      hashArray[hashIndex] = item;
   }
   else hashArray[hashIndex] = item;
}

/*struct DataItem* itemDelete(struct DataItem* item) {
   int key = item->key;

   //get the hash 
   int hashIndex = hashCode(item->data);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}*/

/*void display() {
   int i = 0;
   for(i = 0; i<SIZE; i++) {
      if(hashArray[i] != NULL)
         printf("(%d,%s) ",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~ ");
   }	
}*/

int main() {

  int key=0;
  char data[20];
  char cmd[6];

  while(1){
    scanf("%s", &data);
    if(data[0] == '*') break;
      key = hashCode(data);
      insert(key, data);
   }
  
  while(scanf("%s", &cmd) && cmd[0]!='*'){
    if(strcmp(cmd, "find")==0){
      scanf("%s", &data);
      key=hashCode(data);
      if(search(data)==NULL) printf("0\n");
      else printf("1\n");
    }
    if(strcmp(cmd, "insert")==0){
      scanf("%s", &data);
      key = hashCode(data);
      if(search(data)==NULL){
        insert(key, data);
        printf("1\n");
      } 
      else printf("0\n");
    }
  }

  //display();
}