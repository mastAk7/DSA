// http://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n; cin>>n;
    int k; cin>>k;
    vector<int> f(n), dp(n,1e9);
    for(int i=0; i<n; i++) cin>>f[i];

    dp[0] = 0;

    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            if(i-j>=0){
                dp[i] = min(dp[i],dp[i-j]+abs(f[i]-f[i-j]));
            }
        }
    }

    cout<<dp[n-1];
}