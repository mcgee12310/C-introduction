#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

struct node{
    char name[256];
    char email[256];
    struct node *leftchild, *rightchild;
};
typedef struct node node;

node* hashArray[SIZE] = {NULL};

int hashCode(char* str){
    int c = 0;
    int n = strlen(str);
    for(int i = 0;i < strlen(str);i++) c = (c*255 + str[i]) % SIZE;
    return c;
}

node *makenode(char *name, char *email){
    node *newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->name, name);
    strcpy(newnode->email, email);
    newnode->leftchild = newnode->rightchild = NULL;
    return newnode;
}

node* insert(node *root, char *name, char *email){
    if(root == NULL) return makenode(name, email);
    int c = strcmp(name, root->name);
    if(c > 0){
        root->rightchild = insert(root->rightchild, name, email);
    }
    else if(c < 0){
        root->leftchild = insert(root->leftchild, name, email);
    }
    return root;
}

node* find(node *root, char *name){
    if(root == NULL) return NULL;
    int c = strcmp(name, root->name);
    if(c == 0){
        return root;
    }
    else if(c < 0){
        return find(root->leftchild, name);
    }
    return find(root->rightchild, name);
}

node *minnode(node *p){
    while(p->leftchild != NULL){
        p = p->leftchild;
    }    
    return p;
}

node* delete(node *root, char *name){
    if(root == NULL) return NULL;
    int c = strcmp(name, root->name);
    if(c < 0){
        root->leftchild = delete(root->leftchild, name);
    }
    else if(c > 0){
        root->rightchild = delete(root->rightchild, name);
    }
    else{
        if(root->leftchild != NULL && root->rightchild != NULL){
            node *tmp = minnode(root->rightchild);
            strcpy(root->name, tmp->name);
            strcpy(root->email, tmp->email);
            root->rightchild = delete(root->rightchild, tmp->name);
        }
        else{
            node *tmp = root;
            if(root->leftchild == NULL) root = root->rightchild;
            else root = root->leftchild;
            free(tmp);
        }
    }
    return root;
}

void freenode(node *root){
    if(root == NULL) return;
    freenode(root->leftchild);
    freenode(root->rightchild);
    free(root);
}

void preorderF(node *root, FILE *f){
    if(root == NULL) return;
    fprintf(f, "%s %s\n", root->name, root->email);
    preorderF(root->leftchild, f);
    preorderF(root->rightchild, f);
}
void preorder(node *root){
    if(root == NULL) return;
    printf("%s, %s\n", root->name, root->email);
    preorder(root->leftchild);
    preorder(root->rightchild);
 }
int main(){
    char cmd[20];
    while(scanf("%s", cmd) && strcmp(cmd, "Quit") != 0){
        if(!strcmp(cmd, "Load")){
            int n; 
            scanf("%d", &n);
            while(n--){
                char name[256], email[256];
                scanf("%s %s", name, email);
                int idx = hashCode(name);
                hashArray[idx] = insert(hashArray[idx], name, email);
            }
        }
        else if(!strcmp(cmd, "Remove")){
            char name[256];
            scanf("%s", name);
            int idx = hashCode(name);
            hashArray[idx] = delete(hashArray[idx], name);
        }
        else if(!strcmp(cmd, "Find")){
            char name[256];
            scanf("%s", name);
            int idx = hashCode(name);
            node *tmp = find(hashArray[idx], name);
            if(tmp != NULL) printf("%d %s\n", idx, tmp->email);
            else printf("Not found\n");
        }
        else if(!strcmp(cmd, "Insert")){
            char name[256], email[256];
            scanf("%s %s", name, email);
            int idx = hashCode(name);
            hashArray[idx] = insert(hashArray[idx], name, email);
        }
        else if(!strcmp(cmd, "Store")){
            char filename[256];
            scanf("%s", filename);
            FILE *f = fopen(filename, "w");
            for(int i = 0;i < SIZE;i++){
                preorderF(hashArray[i], f);
            }
            fclose(f);
        }
        else if(!strcmp(cmd, "Print")){
            for(int i = 0;i < SIZE;i++){
                preorder(hashArray[i]);
            }
        }
    }
    printf("Bye\n");
    return 0;
}

