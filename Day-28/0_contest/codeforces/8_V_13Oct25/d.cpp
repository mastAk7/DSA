#include <bits/stdc++.h>
using namespace std;

long long f(string s, char a, long long n){
    vector<long long> ff(n,0), fb(n,0), af(n,0), ab(n,0);
    for(long long i=0; i<n; i++){
        if(i==0) ff[i]=(s[i]==a);
        else ff[i] = ff[i-1] + (s[i]==a);
    }
    for(long long i=1; i<n; i++){
        if(s[i]!=a) af[i] = af[i-1] + ff[i-1];
        else af[i] = af[i-1];
    }
    for(long long i=n-1; i>=0; i--){
        if(i==n-1) fb[i]=(s[i]==a);
        else fb[i] = fb[i+1] + (s[i]==a);
    }
    for(long long i=n-2; i>=0; i--){
        if(s[i]!=a) ab[i] = ab[i+1] + fb[i+1];
        else ab[i] = ab[i+1];
    }
    long long ans = (1LL<<62);
    for(long long i=0; i<n; i++){
        if(i==n-1) ans = min(ans,af[i]);
        else ans = min(ans,af[i]+ab[i+1]);
    }
    return ans;
}

int main(){
    long long k; cin>>k;
    while(k--){
        long long n; cin>>n;
        string s; cin>>s;
        cout<<min(f(s,'b',n),f(s,'a',n))<<endl;
    }
}