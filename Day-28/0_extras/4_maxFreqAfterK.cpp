// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main(){
    vi nums = {1,2,3,4,1,2,1,2,3,4,5,6,7,8,9,9,9,8,6,7};
    vi f(10,0);
    for(auto x:nums){
        f[x]++;
    }
    for(auto x:f){
        cout<<x<<" ";
    }
    cout<<endl;
    int k = 2;
    int n = 5;
    vi p(11+k,0);
    for(int i=1; i<10; i++){
        if(i-k<0) p[0] += f[i];
        else p[i-k] += f[i];
        p[i+k+1] -= f[i];
    }
    for(int i=1; i<11+k-1; i++){
        p[i] += p[i-1];
    }
    for(int i=1; i<10; i++){
        p[i] -= f[i];
    }
    int c = 0;
    for(auto x:p){
        cout<<c<<' '<<x<<endl;
    }
}