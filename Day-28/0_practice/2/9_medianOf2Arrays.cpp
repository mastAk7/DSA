#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int lessThanEqualTo(vi &nums, int x){
    int l = 0 , r = nums.size()-1;
    while(l<=r){
        int m = (r-l)/2 + l;
        if(nums[m]<=x) l = m + 1;
        else r = m - 1;
    }
    return r+1; // r is the index of the number slightly smaller or equal to x
    // r + 1 is the number of numbers satisfying the above conditions
}

int noOfEleLessOrEqual(vi &nums1, vi &nums2, int x){
    int l = 0, r = nums1.size();
    
}

int main(){
    vi nums1 = {1,2,4,6,7};
    vi nums2 = {3,5,8};
    int x = (nums1.size() + nums2.size() - 1)/2;
    
}