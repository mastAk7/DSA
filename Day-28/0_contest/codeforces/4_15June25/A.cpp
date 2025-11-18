#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int k,a,b,x,y;
        cin>>k>>a>>b>>x>>y;
        int c=0;
        if(x>y){
            if(k-b>=0){
                c += (k-b)/y;
                c++;
                k -= c*y;
            }
            if(k-a>=0){
                c += (k-a)/x;
                c++;
            }
        } else{
            if(k-a>=0){
                c += (k-a)/x;
                c++;
                k -= c*x;
            }
            if(k-b>=0){
                c += (k-b)/y;
                c++;
            }
        }
        cout<<c<<endl;
    }
}