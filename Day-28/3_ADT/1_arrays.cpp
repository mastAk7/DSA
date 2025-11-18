#include <iostream>
using namespace std;

struct ar{
private:
    int *arr;
    int cap;
    int i;
public:
    ar(int size){
        cap = size;
        arr = new int[cap];
        i = 0;
    }

    void display(){
        cout<<"Array Elements: ";
        for(int j=0; j<i; j++){
            cout<<arr[j]<<' ';
        }
        cout<<endl;
    }

    void insert(int j, int value);
    void remove(int j);
    void search(int value);
    void sort();
};

void ar::insert(int j, int value){
    if(i<0 || j>i){
        cout<<"Invalid index"<<endl;
        return;
    }
    if(i==cap){
        cout<<"Array full"<<endl;
        return;
    }
    for(int x=j; x<i; x++){
        arr[x+1] = arr[x];
    }
    arr[j] = value;
    i++;
    cout<<"Value added : "<<arr[j]<<endl;
    return;
}

void ar::remove(int j){
    if(i<0 || j>=i){
        cout<<"Invalid index"<<endl;
        return;
    }
    for(int x=j; x<i-1; x++){
        arr[x] = arr[x+1];
    }
    i--;
    cout<<"Value removed"<<endl;
    return;
}

void ar::search(int value){
    int l = 0, r = i-1, ans = -1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(arr[m]>value){
            r = m-1;
        } else if(arr[m]<value){
            l = m+1;
        } else{
            ans = m;
            break;
        }
    }
    if(ans==-1){
        cout<<"Element not found"<<endl;
    } else{
        cout<<"Element found at index "<<ans<<endl;
    }
    return;
}

void ar::sort(){
    for(int j = 1; j < i; j++){
        for(int k = 0; k < i - j; k++){
            if(arr[k]>arr[k+1]){
                swap(arr[k],arr[k+1]);
            }
        }
    }
    return;
}

int main(){
    ar temp(10);
    temp.insert(1,1);
    temp.insert(0,5);
    temp.insert(1,4);
    temp.insert(2,3);
    temp.insert(3,2);
    temp.insert(4,1);
    temp.display();
    temp.sort();
    temp.display();
    temp.remove(3);
    temp.display();
    temp.search(4);
    temp.search(3);
}