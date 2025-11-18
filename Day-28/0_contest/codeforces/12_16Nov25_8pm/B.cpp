#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int a, b, n;
        cin>>a>>b>>n;
        int x = a/b;
        if(a==b) cout<<1<<endl;
        else if(n>x) cout<<2<<endl;
        else cout<<1<<endl;
    }
}
