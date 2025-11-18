// https://cses.fi/alon/task/1715
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int mod = 1e9 + 7;
vector<int> fact;
vector<int> inv_fact;
 
int power(int a, int b, int m){
    if(b==0) return 1;
    if(a>m) a%=m; // during the first recursion call, if a already bigger than m
    int halfPow = power(a, b/2,m) % m;
    int ans = (halfPow%m * halfPow%m) % m;
    if(b&1) ans = (ans * a) % m; 
    return ans;
}
 
void factVec(int n){
    fact.resize(n+1);
    fact[0] = fact[1] = 1;
    for(int i=2; i<=n; i++){
        fact[i] = (fact[i-1]%mod * i%mod)%mod;
    }
    return;
}
 
void invFactVec(int n){
    inv_fact.resize(n+1);
    inv_fact[n] = power(fact[n],mod-2,mod);
    for(int i = n-1; i>=0; i--){
        inv_fact[i] = (inv_fact[i+1]%mod * (i+1)%mod)%mod;
    }
    return;
}
 
int nCk(int n, int k){
    if (k < 0 || k > n) return 0LL;
    return (fact[n]%mod * inv_fact[n-k]%mod * inv_fact[k]%mod)%mod;
}
 
int nPk(int n, int k){
    if (k < 0 || k > n) return 0LL;
    return (fact[n]%mod * inv_fact[n-k]%mod)%mod;
}
 
int32_t main(){
    string s; cin>>s;
    factVec(s.size());
    invFactVec(s.size());
    vector<int> f(26);
    for(auto c:s){
        f[c-'a']++;
    }
    int ans = fact[s.size()];
    for(auto i:f){
        if(i>1) ans = (ans%mod * inv_fact[i]%mod)%mod;
    }
    cout<<ans<<endl;
}