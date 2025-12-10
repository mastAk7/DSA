#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<vi> vii;

// we will iterate from the beginning and we would have two options
// 1. choose the value at the current if possible
// 2. move forward
// in the first case, we would hence look for w - currentWeight in the remaining elements
// in the second case, we would look for the entire w in the remaining elements
// hence we would come across all possible permutations and combinations
int knapsack(vii &f, int w, int i=0){
    if(i==f.size() || w==0) return 0;

    int opt1 = 0, opt2 = 0;
    if(f[i][0]<=w) opt1 = f[i][1] + knapsack(f,w-f[i][0],i+1);
    opt2 = knapsack(f,w,i+1);
    return max(opt1,opt2);
}

int topDown(vii &dp, vii &f, int w, int i=0){
    if(i==f.size() || w==0) return dp[i][w]=0;

    if(dp[i][w] != -1) return dp[i][w];

    int opt1 = 0, opt2 = 0;
    if(f[i][0]<=w) opt1 = f[i][1] + topDown(dp,f,w-f[i][0],i+1);
    opt2 = topDown(dp,f,w,i+1);
    return dp[i][w]=max(opt1,opt2);
}

// state : dp[i][w] -> this represents the max value achieved through max weight w and till index i
// transition:
//          opt1 : choose the current element if possible and the remaining weight through dp[i-1][w-curW]
//          opt2 : leave the current element and hence the value would be till the last element -> dp[i-1][w]
// base case: dp[0][w] = 0 (no element chose), dp[i][0] = 0 (0 weight means no item chose)
void bottomUp(vii &dp, vii &f, int w, int n){
    // already set to 0 hence no need of base case
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(f[i-1][0]<=j) dp[i][j] = f[i-1][1] + dp[i-1][j-f[i-1][0]];
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    return;
}

int32_t main(){
    int n, w; cin>>n>>w;
    vii f(n,vi(2,0));
    for(auto &x:f) cin>>x[0]>>x[1];
    vii dpTD(n+1, vi(w+1,-1));
    vii dpBU(n+1, vi(w+1,0));
    // cout<<topDown(dpTD,f,w)<<endl;
    bottomUp(dpBU,f,w,n);
    cout<<dpBU[n][w]<<endl;
};
