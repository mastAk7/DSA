#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

    node(){
        this->val = 0;
        this->next = nullptr;
    }
    node(int val){
        this->val = val;
        this->next = nullptr;
    }
    node(int val, node* next){
        this->val = val;
        this->next = next;
    }
};

node* insertAtHead(node* head, int val){
    node* temp = new node(val,head);
    head = temp;
    return head;
}

void insertAtPos(node* head, int val, int pos){
    node* temp = head;
    while(pos>1){
        temp = temp -> next;
        pos--;
    }
    node* cur = new node(val,temp->next);
    temp -> next = cur;
    return;
}

void insertAtTail(node* head, int val){
    node* temp = head;
    while(temp->next){
        temp = temp -> next;
    }
    node* cur = new node(val);
    temp -> next = cur;
    return;
}

void printLL(node* head){
    while(head){
        cout<<head -> val<<' ';
        head = head -> next;
    }
    return;
}

int main(){
    node* head = new node(5);
    head = new node(4,head);
    head = new node(3,head);
    head = new node(2,head);
    head = new node(1,head);

    head = insertAtHead(head,0);
    insertAtPos(head,6,3);
    insertAtTail(head,7);

    printLL(head);
}