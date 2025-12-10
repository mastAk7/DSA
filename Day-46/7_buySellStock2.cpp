// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// approach we are gonna do is: 
// we would maintain bool variable to check if to sell or to buy
// for every stock we would have the following options:
// 1. if to buy:
    // a. buy : we would store the value and change the bool and next to the next number
    // b. we just move to the next pointer.
// 2. if to sell:
    // a. if possible we sell : return the diff and move to the next iteration
    // b. we just move to the next pointer.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

int recur(vi &f, int val=0, int i=0){
    if(i==f.size()) return 0;

    int opt1 = 0, opt2 = 0;
    if(val==0){
        opt1 = recur(f,f[i],i);
    } else{
        if(val<f[i]) opt1 = f[i] - val + recur(f,0,i);
    }
    opt2 = recur(f,val,i+1); 
    return max(opt1,opt2);
}

// not applying dp because it could be solved using greedy

int main(){
    vi f = {7,1,5,3,6,4};
    cout<<recur(f)<<endl;
}   