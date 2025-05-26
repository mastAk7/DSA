#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int c1=0;
    for(int i=1; i<nums.size(); i++){
        c1 += nums[i];
    }
    if(!c1){
        return 0;
    }
    c1 = 0;
    for(int i=0; i<nums.size()-1; i++){
        c1 += nums[i];
        int c2=0;
        for(int j=i+2; j<nums.size(); j++){
            c2 += nums[j];
        }
        if(c1==c2){
            return i+1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,7,3,6,5,6};
    cout<<pivotIndex(nums)<<endl;
}