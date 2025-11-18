#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int ans;
        if(a>c){
            if(c<b && c<d){
                ans=1;
            } else{
                ans=0;
            }
        } else{
            if(c<b && c<d){
                ans=1;
            } else if(b>d){
                if(d>a){
                    ans=1;
                } else{
                    ans=0;
                }
            } else{
                if(b>a){
                    ans=1;
                } else{
                    ans=0;
                }
            }
        }
        if(!ans){
            cout<<"Gellyfish"<<endl;
        } else{
            cout<<"Flower"<<endl;
        }
    }
}