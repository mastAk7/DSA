#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        int n; string s;
        cin>>n>>s;
        vector<int> v(26,0);
        for(char c:s){
            v[c-'a']++;
        }
        bool ans=false;
        for(int i=1; i<n-1; i++){
            if(v[s[i]-'a']>1){
                ans = true;
                break;
            }
        }
        if(ans){
            cout<<"Yes"<<endl;
        } else{
            cout<<"No"<<endl;
        }
    }
}