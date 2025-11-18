#include <bits/stdc++.h>
using namespace std;

bool isPrimeN(int n){ // TC -> n
    if(n<=1) return false;
    for(int i=2; i<n; i++){ // n ki jagah sqrt(n) for TC : sqrt(n)
        if(n%i==0) return false;
    }
    return true;
}

void sieve(int n){ // till and including n
    vector<bool> isPrime(n+1, 1);
    isPrime[0] = isPrime[1] = 0;

    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){ 
                // i*i because for example i=7, 14, 21, ...42 must have been marked by 2,3,.. respectively
                // and hence starting form 7*7 would save iterations
                isPrime[j] = 0;
            }
        }
    }

    for(int i=2; i<=n; i++) if(isPrime[i]) cout<<i<<' ';
    cout<<endl;
}

int main(){
    int n = 50;
    for(int i=2; i<50; i++){
        if(isPrimeN(i)) cout<<i<<' ';
    }
    cout<<endl;
    sieve(n-1);
}