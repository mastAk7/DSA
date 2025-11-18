// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

// binary search while checking the numbers less than the mid 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n-1;
        while(l<=r){
            int m = (r-l)/2 + l;
            int c = 0;
            for(auto x:nums) if(x<=m) c++;
            if(c>m)r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};

// we are basically chaning nums[i] to its negative value
// for example 2 is a duplicate 
// on the first encounter with 2, nums[i] would be changed to negative
// on the second encounter with 2 we would find that we have already encountered it
// hence we return it
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])]<0) return abs(nums[i]);
            else nums[abs(nums[i])] *= (-1);
        }
        return 0;
    }
};