// https://cses.fi/problemset/task/1638
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
const int mod = 1e9+7;

int32_t main(){
    int n; cin>>n;
    vii grid(n,vi(n,0));
    for(auto &x:grid) for(int &y:x){
        char c; cin>>c;
        if(c=='.') y = 1;
    }
    vi dp(n+1,0);
    dp[1] = grid[0][0];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i-1][j-1]){
                dp[j] = (dp[j-1]%mod + dp[j]%mod)%mod; 
            } else dp[j] = 0;
        }
    }
    cout<<dp[n]<<endl;
}
