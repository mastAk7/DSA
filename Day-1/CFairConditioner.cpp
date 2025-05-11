#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; cin>>q;
    while(q){
        bool ans = true;
        int n;
        long long m1,m2,t1=0;
        cin>>n>>m1;
        m2 = m1;
        while(n){
            long long t2,l,h;
            cin>>t2>>l>>h;

            long long t = t2-t1;
            m1 = m1 - t;
            m2 = m2 + t;

            if(m1<l){
                m1 = l;
                if(m2>h){
                    m2 = h;
                } else if(m2<l){
                    ans = false;
                }
            } else if(m1>=l && m1<=h){
                if(m2>h){
                    m2 = h;
                }
            } else{
                ans = false;
            }
            t1 = t2;

            n--;
        }


        if(ans){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
        q--;
    }
}