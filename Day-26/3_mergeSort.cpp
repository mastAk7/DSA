#include <bits/stdc++.h>
using namespace std;

void f1(vector<int> &nums, int l, int r){
    int m = (l+r)/2, n = m+1, i = l;
    vector<int> temp;
    while(l<=m && n<=r){
        if(nums[l]>nums[n]){
            temp.push_back(nums[n]);
            n++;
        } else{
            temp.push_back(nums[l]);
            l++;
        }
    }
    while(l<=m){
        temp.push_back(nums[l]);
        l++;
    }
    while(n<=r){
        temp.push_back(nums[n]);
        n++;
    }
    for(int j=0; j<temp.size(); j++){
        nums[i+j] = temp[j];
    }
    return;
}

void f(vector<int> &nums, int l, int r){
    if(l>=r){
        return;
    }

    int m = (l+r)/2;
    f(nums, l, m);
    f(nums, m+1, r);
    
    f1(nums, l, r);
    return;
}

int main(){
    vector<int> arr = {7,6,5,4,3,2,1};
    f(arr,0,6);
    for(int x:arr){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}