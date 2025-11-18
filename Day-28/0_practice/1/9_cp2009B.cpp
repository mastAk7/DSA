#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        int n; cin>>n;
        vector<int> f(n,0);
        for(int i=0; i<n; i++){
            string s; cin>>s;
            for(int j=0; j<4; j++){
                if(s[j]=='#'){f[n-i-1]=j+1; break;}
            }
        }
        for(int i=0; i<n; i++){
            cout<<f[i]<<' ';
        }
        cout<<endl;
    }
}