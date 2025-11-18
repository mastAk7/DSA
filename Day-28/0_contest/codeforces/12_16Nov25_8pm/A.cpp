#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int x = s[n-1];
        int cnt = 0;
        for(auto c:s){
            if(c==x) cnt++;
        }
        cout<<n-cnt<<endl;
    }
}
