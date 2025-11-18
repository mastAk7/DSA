#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        int n; cin>>n;
        int k; cin>>k;
        vector<int> f(k+1);
        for(int i=0; i<n; i++){
            int x; cin>>x;
            if(x<=k) f[x]++;
        }
        int a = 0;
        for(int i=0; i<k; i++){
            if(f[i]==0) a++;
        }
        cout<<max(a,f[k])<<endl;
    }
}