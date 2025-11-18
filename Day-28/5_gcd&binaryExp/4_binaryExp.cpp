#include <bits/stdc++.h>
using namespace std;

int pow(int a, int b){
    if(b==0) return 1; // or (b==1) return a; both works
    int halfPow = pow(a, b/2);
    int ans = halfPow*halfPow;
    if(b&1) ans *= a; // when b==1, ans would get a from here
    return ans;
}

int main(){
    cout<<pow(2,4)<<endl;
}