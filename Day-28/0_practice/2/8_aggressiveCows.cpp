#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>

bool check(vi &f, int m, int x){
    int c = f[0]; // cow already placed at the first place so x-1 more cows need to be placed
    x--;
    for(int i=1; i<f.size(); i++){
        if(f[i]-c>=m){
            x--;
            c = f[i];
        }
        if(x==0) return true;
    }
    return false;
}

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n, c; cin>>n>>c;
        vi f(n);
        for(int i=0; i<n; i++){
            cin>>f[i];
        }
        sort(f.begin(),f.end());
        int l = 0, r = f[n-1] - f[0];
        while(l<=r){
            int m = (r-l)/2 + l;
            if(check(f,m,c)) l = m+1;
            else r = m-1;
        }
        cout<<r<<endl;
    }
}