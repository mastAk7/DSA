#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = (1e9 + 7);
class Solution {
public:
    ll hcf(ll a, ll b){
        if(a==0) return b;
        return hcf(b%a,a);
    }
    ll lcm(ll a, ll b){
        return (a*b)/hcf(a,b);
    }
    ll check(ll a, ll b, ll x){
        return x/a + x/b - x/lcm(a,b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        if(a==b){
            return ( (long long)a*n)%mod;
        }
        ll l = (long long)min(a,b), r = (long long) max(a,b) * n, ans;
        while(l<=r){
            ll m = (r-l)/2 + l;
            if(check(a,b,m)>=n) {r = m-1; ans = m;}
            else l = m+1;
        }
        return ans%mod;
    }
};

int main(){
    ll a = 6, b = 4, n = 3;
    int l = min(a,b), r = max(a,b) * n, ans;
    cout<<ans;
}