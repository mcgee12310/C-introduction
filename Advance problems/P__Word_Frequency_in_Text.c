#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node {
    char word[20];
    int count;
    struct Node* left;
    struct Node* right;
} Node_t;
 
Node_t* createNewNode(char* word) {
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
Node_t* insert(Node_t* root, char* word) {
    if (root == NULL) {
        return createNewNode(word);
    }
    int cmp = strcmp(word, root->word);
    if (cmp == 0) {
        root->count++;
    } else if (cmp < 0) {
        root->left = insert(root->left, word);
    } else {
        root->right = insert(root->right, word);
    }
    return root;
}
 
void inorderTraversal(Node_t* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%s %d\n", root->word, root->count);
    inorderTraversal(root->right);
}
int main() {
    char text[1000];
    Node_t* root = NULL;
    while (fgets(text, 1000, stdin) != NULL) {
        char* word = strtok(text, " \n");
        while (word != NULL) {
            root = insert(root, word);
            word = strtok(NULL, " \n");
        }
    }
    inorderTraversal(root);
    return 0;
}