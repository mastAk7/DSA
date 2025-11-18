#include <bits/stdc++.h>
using namespace std;

int power(int a, int b){
    if(b==0) return 1; // or (b==1) return a; both works
    int halfPow = power(a, b/2);
    int ans = halfPow*halfPow;
    if(b&1) ans *= a; // when b==1, ans would get a from here
    return ans;
}

int power(int a, int b, int m){
    if(b==0) return 1;
    if(a>m) a%=m; // during the first recursion call, if a already bigger than m
    int halfPow = power(a, b/2,m) % m;
    int ans = (halfPow%m * halfPow%m) % m;
    if(b&1) ans = (ans * a) % m; 
    return ans;
}

int modInverse(int a, int m){
    return power(a,m-2,m);
}

int main(){

}