#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;

    node(){
        this->next = NULL;
    }

    node(int data){
        this->data = data;
        this->next = NULL;
    }

    node(int data, node* next){
        this->data = data;
        this->next = next;
    }
};

void tranverse(node* head){
    while(head != NULL){
        cout<<head->data<<' ';
        head = head->next;
    }
    cout<<endl;
}

void insertAtBeg(node* &head, int data){
    node* temp = new node(data,head);
    head = temp;
    return;
}

void insertAtEnd(node* head, int data){
    node *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    node *Node = new node(data, nullptr);
    temp->next = Node;
    return;
}

void insertAtIndex(node* head, int data, int i){
    node *temp = head;
    for(int j=0; j<i-1; j++){
        temp = temp->next;
    }
    node *Node = new node(data,temp->next);
    temp->next = Node;
    return;
}

void insertAtNode(node* head, int data){
    node *temp = new node(data,head->next);
    head->next = temp;
    return;
}

void deleteAtBeg(node* &head){
    node* temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtPos(node* head, int pos){
    node *temp = head;
    for(int i=0; i<pos-1; i++){
        temp = temp->next;
    }
    node *del = temp->next;
    temp->next = temp->next->next;
    delete del;
    return;
}

void deleteByVal(node* &head, int val){
    node* temp = head;
    if(head->data == val){
        head = head->next;
        delete temp;
        return;
    }
    while(temp && temp->next){
        if(temp->next->data == val){
            node *del = temp->next;
            temp->next = temp->next->next;
            delete del; 
        }
        temp = temp->next;
    }
    return;
}

int main(){
    node *head = new node(2,nullptr);
    insertAtBeg(head,1);
    insertAtEnd(head,5);
    insertAtIndex(head,4,2);
    insertAtNode(head->next,3);
    tranverse(head);
    deleteByVal(head,3);
    tranverse(head);
    deleteAtPos(head,2);
    tranverse(head);
    deleteAtBeg(head);
    tranverse(head);
    deleteByVal(head,5);
    tranverse(head);
}