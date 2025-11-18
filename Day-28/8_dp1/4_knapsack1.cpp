// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, w; 
    cin>>n>>w;
    vector<vector<int>> f(n,vector<int>(2,0));
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=0; i<n; i++) cin>>f[i][0]>>f[i][1];  // f[i][0] -> weight, [1] -> value
 
    // all set to 0 so no need of setting the base case differently

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            int opt1 = 0, opt2 = 0;
            if(j-f[i-1][0]>=0) opt1 = dp[i-1][j-f[i-1][0]] + f[i-1][1];
            // checking if the weight of the current element is <= to the desired sack weight
            // if yes, we go with option 1 and hence add the value of element to prev dp

            opt2 = dp[i-1][j];

            dp[i][j] = max(opt1,opt2);
        }
    }

    cout<<dp[n][w]<<endl;
}