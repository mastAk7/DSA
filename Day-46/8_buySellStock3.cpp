// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// approach we are gonna do is: 
// we would maintain bool variable to check if to sell or to buy
// for every stock we would have the following options:
// 1. if to buy:
    // a. buy : we would store the value and change the bool and next to the next number
    // b. we just move to the next pointer.
// 2. if to sell:
    // a. if possible we sell : return the diff and move to the next iteration
    // b. we just move to the next pointer.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

int recur(vi &f, int k = 4, int c=0, int i=0){
    if(i==f.size() || k==0) return 0;

    int opt1 = 0, opt2 = 0;
    // basic when selling and buying completed, it would be equivalent to highP - lowP
    if(c==0) opt1 = -f[i] + recur(f,k-1,1,i);   
    else opt1 = f[i] + recur(f,k-1,0,i);
    opt2 = recur(f,k,c,i+1); 
    return max(opt1,opt2);
}

// dp[i][k] denotes max profit till k transactions and ith index
    int topDown(vii &dp, vi &f, int k = 4, int c=0, int i=0){
        if(i==f.size() || k==0) return dp[i][k] = 0;

        if(dp[i][k] != -1) return dp[i][k];
        int opt1 = 0, opt2 = 0;
        // basic when selling and buying completed, it would be equivalent to highP - lowP
        if(c==0) opt1 = -f[i] + topDown(dp,f,k-1,1,i);   
        else opt1 = f[i] + topDown(dp,f,k-1,0,i);
        opt2 = topDown(dp,f,k,c,i+1); 
        return dp[i][k] = max(opt1,opt2);
    }

int main(){
    vi f = {7,1,5,3,6,4};
    int n = f.size();
    int k = 4;
    vii dp(n+1, vi(k+1,-1));
    cout<<recur(f)<<endl;
    cout<<topDown(dp,f)<<endl;
    for(auto &x:dp){
        for(auto y:x){
            cout<<y<<' ';
        }
        cout<<endl;
    }
}   