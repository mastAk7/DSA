#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v;
        int tar;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            if(i==0){
                tar = abs(x);
            }
            v.push_back(abs(x));
        }

        int in;
        sort(v.begin(),v.end());

        for(int i=0; i<n; i++){
            if(v[i]==tar){
                in = i;
            }
        }

        int med = (n-1)/2;

        if(n%2==0){
            if(med +1 >= in){
                cout<<"YES"<<endl;
            } else{
                cout<<"NO"<<endl;
            }
        } else{
            if(med >= in){
                cout<<"YES"<<endl;
            } else{
                cout<<"NO"<<endl;
            }
        }
    }
}