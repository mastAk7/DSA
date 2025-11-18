#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        string s; cin>>s;
        int c=0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]==s[i+1]) {c++; break;}
        }
        if(c) cout<<1<<endl;
        else cout<<s.length()<<endl;
    }
}