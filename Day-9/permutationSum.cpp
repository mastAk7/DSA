// Given an array of distinct integers candidates and a target integer target, 
// design a algorithm to find all the permutations of candidates that sum up to 
// the target.You may print the permutations in any order. 
 
// The same number may be chosen from candidates an unlimited number of times.

#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp, int t, int i){
    if(i==arr.size() || t==0){
        if(t==0){
            ans.push_back(temp);
        }
        return;
    }

    for(int j=i; j<arr.size();j++){
        swap(arr[i],arr[j]);
        if(t>=arr[i]){
            temp.push_back(arr[i]);
            f(ans,arr,temp,t-arr[i],i);
            temp.pop_back();
        }
        swap(arr[i],arr[j]);
    }

    return; 
}

// 2,3,5,7
// starts from 2 and iterates till 7
// iteration 1 : 
    // temp = 2;
    // 2,3,5,7
    // iteration 1:
        // temp = 2,2
        // 2,3,5,7
        // iteration 1:
            // temp = 2,2,2
            // 2,3,5,7
            // all iterations occur and result not found
        // iteration 2:
            //temp = 2,2,3 ---------------------------------> ans[0];
        // iteration 3 and 4
    
    //iteration 2:
        // temp = 2,3
        // 3,2,5,7
        // iteration 1:
            // temp = 2,3,3
            // 3,2,5,7
            // all iterations occur
            // returns
        // iteration 2:
            // temp = 2,3,2 --------------------------------> ans[1]
            // 2,3,5,7
            // returns (iterations occur but no result obv)

    //iteration 3:
        // temp = 2,5 --------------------------------------> ans[2]
        // 5,3,2,7
        // returns (iterations occur but no result obv)

    //iteration 4

//iteration 2:
    // temp = 3
    // 3,2,5,7
    // .................................................... goes on



int main(){
    vector<int> arr = {2,3,5,7}, temp;
    vector<vector<int>> ans;
    f(ans,arr,temp,7,0);

    for(auto &x:ans){
        for(auto y : x){
            cout<<y<<' ';
        }
        cout<<endl;
    }
}