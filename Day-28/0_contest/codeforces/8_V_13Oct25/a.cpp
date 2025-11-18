#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        int n; cin>>n;
        int a=0, b=0;
        while(n--){
            int x; cin>>x;
            if(x==-1) a++;
            else if(x==0) b++;
        }
        cout<<(a%2)*2+b<<endl;
    }
}