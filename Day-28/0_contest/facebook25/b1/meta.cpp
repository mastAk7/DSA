#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long
#define mi map<int,int>
#define l(n) for(int i=0; i<n; i++)


int main(){
    int t; cin>>t;
    l(t){
        cout<<"Case #"<<i+1<<": ";
        int n, a, b;
        cin>>n>>a>>b;
        for(int j=1; j<2*n; j++){
            cout<<1<<' ';
        }
        cout<<b<<endl;
    }   
}