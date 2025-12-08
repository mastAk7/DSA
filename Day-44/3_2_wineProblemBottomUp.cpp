// dp[l][r] denotes the maximum profit through the window l to r
//    r 0 1  2  3  4  5
// l   
// 1    0 10    
// 2    0 0  15   
// 3    0 0  0  25 
// 4    0 0  0  0  5
// 5    0 0  0  0  0  20 
// 6    0 0  0  0  0  0
// the above are all zero because there is no window with l>r

// 2 3 5 1 4
// the same example
// what can be the smallest window? l=r
// and what is the answer to the smallest window? price * (n-r+l)

// the second smallest is l = r-1
// e.g. 2 3 -> how to find the answer?
// considering 2 as day 5 and 3 as 4 or vice versa
// more like wine[r] * day + dp[r-1][l] or wine[l] * day + dp[r][l+1]
// once all 2 windows filled, similarly 3 can be filled and it goes on

// alternative: we can fill it from l = 5 to l = 1 and towards the right in each row
// this is because we only need the below element and the prev element

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

void bottomUp(vii &dp, vi &wine){
    int n = wine.size();
    for(int win = 1; win<=n; win++){ // window will start from 1 day to n days
        for(int l=1; l<=n-win+1; l++){
            int r = l + win - 1;
            int day = n - r + l;
            int opt1 = wine[r-1]*day + dp[l][r-1];
            int opt2 = wine[l-1]*day + dp[l+1][r];
            dp[l][r] = max(opt1,opt2);
        }
    }
}  

int main(){
    vi wine = {2,3,5,1,4};
    vii dp(7,vi(7,0));
    bottomUp(dp,wine);
    cout<<dp[1][5]<<endl;
}