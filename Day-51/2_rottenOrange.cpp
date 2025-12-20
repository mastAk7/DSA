#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> adj = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>> q;
        int ans = 0, fresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        while(!q.empty()){
            for(int i=q.size(); i>0; i--){
                auto [x,y] = q.front();
                for(auto [dx,dy]:adj){
                    int nx = x + dx, ny = y + dy;
                    if(nx<0 || ny<0 || nx==n || ny==m) continue;
                    if(grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                        fresh--;
                    }
                }
                q.pop();
            }
            ans++;
        }
        if(fresh) return -1;
        if(ans==0) return 0;
        return ans-1; //extra level because the end level would be useless
        // since all oranges have been rotten
    }
};