```cpp
class Solution {
public:
    bool check(string &s, int i, int j){
        j += i-1;
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans="";
        for(int i=1; i<=n; i++){
            for(int j=0; j<n-i+1; j++){
                if(check(s,j,i) && ans.size()<i) ans = s.substr(j,i);
            }
        }
        return ans;
    }
};```