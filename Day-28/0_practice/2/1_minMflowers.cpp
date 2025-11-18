// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
class Solution {
    public:
    int check(vi nums, int m, int k, int x){
        int c = 0, temp = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=x){
                temp++;
                if(temp == k){
                    c++;
                    temp = 0;
                }
            }
            else temp = 0;
        }
        return c>=m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int l = 1e9, r = 0;
        for(auto x:nums){
            l = min(x,l);
            r = max(x,r);
        }
        int ans = -1;
        while(l<=r){
            int mid = (r-l)/2 + l;
            if(check(nums,m,k,mid)){
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};