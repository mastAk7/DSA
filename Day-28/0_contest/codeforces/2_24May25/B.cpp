#include <bits/stdc++.h>
using namespace std;

bool f(string &s){
    int i=0, j=s.size()-1;
    while(i<j){
        if(!((s[i]=='(' && s[j]==')') || (s[i]==')' && s[j]=='('))){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        if(f(s)){
            cout<<"NO"<<endl;
        } else{
            cout<<"YES"<<endl;
        }
    }
}