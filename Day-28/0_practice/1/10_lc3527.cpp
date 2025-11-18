#include <bits/stdc++.h>
using namespace std;

#define ms map<string,int>

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        ms mp;
        for(auto &x:responses){
            ms temp;
            for(auto y:x){
                if(temp[y]==0){
                    temp[y]++;
                    mp[y]++;
                }
            }
        }
        string ans="";
        for(auto &x:mp){
            if(ans=="") ans = x.first;
            if(x.second>mp[ans]){
                ans = x.first;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<string>> responses = {{"good","ok","good","ok"},{"ok","bad","good","ok","ok"},{"good"},{"bad"}};
    cout<<s.findCommonResponse(responses);
}