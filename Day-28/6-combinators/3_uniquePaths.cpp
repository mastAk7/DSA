// https://leetcode.com/problems/unique-paths/
#define ll long long
#include <bits/stdc++.h>
using namespace std;

// we can visualize it taking the example m=3 & n=4 (m is down and n is right)
// the path would always have 2 downs and 3 rights regardless the path and decisions 
// DDDRRRR and similarly all the combinations
// _______ 7 blanks -> out all the downs and put all the rights in the remaining boxes
// hence the solution is NCk would be the solution where N = (n-1) + (m-1) -> total spaces
// k is either (n-1) or (m-1) -> same answer in both ways
// now for optimizing, x is min(m,n) -> n in this case
// N * N-1 * .... (m) * (m-1) * ... (n) * (n-1) ... 1 /
// ((n-1) * .. 1) * ((m-1) * ...) -> for minimizing lets removing the (m-1)!

// N * (N-1) * ... (m+1) * (m)
// 1 * (2)   * ... (n-2) * (n-1)

// (N-1+1) * (N-2+1) * ... (N-(n-2)+1) * (N-(n-1)+1)  -> ((n-1) + (m-1) - (n-2) + 1) -> m+1
//    1    *    2    * ...    (n-2)    *    (n-1)

class Solution {
public:
    int uniquePaths(int m, int n) {
        ll N = m + n - 2;
        ll x = min(m,n) - 1;
        ll ans = 1;
        for(ll i = 1; i<=x; i++){
            ans*=(N-i+1);
            ans/=i;
        }
        return ans;
    }
};