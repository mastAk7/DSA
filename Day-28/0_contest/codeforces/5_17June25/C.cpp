#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    while(k--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n,vector<int>(m)), temp(n,vector<int>(m));
        vector<int> row(n, 0), col(m, 0);
        int mx = 0;
        
        // Read matrix and find maximum element
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> mat[i][j];
                mx = max(mx, mat[i][j]);
            }
        }
        
        // Count number of maximum elements in each row and column
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == mx){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        // Find cell (i, j) that maximizes (row[i] + col[j])
        int tempR = 0, tempC = 0, tempMax = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                temp[i][j] = row[i] + col[j];
                if(mat[i][j]==mx) temp[i][j]--;
                if(temp[i][j] > tempMax){
                    tempMax = temp[i][j];
                    tempR = i;
                    tempC = j;
                }
            }
        }
        
        // Now decrement elements in the row 'tempR' and column 'tempC'
        for(int i=0; i<m; i++){
            mat[tempR][i]--;
        }
        for(int i=0; i<n; i++){
            if(i == tempR) continue;
            mat[i][tempC]--;
        }
        
        // Find maximum element after decrements
        mx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mx = max(mx, mat[i][j]);
            }
        }

        cout << mx << endl;
    }
}
