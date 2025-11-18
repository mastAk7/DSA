#include <bits/stdc++.h>
using namespace std;

void f(){
    int n,m; cin>>n>>m;
    if(n%2==0){
        if(m%2 || m/n==0){
            cout<<"No"<<endl;
            return;
        }
        cout<<"Yes"<<endl;
        for(int i=0; i<n-2; i++){
            cout<<m/n<<' ';
        }
        cout<<(m/n + (m%n)/2)<<' ';
        cout<<(m/n + (m%n)/2)<<' ';
        cout<<endl;
    } else{
        if(m/n==0){
            cout<<"No"<<endl;
            return;
        }
        cout<<"Yes"<<endl;
        for(int i=0; i<n-1; i++){
            cout<<m/n<<' ';
        }
        cout<<(m/n + (m%n))<<' ';
        cout<<endl;
    }
    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        f();
    }
    return 0;
}