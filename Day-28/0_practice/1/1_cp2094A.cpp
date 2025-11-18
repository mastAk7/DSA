#include <bits/stdc++.h>
using namespace std;    

void f(string s){
    int c = 1;
    string ans = "";
    for(auto x:s){
        if(x==' ') c++;
        else{
            if(c){
                ans+=x;
                c--;
            }
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t; cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        f(s);
    }
}