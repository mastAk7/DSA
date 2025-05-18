#include <bits/stdc++.h>
using namespace std;

void f(string &s, string &m, long long &c, int &n, int i){
    if(c > pow(2,31)){
        c = pow(2,31);
        return;
    }
    if(i==s.size()){
        return;
    }
    if(s[i]>='0' && s[i]<='9'){
        n=1;
        c = c*10 + (s[i] - '0');
        cout<<c<<endl;
        f(s,m,c,n,i+1);
    } else{
        if(s[i]==' ' && n==0){
            f(s,m,c,n,i+1);
        } else if((s[i]=='-' || s[i]=='+') && n==0){
            n=1;
            if(s[i]=='-'){
                m[0] = '-';
            } else{
                m[0] = '+';
            }
            f(s,m,c,n,i+1);
        } else{
            return;
        }
    }
    return;
}
int myAtoi(string s) {
    long long c = 0;
    int n=0;
    string m = "";
    f(s,m,c,n,0);
    if(m[0] == '-'){
        return -c;
    } else{
        if(c==pow(2,31)){
            return c-1;
        }
    }
    return c;
}

int main(){
    string s = "21474836460";
    cout<<myAtoi(s);
}