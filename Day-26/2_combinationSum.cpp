#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int t, int i=0){
    if(t==0){
        ans.push_back(temp);
        return;
    }
    if(i==nums.size()){
        return;
    }

    if(nums[i]<=t){
        temp.push_back(nums[i]);
        f(ans,temp,nums,t-nums[i],i);
        temp.pop_back();
    }
    f(ans,temp,nums,t,i+1);
    return;
}

vector<vector<int>> combinationSum(vector<int> &nums, int target){
    vector<vector<int>> ans;
    vector<int> temp;
    f(ans, temp, nums, target);
    return ans;
}

int main(){
    vector<int> nums = {2,3,5,7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(nums,target);
    for(auto &x : ans){
        for(auto y:x){
            cout<<y<<' ';
        }
        cout<<endl;
    }
}