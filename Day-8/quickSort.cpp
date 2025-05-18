#include <bits/stdc++.h>
using namespace std;

int f1(vector<int> &arr, int l, int r){
    int i = l-1;
    int j = l;
    int pi = r;
    while(j<pi){
        if(arr[j]>=arr[pi]){
            j++;
        } else{
            i++;
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[i+1],arr[pi]);
    return i+1;
}

void f2(vector<int> &arr, int l, int r){
    if(l>=r){
        return;
    }

    int m = f1(arr,l,r);
    f2(arr,l,m-1);
    f2(arr,m+1,r);
    return;
}

int main(){
    vector<int> arr = {3,5,1,6,2,4};

    f2(arr,0,5);
    for(int i:arr){
        cout<<i<<' ';
    }
}