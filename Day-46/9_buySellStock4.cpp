// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// bottom Up approach
// state: dp[n][k] -> denotes max profit till index i and k transactions
// transition -> we are gonna take the max of the following:
    // 1. skip -> dp[n][k] = dp[n-1][k]
    // 2. sell if k%2==0 -> dp[n][k] = dp[n][k-1] + f[n];
    // 3. buy if k%2==1 -> dp[n][k] = dp[n][k-1] - f[n]; (we are doing the first tr, then third and so on)
// base case : dp[0][k] = 0, dp[n][0] = 0;
 
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

// the below version fails because of inappropriate base cases
// the second reason is we are selling without actually  buying
// so moving from back to front solves this issue
// we can always buy and not sell but we can never sell and not buy
// int main(){
//     vi f = {7,1,5,3,6,4};
//     int n = f.size();
//     int k = 4;
//     vii dp(n+1, vi(k+1,INT_MIN));
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=k; j++){
//             if(j%2) dp[i][j] = dp[i][j-1] - f[i-1];
//             else dp[i][j] = dp[i][j-1] + f[i-1];
//             dp[i][j] = max(dp[i][j],dp[i-1][j]);
//         }
//     }
//     cout<<dp[n][k]<<endl;
// }   


int main(){
    vi f = {7,1,5,3,6,4};
    int n = f.size();
    int k = 4;
    vi dp(k+1,0);
    for(int i=n-1; i>=0; i--){
        for(int j=k-1; j>=0; j--){
            if(j%2) dp[j] = max(dp[j], dp[j+1]+f[i]);
            else dp[j] = max(dp[j], dp[j+1]-f[i]);
        }
    }
    cout<<dp[0]<<endl;
}   