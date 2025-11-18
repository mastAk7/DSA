#include <iostream>
using namespace std;

struct stack{
    int cap, top;
    int* arr;

    stack(int size){
        cap = size;
        top = -1;
        arr = new int[size];
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        } else{
            return false;
        }
    }

    bool isFull(){
        if(top == cap-1){
            return true;
        } else{
            return false;
        }
    }

    void push(int x){
        if(!isFull()){
            arr[++top] = x;
            cout<<"Element pushed "<<arr[top]<<endl;
            return;
        }
        cout<<"Stack full"<<endl;
        return;
    }

    void pop(){
        if(!isEmpty()){
            --top;
            cout<<"Element poped"<<endl;
            return;
        }
        cout<<"Stack empty"<<endl;
        return;
    }

    void stop(){
        if(!isEmpty()){
            cout<<"Element at top : "<<arr[top]<<endl;
            return;
        }
        cout<<"Stack empty"<<endl;
        return;
    }
};

int main(){
    stack s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.stop();
    s.pop();
    s.stop();
    s.pop();
    s.stop();
    s.pop();
    s.stop();
    s.pop();
    cout<<s.isEmpty()<<endl;
}