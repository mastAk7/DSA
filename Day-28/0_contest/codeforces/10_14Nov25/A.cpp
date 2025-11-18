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
        int n, a; cin>>n>>a;
        int l=0, r=0;
        l(n){
            int x; cin>>x;
            if(x>a) r++;
            else if(x<a) l++;
        }
        if(l>r) cout<<a-1<<endl;
        else cout<<a+1<<endl;
    }
}