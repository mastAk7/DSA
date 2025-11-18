// https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
using namespace std;

// understanding the issue
// what is the significance of 1e9
// 1 4
// 3
// till i=3 nothing works: 0 1e9 1e9 1e9 1e9
// now i-c[0] = 0 -> dp[i] = 1; : 0 1e9 1e9 1 1e9
// i = 4
// i-c[0] = 1 -> min(1e9, 1+1e9) -> 1e9
// if any smaller number, min(smaller number, actual answer) would cause problems

int main(){
    int n, x; cin>>n>>x;
    vector<int> c(n);
    vector<int> dp(x+1,1e9); // if 1e9, it means that sum cannot be reached
    dp[0] = 0;
    for(int i=0; i<n; i++) cin>>c[i];
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(i-c[j]>=0){
                dp[i] = min(dp[i], dp[i-c[j]]+1);
            }
        }
        // if(mn!=1e9)
        // why not above condition
    }
    if(dp[x]==1e9) cout<<-1<<endl;
    else cout<<dp[x]<<endl;
}