#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            v.push_back(x);
        }
 
        int c1 = 0, c2 = 1;
        for(int i=0 ; i<n-1; i++){
            if(v[i]==0){
                c1 = 1;
                if(v[i+1] == 0){
                    c2 = 0;
                }
            }
        }
        if(v[n-1]==0){
            c1=1;
        }
 
        if(c1 && c2){
            cout<<"NO"<<endl;
        } else{
            cout<<"YES"<<endl;
        }
    }
}