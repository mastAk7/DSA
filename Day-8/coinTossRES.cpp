// Given N coins, such that each coin has two sides H (heads) and T (tails), 
// design a recursive algorithm to generate all the possible outcomes that we 
// can get upon tossing the N coins simultaneously such that an outcome 
// should not contain consecutive heads. 

#include <bits/stdc++.h>
using namespace std;

void f(int n, string &s){
    if(n==0){
        cout<<s<<endl;
        return;
    }

    if(s.back()!='H'){
        s += 'H';
        f(n-1, s);
        s.pop_back();
    }
    s += 'T';
    f(n-1, s);
    s.pop_back();
    return;
}

int main(){
    int n; cin>>n;
    string s="";
    f(n,s);
}