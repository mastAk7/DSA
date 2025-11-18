#include <bits/stdc++.h>
using namespace std;

bool f(){
    int l1,b1,l2,b2,l3,b3;
    cin>>l1>>b1>>l2>>b2>>l3>>b3;

    if(b2==b3 && l2+l3==l1 && l1==b1+b2){
        return true;
    }

    if(l2==l3 && b2+b3==b1 && b1==l1+l2){
        return true;
    }

    if(l1==l2 && l2==l3 && b1+b2+b3==l1){
        return true;
    }

    if(b1==b2 && b2==b3 && l1+l2+l3==b1){
        return true;
    }

    if(b1+b2 == l1+l3){
        if((l1+l3 == l2 && b1==b3) || (b1+b2 == b3 && l1==l2)){
            return true;
        }
    }

    if(b1+b3 == l1+l2){
        if((l1+l2 == l3 && b1==b2) || (b1+b3 == b2 && l1==l3)){
            return true;
        }
    }

    return false;
}

int main(){
    int k; cin>>k;
    while(k--){
        if(f()){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
}