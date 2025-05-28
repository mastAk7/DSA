```cpp
class Solution {
  public:
    void f(vector<vector<int>> &maze, vector<vector<int>> &check, vector<string> &ans, string temp, int i, int j){
        if(i<0 || j<0 || i>=maze.size() || j>=maze[0].size() || check[i][j] || !maze[i][j]){
            return;
        }
        if(i==maze.size()-1 && j==maze[0].size()-1){
            ans.push_back(temp);
            return;
        }
        check[i][j]=1;
        temp.push_back('U');
        f(maze,check,ans,temp,i-1,j);
        temp.pop_back();
        temp.push_back('D');
        f(maze,check,ans,temp,i+1,j);
        temp.pop_back();
        temp.push_back('L');
        f(maze,check,ans,temp,i,j-1);
        temp.pop_back();
        temp.push_back('R');
        f(maze,check,ans,temp,i,j+1);
        temp.pop_back();
        check[i][j]=0;
        
        return;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<vector<int>> check(maze.size(), vector<int> (maze[0].size(),0));
        vector<string> ans;
        string temp;
        f(maze,check,ans,temp,0,0);
        return ans;
    }
};
```