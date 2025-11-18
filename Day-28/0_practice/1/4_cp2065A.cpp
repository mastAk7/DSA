#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        string s; cin>>s;
        cout<<s.substr(0,s.length()-2)+'i'<<endl;
    }
}