#include<stdio.h>
#include<malloc.h>

struct Node{      //  1->2->3->4->5 
    int val;
    struct Node* next;
};

void insert(struct Node* head,int val){
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct Node* node = (struct Node*)malloc(sizeof(struct Node*));
    node->val = val;
    temp->next = node;
}

void display(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ->",temp->val);
        temp = temp->next;
    }
}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node*));
    head->val = 1;                                                  // 1->null

    insert(head,2);
    insert(head,3);
    insert(head,4);

    display(head);
    free(head);
}