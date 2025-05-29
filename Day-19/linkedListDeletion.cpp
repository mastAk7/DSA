#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

    node(){
        this->next = nullptr;
        this->val = 0;
    }
    node(int val){
        this->next = nullptr;
        this->val = val;
    }
    node(int val, node* next){
        this->next = next;
        this->val = val;
    }
};

node* deletionAtHead(node* head){
    node* temp = head->next;
    delete head;
    return temp;
}

void deletionAtPos(node* head, int pos){
    node* temp = head;
    while(pos>1){
        temp = temp->next;
        pos--;
    }
    node* cur = temp->next;
    temp -> next = cur -> next;
    delete cur;
    return;
}

void deletionAtTail(node* head){
    node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    node* cur = temp->next;
    temp -> next = nullptr;
    delete cur;
    return;
}

void printLL(node* head){
    while(head){
        cout<<head->val<<' ';
        head = head -> next;
    }
    return;
}

int main(){
    node * head = new node(5);
    head = new node(4,head);
    head = new node(3,head);
    head = new node(2,head);
    head = new node(1,head);

    head = deletionAtHead(head);
    deletionAtPos(head,1);
    deletionAtTail(head);

    printLL(head);
}