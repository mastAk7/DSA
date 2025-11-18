// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

vi sieve(int n){ // TC = O(n*loglogn)
    vi f(n+1);
    for(int i=0; i<=n; i++) f[i] = i;
    for(int i=2; i*i<=n; i++){
        if(f[i]==i){ // if prime
            for(int j=i*i; j<=n; j+=i){ // iterate on multiples
                if(f[j]==j) f[j] = i; // for example if a number already has a prime factor smaller than j, why disturb it
            }
        }
    }
    return f;  
}

int distinctPrimeFactors(vector<int>& nums) {
    int mx = *max_element(nums.begin(),nums.end());
    vi spf = sieve(mx);
    unordered_set<int> fact;
    for(auto x:nums){
        while(x!=1){
            fact.insert(spf[x]);
            x/=spf[x];
        }
    }
    return fact.size();
}