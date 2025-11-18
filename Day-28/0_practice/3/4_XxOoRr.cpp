// https://www.codechef.com/submit/XXOORR
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main(){
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vi bits(32,k-1);
        while(n--){
            int x; cin>>x;
            int c = 0;
            while(x){
                if(x&1) bits[c]++;
                c++;
                x>>=1;
            }
        }
        int ans = 0;
        for(auto x:bits) ans += x/k;
        cout<<ans<<endl;
    }
}