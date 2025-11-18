// https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int m = (l + r) / 2;
            // Ensure m is even so we always check pairs (m, m+1)
            if (m % 2 == 1) m--;

            if (nums[m] == nums[m + 1])
                l = m + 2;  // single element is to the right
            else
                r = m;      // single element is to the left or at m
        }

        return nums[l];
    }
};