#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> f(101,0);
        for(auto x:nums){
            f[x]++;
        }
        for(int i = k; i<101; i+=k){
            if(!f[i]){
                return i; 
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> v = {1,4,7,10,15};
    cout<<s.missingMultiple(v, 5);
}