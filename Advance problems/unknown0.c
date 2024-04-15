#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int maxCap;
        int currCap;
        struct Node *next;
} Node;

void initStack(Node** arr, int N){
    for(int i = 0; i < N; i++){
        arr[i] = NULL;
    }
}
int stackEmpty(Node** arr, int index){
    return arr[index] == NULL;
}

Node* makeNode(int currCap, int maxCap){
    Node* p = (Node*)malloc(sizeof(Node));
    p->maxCap = maxCap;
    p->currCap = currCap; p->next = NULL;
    return p;
}


void push(int currCap, int maxCap, Node** arr, int index){

    Node* p = makeNode(currCap, maxCap);
    p->next = arr[index]; arr[index] = p;
}

char pop(Node** arr, int index){
    if(stackEmpty(arr, index)) return ' ';
    int x = arr[index]->currCap;
    Node* tmp = arr[index]; arr[index] = arr[index]->next; free(tmp);
    return x;
}

void Sort(int size, Node **arr)
{
    for(int i = 0 ; i < size ; i++)
    {
        for (int j = i + 1 ; j < size ; j++)
        {
            if(arr[i]->maxCap > arr[j]->maxCap)
            {
                Node *tmp;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    Node* arr[N]; //mang gom co N ngan xep
    initStack(arr, N);
    int maxNodes;
    scanf("%d", &maxNodes);
    int maxCaps[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &maxCaps[i]);
        if(i == 0)
        {
            arr[i] = makeNode(maxNodes, maxCaps[i]);
        }
        else
        {
            push(maxNodes, maxCaps[i], arr, i);
        }
    }
    Sort(N, arr);
    /*printf("==============================\n");
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += maxCaps[i];
    }
    printf("%d", sum);*/
    int M;
    scanf("%d", &M);
    int allStuff;
    for(int i = 0; i < M; i++){
        scanf("%d", &allStuff);
        for(int j = 0 ; j < N ; j++)
        {
            if(arr[j]->maxCap >= allStuff)
            {
                if(arr[j]->currCap > 0)
                {
                    arr[j]->currCap--;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < N ; i++)
    {
        if(arr[i]->currCap > 0) ans++;
 //       printf("%c. %d %d\n", i+'A', arr[i]->currCap, arr[i]->maxCap);
    }
    printf("%d", ans);

    return 0;
}