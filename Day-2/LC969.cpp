#include <bits/stdc++.h>
using namespace std;

void f(vector<int>& nums, int n){
    int i=0, j=n;
    while(i<j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}
vector<int> pancakeSort(vector<int>& nums) {
    vector<int> ans;
    for(int i=0; i<nums.size()-1; i++){
        int x = nums.size()-i;
        int j = x-1, in;
        while(j>=0){
            if(nums[j]==x){
                in = j;
                break;
            }
            j--;
        }
        if(in == x-1){
            continue;
        }
        f(nums,in);
        ans.push_back(in+1);
        f(nums,x-1);
        ans.push_back(x);
    }
    return ans;
}

int main(){
    vector<int> v = {3,2,4,1};
    vector<int> ans;
    ans = pancakeSort(v);
    for(int x:ans){
        cout<<x<<' ';
    }
}