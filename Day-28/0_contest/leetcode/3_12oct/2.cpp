#include <bits/stdc++.h>
using namespace std;

bool f(string s, int i, int j){
    vector<int> f(26,0);
    while(j){
        f[s[i]-'a']++;
        i++;
        j--;
    }
    int temp = -1;
    for(auto x:f){
        if(x==0) continue;
        if(temp==-1) temp = x;
        else{
            if(temp!=x) return false;
        }
    }
    return true;
}

int longestBalanced(string s){
    int ans = 1;
    for(int i=0; i<s.length(); i++){
        for(int j=1; j<=s.length()-i; j++){
            if(f(s,i,j)){
                ans = max(ans,j);
            }
        }
    }
    return ans;
}

int main(){
    string s="zzabccy";
    cout<<longestBalanced(s)<<endl;
}