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

vi factorize(int n){
    if(n<2) return {};
    vi spf = sieve(n);
    vi fact;
    while(n!=1){
        fact.push_back(spf[n]);
        n/=spf[n];
    }
    return fact;
}

int main(){
    int n; cin>>n;
    vi fact = factorize(n);
    for(auto x:fact){
        cout<<x<<' ';
    }
    cout<<endl;
}