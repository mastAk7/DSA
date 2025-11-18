#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int i = nums.size()-2;
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    if(i<0){
        int l=0, r=nums.size()-1;
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
    int t; cin>>t;
    while(t--){
        int n, j , k;
        cin>>n>>j>>k;
        vector<int> f1;
        vector<int> f2;
        if(n==12) f1 = f2 = {1,2};
        if(n==123) f1 = f2 = {1,2,3};
        if(n==1234) f1 = f2 = {1,2,3,4};
        for(int i=1; i<j; i++) nextPermutation(f1);
        for(int i=1; i<k; i++) nextPermutation(f2);
        int c = 0;
        for(int i=0; i<f1.size(); i++){
            if(f1[i] == f2[i]) c++;
        }
        cout<<c<<"A"<<f1.size()-c<<"B"<<endl;
    }
}
