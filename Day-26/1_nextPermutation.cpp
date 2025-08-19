#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &nums){
    int i = nums.size()-2;
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    if(i<0){
        int l=0, r=nums.size();
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
        return;
    }
    int l = i+1, r=nums.size()-1;
    while(nums[i]>=nums[r]){
        r--;
    }
    swap(nums[i],nums[r]);
    r = nums.size()-1;
    while(l<r){
        swap(nums[l],nums[r]);
        l++;
        r--;
    }
    return;
}

int main(){
    vector<int> arr = {};
    f(arr);
    for(int x:arr){
        cout<<x<<' ';
    }
    cout<<endl;
}