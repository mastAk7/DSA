#include <bits/stdc++.h>
using namespace std;

int power(int a, int b){
    if(b==0) return 1;
    int halfPow = power(a,b/2);
    int ans = halfPow * halfPow;
    if(b%2) ans = ans * a;
    return ans;
}

int main(){
    int n, k; 
    cin>>n>>k;
    int c = 0;
    vector<int> bits;
    while(n){
        if(n&1) c++;
        bits.push_back(n&1);
        n>>=1;
    }
    if(c>k){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=bits.size()-1; i>0; i--){
        if(bits[i]){
            if(c<k){
                if(bits[i]+c<=k){
                    bits[i-1] += (bits[i])*2;
                    c += bits[i];
                    bits[i] = 0;
                } else{
                    bits[i-1] += (k-c)*2;
                    bits[i] -= (k-c);
                    c = k;
                }
            } else break;
        }
    }
    if(c<k){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0; i<bits.size(); i++){
        if(bits[i]){
            int x = pow(2,i);
            while(bits[i]--){
                cout<<x<<' ';
            }
        }
    }
    cout<<endl;
    return 0;
}