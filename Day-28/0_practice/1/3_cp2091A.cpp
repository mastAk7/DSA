#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        map<int,int> m;
        m[0]=3;
        m[1]=1;
        m[2]=2;
        m[3]=1;
        m[5]=1;
        int ans = 0;
        int n; cin>>n;
        for(int i=1; i<=n; i++){
            int x; cin>>x;
            if(m[x]){
                m[x]--;
                if(!m[x]) m.erase(x);
                if(m.empty()) ans = i;
            } else{
                m.erase(x);
            }
        }
        cout<<ans<<endl;
    }
}