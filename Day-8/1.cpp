#include <bits/stdc++.h>
using namespace std;

int smallestIndex(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        int c=0, x=nums[i];
        while(x){
            c = c*10 + x%10;
            x /= 10; 
        }
        if(c==i){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,10,11};
    cout<<smallestIndex(nums);
}