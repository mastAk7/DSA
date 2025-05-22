#include <bits/stdc++.h>
using namespace std;

void f0(vector<string> &temp, vector<int> &r, int n){
    for(int i=0; i<n; i++){
        string s="";
        for(int j=0; j<n; j++){
            if(j+1 == r[i]){
                s+='Q';
            } else{
                s+='.';
            }
        }
        temp.push_back(s);
    }
    return;
}
void f(vector<vector<string>> &ans, vector<int> &r, vector<int> &c, vector<int> &d1, vector<int> &d2, int n, int i){
    if(i==n){
        vector<string> temp;
        f0(temp,r,n);
        ans.push_back(temp);
        return;
    }
    for(int j=0; j<n; j++){
        int di1 = i + j;
        int di2 = n + j - i -1;
        if(!d1[di1] && !d2[di2] && !c[j]){
            d1[di1]++;
            d2[di2]++;
            c[j]++;
            r.push_back(j+1);
            f(ans,r,c,d1,d2,n,i+1);
            d1[di1]--;
            d2[di2]--;
            c[j]--;
            r.pop_back();
        }
    }
    return;
}
vector<vector<string>> solveNQueens(int n) {
    vector<int> r, c(n,0), d1(n*2+1,0), d2(n*2+1,0);
    vector<vector<string>> ans;
    f(ans,r,c,d1,d2,n,0);
    return ans;
}

int main(){
    vector<vector<string>> ans = solveNQueens(4);
    for(auto &x:ans){
        for(auto y:x){
            cout<<y<<endl;
        }
        cout<<endl;
    }
}