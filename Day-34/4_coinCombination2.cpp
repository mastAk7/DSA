// https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
const int mod = 1e9+7;

int32_t main(){
    int n, x; 
    cin>>n>>x;

    vi coins(n,0);
    for(int &y:coins) cin>>y; //array of coins

    vii dp(x+1,vi(n+1,0));    // base case
    for(int i=0; i<=n; i++) dp[0][i] = 1;

    for(int i=1; i<=x; i++){
        for(int j=1; j<=n; j++){
            if(coins[j-1]<=i){
                dp[i][j] += (dp[i-coins[j-1]][j])%mod;
            }
            dp[i][j] = (dp[i][j]%mod + dp[i][j-1]%mod)%mod;
        }
    }

    cout<<dp[x][n]<<endl;
}