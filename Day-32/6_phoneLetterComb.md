```cpp
class Solution {
public:
    vector<string> s = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void f(string &digits, string &temp, vector<string> &ans, int i=0){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        int curIn = digits[i]-'0';
        for(int j=0; j<s[curIn].size(); j++){
            temp+=s[curIn][j];
            f(digits,temp,ans,i+1);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp = "";
        f(digits,temp,ans);
        return ans;
    }
};
```