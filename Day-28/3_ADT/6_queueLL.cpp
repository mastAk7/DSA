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

struct queue{
    node *f = nullptr, *b = nullptr;

    bool isEmpty(){
        return !f;
    }
    void enque(int val){
        node* temp = new node(val);
        if(!f){
            f=b=temp;
        }else{
            b->next = temp;
            b = temp;
        }
        return;
    }
    void deque(){
        if(isEmpty()){
            return;
        }
        node* temp = f;
        f = f->next;
        cout<<temp->val<<endl;
        delete temp;
        return;
    }
};

int main(){
    queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
}
