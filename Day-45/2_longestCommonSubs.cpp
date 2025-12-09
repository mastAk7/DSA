// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

#include <bits/stdc++.h>
using namespace std;

// what all we can do?
// example s1 = "abcde", s2 = "ace"
// 1. if the last characters are same, we would check abcd && ac and return ans + 1
// 2. if not, we check abcde && ac and abcd && ace

// basically what we are doing is: we are checking all the pnc
// if the current chars of both texts are equal, we obv check the remaining strings
// else if unequal, we would include the characters one by one and check with the
// remaining strings
 
// example s1 = "abcde", s2 = "ace"
// e = e, we check abcd and ac and add 1
// d!=c, we check abcd & a and abc & ac
// i.  for abcd and a, we would do the same and ans would be 1 only
// ii. abc & ac: c==c -> ab and a left and add 1
//      i. a & a -> 1 
//      i. ab & "" -> 0
// ans would be 3 in this case

// TC would be O(2^n * 2^m) since we are including and excluding all characters in both strings one by one

int lcs(string &s1, string &s2, int n, int m){
    //base case
    if(n==0 || m==0) return 0;
    //recursive case
    if(s1[n-1] == s2[m-1]) return 1 + lcs(s1,s2,n-1,m-1);
    else return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
}

// applying topDown dp -> for a fixed value of n and m, the answer would always be same
int topDown(vector<vector<int>> &dp, string &s1, string &s2, int n, int m){
    if(n==0 || m==0) return dp[n][m] = 0;

    if(dp[n][m]!=-1) return dp[n][m];

    if(s1[n-1] == s2[m-1]) {
        return dp[n][m] = 1 + topDown(dp,s1,s2,n-1,m-1);
    }
    else return dp[n][m] = max(topDown(dp,s1,s2,n-1,m),topDown(dp,s1,s2,n,m-1));
}

// applying bottomUp dp 
// state would be dp[n][m] -> lcs of s1 till size n and s2 till size m
// transition: if(s1[n-1] == s2[m-1]) dp[n][m] = dp[n-1][m-1] + 1;
//             else dp[n][m] = max(dp[n-1][m],dp[n][m-1]);
// base case: dp[n][0] = 0 and dp[0][m] = 0 -> this is because there can be no string with length 0
void bottomUp(vector<vector<int>> &dp, string &s1, string &s2, int n, int m){
    // prefined to zero hence no need of base case
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return;
}

int main() {
    string s1 = "abcdef", s2="abcdfe";
    int n = 6, m = 6;
    cout << lcs(s1,s2,n,m) << endl;
    
    vector<vector<int>> dpTD(n+1,vector<int>(m+1,-1));
    vector<vector<int>> dpBU(n+1,vector<int>(m+1, 0));
    cout << topDown(dpTD,s1,s2,n,m) << endl;
    bottomUp(dpBU,s1,s2,n,m);
    cout<<dpBU[n][m]<<endl;
}