#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> f(n), ch(n,0), r(n,-1), l(n,-1);
        int mx = *max(f.begin(),f.end());
        for(int i=0; i<n; i++) cin>>f[i];

        for(int j=0; j<(2*n); j++){
            int i = j%n;
            if(r[(i-1+n)%n]==-1){
                if(f[(i-1+n)%n]>f[i]) r[i] = f[(i-1+n)%n];
            } else{
                if(f[(i-1+n)%n]>f[i] && r[(i-1+n)%n]>f[i]) r[i] = min(f[(i-1+n)%n],r[(i-1+n)%n]);
                else if(max(f[(i-1+n)%n],r[(i-1+n)%n])>f[i]) r[i] = max(f[(i-1+n)%n],r[(i-1+n)%n]);
            }
            if(f[(i-1+n)%n] == f[i]) ch[i] = 1;
        }

        int c = 0;
        int c2 = 0;
        for(int i=0; i<n; i++){
            if(f[i]==mx) c2++;
            else{
                if(ch[i] = 1) c += f[i];
                else c+=r[i];
            }
        }
        c+=(c2-1)*mx;
        cout<<c<<endl;
    }
}
