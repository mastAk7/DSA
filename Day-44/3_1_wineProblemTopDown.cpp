// 2 3 5 1 4
// we can either sell leftmost or rightmost bottle
// profit = price * current day
// day 1: 2 * 1
// day 2: 4 * 2
// day 3: 1 * 3
// day 4: 3 * 4
// day 5: 5 * 5
// total profit = 50

// a small observation:
// the profit is always same for fixed values of l and r
// e.g. l = 1, r = 3: 3 5 1 -> profit would always come out the same using recursion
// and similarly the day can also be calculated using a relation between the two 
// this will be our for top down approach

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

int recur(vi &wine, int l, int r){
    if(l>r) return 0;
    int day = wine.size() - (r-l);
    int opt1 = wine[l-1]*day + recur(wine,l+1,r);
    int opt2 = wine[r-1]*day + recur(wine,l,r-1);
    return max(opt1,opt2);
}

int topDown(vii &dp, vi &wine, int l, int r){
    if(l>r) return dp[l][r]=0;

    if(dp[l][r]!=-1) return dp[l][r];
    int day = wine.size() - (r-l);
    int opt1 = wine[l-1]*day + topDown(dp,wine,l+1,r);
    int opt2 = wine[r-1]*day + topDown(dp,wine,l,r-1);

    return dp[l][r]=max(opt1,opt2);
}

int main(){
    vi wine = {2,3,5,1,4};
    // 2d array because the state depends on two variables
    vii dp(7,vi(7,-1));
    // lets pass 1 based index in l and r
    // hence the indexes can be 1 to 5 in wine
    // and l and r can be min and max 0 and 6
    cout<<recur(wine,1,5)<<endl;
    cout<<topDown(dp,wine,1,5)<<endl;
}