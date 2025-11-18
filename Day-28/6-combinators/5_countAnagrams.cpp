// https://leetcode.com/problems/count-anagrams/-

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

lint solve(string s){
    vector<lint> f(26);
    for(auto c:s){
        f[c-'a']++;
    }
    lint ans = fact[s.size()];
    for(auto i:f){
        if(i>1) ans = (ans%mod * inv_fact[i]%mod)%mod;
    }
    return ans;
}

int main(){
    string s; getline(cin, s);
    factVec(s.size());
    invFactVec(s.size());
    lint ans = 1;
    string temp = "";
    for(lint i=0; i<s.size(); i++){
        if(s[i]==' '){
            if(temp=="") continue;
            ans = (ans%mod * solve(temp)%mod)%mod;
            temp = "";
        } else{
            temp += s[i];
            if(i==s.size()-1){
                ans = (ans%mod * solve(temp)%mod)%mod;
            }
        }
    }
    cout<<ans;
}