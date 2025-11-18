// https://cses.fi/problemset/task/1620/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define mi map<int,int>
#define l(n) for(int i=0; i<n; i++)

bool check(vi &f, int k, int m){
    int c = 0;
    l(f.size()){
        c += m/f[i];
    }
    return c>=k;
}

int32_t main(){
    int n; cin>>n;
    int k; cin>>k;
    vi f(n);
    int l=1e9, r=0, ans;
    l(n){
        cin>>f[i];
        l = min(l,f[i]);
    }
    r = l*k;
    while(l<=r){
        int m = (r-l)/2 + l;
        if(check(f,k,m)){
            ans = m;
            r = m - 1;
        } else l = m+1; 
    }
    cout<<ans<<endl;
}