#include <iostream>
using namespace std;

struct queue{
    int b, f;
    int size;
    int *arr;

    queue(int x){
        arr = new int[x];
        size = x;
        b = 0;
        f = 0;
    }

    bool isEmpty(){
        return b==f; // for circular queue, r==f
    }
    bool isFull(){
        return b==size-1; // for circular queue, (r+1)%size == f
    }
    void enque(int x){
        b++;        // for circular, b = (b+1)%r;
        arr[b] = x;
    }
    void deque(){
        f++;        // for circular, f = (f+1)%r;
    }
    void front(){
        cout<<arr[f+1]<<endl;  // (f+1)%r   
    }
};

int main(){
    queue q(100);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.front();
    q.deque();
    q.front();
    q.deque();
    q.front();
    q.deque();
    q.front();
    q.deque();
    q.front();
    q.deque();
}