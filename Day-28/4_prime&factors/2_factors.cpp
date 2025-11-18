#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

vi trialDivision(int n){
    vi factors;
    for(int i=1; i<=n; i++){  // if we iterate i till root n because if there exists a root < rootn, then other exists > rootn
                              // and can be added by n/i;
        if(n%i==0){
            factors.push_back(i);
        }
    }
    return factors;
}

vi trialDivisionOptimized(int n){
    vi factors;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            factors.push_back(i);
            if(i*i!=n) factors.push_back(n/i);
        }
    }
    return factors;
}

int main(){
    int n; cin>>n;
    vi factors = trialDivision(n);
    for(auto x:factors){
        cout<<x<<' ';
    }
    cout<<endl;
    factors = trialDivisionOptimized(n);
    sort(factors.begin(), factors.end());
    for(auto x:factors){
        cout<<x<<' ';
    }
}