// https://cses.fi/problemset/task/2422
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define mi map<int,int>
#define l(n) for(int i=0; i<n; i++)

int check(int m, int n){
    int c = 0;
    for(int i=1; i<=n; i++){
        c += min(n,m/i);
    }
    return c;
}

int32_t main(){
    int n; cin>>n;
    int l=1, r=n*n, ans;
    while(l<=r){
        int m = (r-l)/2 + l;
        if(check(m,n)>=((n*n)/2+1)) {r = m-1; ans = m;}
        else l = m+1;
    }
    cout<<ans<<endl;
}