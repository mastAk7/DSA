#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> ans;
map<vector<int>,int> grid;
vector<vector<int>> g(9,vector<int>(9,1)), r(9,vector<int>(9,1)), c(9,vector<int>(9,1));

bool check(int i, int j, int x){
    if(r[i][x] && c[j][x] && g[grid[{i,j}]][x]){
        return true;
    }
    return false;
}
void solver(vector<vector<char>> &board, int i, int j){
    if(i==9){
        ans = board;
        return;
    }
    if(j==9){
        solver(board,i+1,0);
        return;
    }
    if(board[i][j]!='.'){
        solver(board,i,j+1);
        return;
    }
    for(int x=0; x<9; x++){
        if(check(i,j,x)){
            board[i][j] = '1' + x;
            r[i][x] = c[j][x] = g[grid[{i,j}]][x] = 0;
            solver(board,i,j+1);
            r[i][x] = c[j][x] = g[grid[{i,j}]][x] = 1;
            board[i][j] = '.';
        }
    }
}
void solveSudoku(vector<vector<char>> &board){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    grid[{k+3*i,l+3*j}] = 3*i + j;
                }
            }
        }
    }
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if((board[i][j])!='.'){
                r[i][board[i][j]-'1']--;
                c[j][board[i][j]-'1']--;
                g[grid[{i,j}]][board[i][j]-'1']--;
            } 
        }
    }  
    solver(board,0,0);
    board = ans;
    return;
}


int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    vector<vector<char>> solved = {
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };

    if(board == solved) cout<<"Done";
    else cout<<"Fail";
    return 0;
}