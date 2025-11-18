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
        int n; cin>>n;
        int x; cin>>x;
        int ans = 0;
        if(n==0) cout<<"Case #"<<i+1<<": "<<0<<endl;
        else{
            l(n-1){
                int y; cin>>y;
                ans = max(ans,abs(y-x));
                x = y;
            }
            cout<<"Case #"<<i+1<<": "<<ans<<endl;
        }
    }   
}