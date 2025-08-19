#include <bits/stdc++.h>
using namespace std;


void f1(vector<vector<int>> &maze, vector<string> &ans, string &temp, int i = 0, int j = 0){
    if(i<0 || i==maze.size() || j<0 || j==maze[0].size()){
        return;
    }
    if(maze[i][j]==0 || maze[i][j]==-1){
        return;
    }
    if(i==maze.size()-1 && j==maze[0].size()-1){
        ans.push_back(temp);
        return;
    }
    maze[i][j]=-1;
    temp.push_back('U');
    f1(maze,ans,temp,i-1,j);
    temp.pop_back();
    temp.push_back('D');
    f1(maze,ans,temp,i+1,j);
    temp.pop_back();
    temp.push_back('L');
    f1(maze,ans,temp,i,j-1);
    temp.pop_back();
    temp.push_back('R');
    f1(maze,ans,temp,i,j+1);
    temp.pop_back();
    maze[i][j]=1;
}

vector<string> f(vector<vector<int>> &maze){
    vector<string> ans;
    string temp;
    f1(maze,ans,temp);
    return ans;
}
int main(){
    vector<vector<int>> maze = {{1,1,1,0},{1,1,1,0},{1,0,1,1},{0,0,0,1}};
    vector<string> ans = f(maze);
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}