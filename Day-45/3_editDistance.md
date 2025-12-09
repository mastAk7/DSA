```cpp
// exactly like longest common subsequence
// if current char of w1 = w2, then no cost of operation and we would directly move to the next characters with no addition cost
// else:
// 1. insertion -> adding the character to w1 hypothetically would make both chars equal but in practical we would only move w2 to next char, w1's current char is yet to be matched
// eg : horse and ros, we are on h and r -> rhorse and ros, move to next element of ros and stay on the same char of horse and add 1 to the cost
// 2. deletion -> deleting the w1 char, we move to the next one on w1 and stay on the same in w2 and add cost by 1
// 3. replace -> bhot char match and we move to the next and add 1

// state : dp[i][j] -> cost of matching i size of w1 and j of w2
// transition : if i-1 == j-1 -> dp[i][j] = dp[i-1][j-1]
//              else -> min of:
//              dp[i-1][j-1] ->replace
//              dp[i][j-1] : for insert, we move i+1, hence we match i length and j-1
//              dp[i-1][j] : for deletion, similar logic 
// base case: if i=0, we need to insert j number of characters
// base case: if j=0, we need to delete i number of characters


class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++) dp[i][0] = i;
        for(int j=1; j<=m; j++) dp[0][j] = j;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) +1;
            }
        }
        return dp[n][m];
    }
};
```