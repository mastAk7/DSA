// http://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n; cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(3,0));

    // base case by default 0

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + x;
        cin>>x;
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + x;
        cin>>x;
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + x;
    }

    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
}