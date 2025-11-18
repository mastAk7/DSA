#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> f(101,0);
        while(n--){
            int x; cin>>x;
            f[x]++;
        }
        int ans = 0;
        for(int i=0; i<101; i++){
            if(f[i]==0){
                ans = i;
                break;
            }
        }
        cout<<ans<<endl;
    }
}