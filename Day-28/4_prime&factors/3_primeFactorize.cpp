#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

vi primeFactors(int n){
    vi fact;
    for(int i=2; i<=n; i++){
        while(n%i==0){
            n/=i;
            fact.push_back(i);
        }
    }
    return fact;
}

// the idea to iterate till rootn only
// n can be visualized as i*i or x*y
// now if x<i then y>i
// x would be considered during the iteration
// for y, it can only be a prime number
// if composite, it would be breaker down before always
// y = p*q, if p>i then always would get broken
vi primeFactorsOpt(int n){
    vi fact;
    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            n/=i;
            fact.push_back(i);
        }
    }
    if(!n) fact.push_back(n); // left over prime number greater than i
    return fact;
}

int main(){
    int n; cin>>n;
    vi fact = primeFactors(n);
    for(auto x:fact){
        cout<<x<<' ';
    }
    cout<<endl;
    fact = primeFactors(n);
    for(auto x:fact){
        cout<<x<<' ';
    }
    cout<<endl;
}