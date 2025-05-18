//Given an array of N integers, design an algorithm to find the Kth smallest element in it.
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

void f2(vector<int> &arr, int l, int r, int k, int &ans){
    if(l>r){
        return;
    }

    int m = f1(arr,l,r);
    if(m==k-1){
        ans = arr[m];
    } else if(k-1<m){
        f2(arr,l,m-1,k,ans);
    } else{
        f2(arr,m+1,r,k,ans);
    }
    return;
}

int main(){
    vector<int> arr = {3,5,1,6,2,4};

    for(int i=1; i<=6; i++){
        int ans;
        f2(arr,0,5,i,ans);
        cout<<ans<<endl;
    }
}