#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int z = 0, o = 0;
        for(auto c:s){
            if(c-'0') o++;
            else z++;
        }
        cout<<z*(o+1) + o*(o-1)<<endl;
    }
}