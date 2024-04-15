#include <iostream>
#include<cstdlib>
using namespace std;
//tạo stack
#define ull unsigned long long
struct node{
    ull data;
    struct node *next;
};
typedef struct node node;
node* makeNode(ull data){
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//push thêm vào đầu dslk
void push(node **head,ull data){
    node *newNode = makeNode(data);
    if (*head == NULL) *head = newNode;
    else {
        newNode->next = *head;
        *head = newNode;
    }
}
//xóa node đầu tiên trong dslk
void pop(node **head){
    if (*head == NULL) return;
    node *tmp = *head;
    *head = tmp->next;
    delete tmp;
}
//lấy giá trị phần tử đầu tiên
int top(node *head){ // mặc định là head không null
    return head->data;
}
int empty(node *head){
    return head == NULL;
}
void print(node *head){
    while(head != NULL){
        cout << head->data;
        head = head->next;
    }
}
//đảo ngược danh sách
void reverse(node **head){
    node *prev = NULL, *next = NULL, *cur = *head;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}
int main()
{
    node *head1 = NULL, *head2 = NULL, *head = NULL;
    ull s1, s2; cin >> s1 >> s2;
    while(s1 > 0){
        ull r = s1%10;
        push(&head1,r);
        s1 /= 10;
    }
    reverse(&head1);
    while(s2 > 0){
        ull r = s2%10;
        push(&head2,r);
        s2 /= 10;
    }
    reverse(&head2);

    //thực hiện việc lấy từng phần tử đầu tiên của 2 head1 và head2 ra cộng tương ứng
    ull sum = 0, cnt = 0;
    while(!empty(head1) && !empty(head2)){
        sum = (top(head1) + top(head2) + cnt);
        push(&head, sum%10);
        cnt = sum/10;
        //xóa luôn 2 ptu đầu tiên của mỗi head1 và head2 đó
        pop(&head1); 
       
        pop(&head2);
    }
    //sau khi thoát khỏi vòng lặp thì có thể chỉ có 1 trong 2 head1 hay head2 hết mà thôi
    while (!empty(head1)) {
        sum = (cnt + top(head1));
        push(&head,sum % 10);
        cnt = sum / 10;
        pop(&head1);
    }
    while (!empty(head2)) {
        sum = (cnt + top(head2));
        push(&head,sum % 10);
        cnt = sum / 10;
        pop(&head2);
    }
    if (cnt != 0) {
        push(&head, cnt);
    }
    
    print(head);
    return 0;
}