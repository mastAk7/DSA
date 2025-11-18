#include <iostream>
using namespace std;

struct node{
    int val;
    node* next;

    node(int val){
        this->next = nullptr;
        this->val = val;
    }
    node(int val, node* next){
        this->next = next;
        this->val = val;
    }
};

struct stack{
    node* head = nullptr;

    bool isEmpty(){
        if(head){
            return 0;
        }
        return 1;
    }

    void push(int val){
        node* Node = new node(val);
        Node->next = head;
        head = Node;
    }

    void pop(){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    
    void top(){
        cout<<head->val<<endl;
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.top();
    s.pop();
    s.top();
    s.pop();
    s.top();
    s.pop();
    s.top();
    s.pop();
}