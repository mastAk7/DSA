#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, m, p, q;
        cin>>n>>m>>p>>q;

        if(n%p==0){
            if((n/p) * q == m){
                cout<<"YES"<<endl;
            } else{
                cout<<"NO"<<endl;
            }
        } else{
            cout<<"YES"<<endl;
        }
    }
}