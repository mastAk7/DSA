#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        a--;
        int x = 0;
        if(a!=0){
            if(a%4==0) x = a;
            else if(a%4==1) x = 1;
            else if(a%4==2) x = a+1;
        }
        if(x==b) cout<<a+1<<endl;
        else{
            if((x^b)==a+1) cout<<a+3<<endl;
            else cout<<a+2<<endl;
        }
    }
}