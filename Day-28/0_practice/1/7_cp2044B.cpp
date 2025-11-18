#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        string s; cin>>s;
        string ans = s;
        int n = s.length()-1;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='q') ans[n-i]='p';
            else if(s[i]=='p') ans[n-i]='q';
            else ans[n-i]='w';
        }
        cout<<ans<<endl;   
    }
}