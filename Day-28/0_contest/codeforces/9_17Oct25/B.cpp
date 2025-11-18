#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long
#define mi map<int,int>
#define l(n) for(int i=0; i<n; i++)


int main(){
    int k; cin>>k;
    while(k--){
        int n; cin>>n;
        string s; cin>>s;
        int c =  0;
        l(n){
            if((s[i]-'0')==0) c++;
        }
        cout<<c<<endl;
        l(n){
            if((s[i]-'0')==0) cout<<i+1<<' ';
        }
        cout<<endl;
    }
}