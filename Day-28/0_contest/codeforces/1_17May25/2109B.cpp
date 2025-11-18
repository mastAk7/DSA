#include <bits/stdc++.h>
using namespace std;

int f1(int n, int m, int a, int b){
    n -= max(n-a,a-1);
    
    a = (n+1)/2;
    b = (m+1)/2;
    
    int c=1;
    while(true){
        int x1 = max(n-a, a-1);
        int x2 = max(m-b, b-1);
        if(x1>x2){
            n -= x1;
        } else{
            m -= x2;
        }
    
        a = (n+1)/2;
        b = (m+1)/2;
        c++;
        if(n==1 && m==1){
            break;
        }
    }
    return c;
}

int f3(int n, int m, int a, int b){
    m -= max(m-b,b-1);
    
    a = (n+1)/2;
    b = (m+1)/2;
    
    int c=1;
    while(true){
        int x1 = max(n-a, a-1);
        int x2 = max(m-b, b-1);
        if(x1>x2){
            n -= x1;
        } else{
            m -= x2;
        }
    
        a = (n+1)/2;
        b = (m+1)/2;
        c++;
        if(n==1 && m==1){
            break;
        }
    }
    return c;
}

int f2(int n, int m, int a, int b){
    int c=0;
    while(true){
        int x1 = max(n-a, a-1);
        int x2 = max(m-b, b-1);
        if(x1>x2){
            n -= x1;
        } else{
            m -= x2;
        }
    
        a = (n+1)/2;
        b = (m+1)/2;
        c++;
        if(n==1 && m==1){
            break;
        }
    }
    return c;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m>>a>>b;

        int c = min(f1(n,m,a,b),f2(n,m,a,b));
        c = min(c,f3(n,m,a,b));

        cout<<c<<endl;
    }
}