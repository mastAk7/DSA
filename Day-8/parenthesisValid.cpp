#include <bits/stdc++.h>
using namespace std;

void f(int n, string &s, int i, int j){
    if(i==n && j==n){
        cout<<s<<endl;
        return;
    }

    if(i<n){
        s += '(';
        f(n,s,i+1,j);
        s.pop_back();
    }
    if(j<n && j<i){
        s += ')';
        f(n,s,i,j+1);
        s.pop_back();
    }

    return;
}

int main(){
    string s; 
    f(2,s,0,0);
}