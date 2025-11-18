// https://cses.fi/problemset/task/1652/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<vector<char>> f(n,vector<char>(n));
    vector<vector<int>> p(n+1,vector<int>(n+1,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>f[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + (f[i-1][j-1]=='*'? 1 : 0);
        }
    }
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<p[c][d]+p[a-1][b-1]-p[a-1][d]-p[c][b-1] <<endl;
    }
}