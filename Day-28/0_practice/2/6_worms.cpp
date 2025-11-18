// https://codeforces.com/contest/474/problem/B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define mi map<int,int>
#define l(n) for(int i=0; i<n; i++)

int32_t main(){
    int n; cin>>n;
    vi f(n), p(n);
    l(n){
        cin>>f[i];
        if(i==0) p[i] = f[i];
        else p[i] = f[i] + p[i-1];
    }
    int m; cin>>m;
    while(m--){
        int q; cin>>q;
        int l = 0, r = n-1, ans;
        while(l<=r){
            int mid = (r-l)/2 + l;
            if(p[mid]>=q){
                ans = mid + 1;
                r = mid - 1;
            } else l = mid + 1;
        }
        cout<<ans<<endl;
    }
}