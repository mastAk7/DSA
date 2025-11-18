#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int x1 = v[0]%2;
        int x2 = v[v.size()-1]%2;
        int c=1e9;
        int i=0, cnt=0;
        while((v[i]%2)!=x2){
            cnt++;
            i++;
        }
        c=min(cnt,c);
        i=v.size()-1;
        cnt=0;
        while((v[i]%2)!=x1){
            i--;
            cnt++;
        }
        c=min(cnt,c);
        cout<<c<<endl;
    }
}