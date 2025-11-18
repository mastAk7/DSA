#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        int n; cin>>n;
        vector<int> f(n);
        for(int i=0; i<n; i++){
            cin>>f[i];
        }
        int ans = 0;
        sort(f.begin(),f.end());
        for(int i=0; i<n; i+=2){
            ans = max(f[i+1]-f[i],ans);
        }
        cout<<ans<<endl;
    }
}