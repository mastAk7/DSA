// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;
        int px = 0;
        mp[0] = 1;
        for(int i=0; i<n; i++){
            px += nums[i];
            ans += mp[px - k];
            mp[px]++;
        }
        return ans;
    }
};