// https://cses.fi/problemset/task/1637
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n; cin>>n;
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int x = i;
        while(x){
            dp[i] = min(dp[i],dp[i-(x%10)]);
            x/=10;
        }
        dp[i]++;
    }
    cout<<dp[n]<<endl;
}