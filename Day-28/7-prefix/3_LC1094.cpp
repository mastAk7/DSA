// https://leetcode.com/problems/car-pooling/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int mx = 0;
        for(auto &x:trips){
            mx = max(mx,x[2]);
        }
        vector<int> f(mx+2,0);
        for(auto &x:trips){
            f[x[1]]+=x[0];
            f[x[2]]-=x[0];
        }   
        int ans = f[0];
        for(int i=1; i<mx+2; i++){
            f[i] += f[i-1];
            ans = max(ans,f[i]);
        }
        if(ans>capacity) return false;
        return true;
    }
};