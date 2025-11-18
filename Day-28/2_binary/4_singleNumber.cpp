// https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n==1) return nums[0];
        int l = 0, r = n - 1;
        int ans = -1;

        while (l <= r) {
            int m = (l + r) / 2;

            // Check if nums[m] is unique
            if ((m == 0 && nums[m] != nums[m + 1]) ||
                (m == n - 1 && nums[m] != nums[m - 1]) ||
                (m > 0 && m < n - 1 && nums[m] != nums[m - 1] && nums[m] != nums[m + 1])) {
                ans = nums[m];
                break;
            }

            // Move based on pair alignment (correct logic)
            if ((m % 2 == 1 && nums[m] == nums[m - 1]) ||
                (m % 2 == 0 && nums[m] == nums[m + 1])) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};