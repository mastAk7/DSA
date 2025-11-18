// https://cses.fi/alon/task/1716
#include <bits/stdc++.h>
using namespace std;

#define lint long long
const lint mod = 1e9 + 7;
vector<lint> fact;
vector<lint> inv_fact;

lint power(lint a, lint b, lint m){
    if(b==0) return 1;
    if(a>m) a%=m; // during the first recursion call, if a already bigger than m
    lint halfPow = power(a, b/2,m) % m;
    lint ans = (halfPow%m * halfPow%m) % m;
    if(b&1) ans = (ans * a) % m; 
    return ans;
}

void factVec(lint n){
    fact.resize(n+1);
    fact[0] = fact[1] = 1;
    for(lint i=2; i<=n; i++){
        fact[i] = (fact[i-1]%mod * i%mod)%mod;
    }
    return;
}

void invFactVec(lint n){
    inv_fact.resize(n+1);
    inv_fact[n] = power(fact[n],mod-2,mod);
    for(lint i = n-1; i>=0; i--){
        inv_fact[i] = (inv_fact[i+1]%mod * (i+1)%mod)%mod;
    }
    return;
}

lint nCk(lint n, lint k){
    if (k < 0 || k > n) return 0LL;
    return (fact[n]%mod * inv_fact[n-k]%mod * inv_fact[k]%mod)%mod;
}

lint nPk(lint n, lint k){
    if (k < 0 || k > n) return 0LL;
    return (fact[n]%mod * inv_fact[n-k]%mod)%mod;
}

int main(){
    lint n,k; cin>>n>>k;
    factVec(n+k-1);
    invFactVec(n+k-1);
    cout<<nCk(n+k-1,n-1)<<endl;
}