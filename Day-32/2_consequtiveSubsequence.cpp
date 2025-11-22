#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>

int main(){
    int n; cin>>n;
    unordered_map<int,int> dp;
    vi f(n,0);
    for(int &x:f){
        cin>>x;
        dp[x] = max(dp[x-1]+1,dp[x]);
    }
    int mx = 1, mi = f[0]; 
    for(auto [x,y]:dp) if(y>mx){
        mx = y;
        mi = x;
    }
    int mn = mi - mx + 1;
    cout<<mx<<endl;
    for(int i=0; i<n; i++){
        if(f[i]==mn){
            cout<<i+1<<' ';
            mn++;
        }
        if(mn>mi) break;
    }
    cout<<endl;
}