// https://codeforces.com/problemset/problem/1421/A

#include <bits/stdc++.h>
using namespace std;

int pow(int a, int b){
    if(b==0) return 1;
    int halfPow = pow(a,b/2);
    int ans = halfPow*halfPow;
    if(b%2) ans *= a;
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        int x=a, y=b;
        int bit = 0;
        int c = 0;
        while(a && b){
            if(a&1 && b&1) c+=pow(2,bit);
            a>>=1;
            b>>=1;
            bit++;
        }
        cout<<((x^c) + (y^c))<<endl;
        // what this is doing is removing all the same bit -> if 1, adding to c and when taken zor, removed
        // if 0, automatically no significance;
        // hence all the uncommon bits are being returned as sum
        // the task done is simply a^b
    }
}