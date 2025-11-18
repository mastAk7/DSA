#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long
#define mi map<int,int>
#define l(n) for(int i=0; i<n; i++)

int bitC(int n){
    int c = 0;
    while(n){
        c++;
        n>>=1;
    }
    return c;
}

vi bitD(int n){
    int c = bitC(n);
    int p = pow(2,c-1);
    return {p,n-p};
}

int main(){
    int k; cin>>k;
    while(k--){
        int a, b;
        cin>>a>>b;
        int x = a^b;
        if(a==b) cout<<0<<endl;
        else if(bitC(x)>bitC(a)) cout<<-1<<endl;
        else if(bitC(x)<bitC(a)) cout<<1<<endl<<x<<endl;
        else cout<<2<<endl<<bitD(x)[1]<<' '<<bitD(x)[0]<<endl;
    }
}