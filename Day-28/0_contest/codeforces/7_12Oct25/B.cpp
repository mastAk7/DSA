#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> f(n);
        for(ll i=0; i<n; i++){
            cin>>f[i];
        }
        vector<ll> ans = {1};
        for(ll i=1; i<n; i++){
            ll dif = f[i] - f[i-1];
            if(dif==i+1){
                ans.push_back(i+1);
            } else{
                ans.push_back(ans[i-dif]);
            }
        }
        for(auto x:ans){
            cout<<x<<' ';
        }
        cout<<endl;
    }
}