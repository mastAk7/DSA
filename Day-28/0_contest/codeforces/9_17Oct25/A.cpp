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
        int ans = 0;
        l(n){
            int x; cin>>x;
            ans = max(ans,x);
        }
        cout<<ans<<endl;
    }
}