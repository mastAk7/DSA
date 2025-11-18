// https://codeforces.com/problemset/problem/1514/B

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int power(int a, int b){
    if(b==0) return 1;
    int halfPow = power(a,b/2)%mod;
    int ans = (halfPow%mod * halfPow%mod)%mod;
    if(b%2) ans = (ans%mod * a%mod)%mod;
    return ans%mod;
}

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        cout<<power(n,k)<<endl;
    }
}

// basically the solution goes like there are n numbers
// each number has k bits
// for the AND to be 0, each of there k bits have to be OFF once in the combined span of n numbers
// example, n = 3 and k = 4 -> bits 0 to 3
// now we can turn off bit 0 in either of the n numbers giving n choices
// similarly all k bits follow the same
// hence power(n,k)