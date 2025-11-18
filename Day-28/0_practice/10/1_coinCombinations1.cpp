// https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int32_t main(){
    int n, x; 
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    sort(coins.begin(), coins.end());

    vector<int> dp(x+1,0);
    dp[0] = 1; // base case

    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(i<coins[j]) break;
            dp[i] += dp[i - coins[j]];
            if (dp[i] >= mod) dp[i] -= mod;
        }
    }
    cout<<dp[x]<<endl;
}