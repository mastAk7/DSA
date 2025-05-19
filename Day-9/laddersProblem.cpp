// Consider a ladder with n steps,  a person is standing at the bottom of the 
// ladder and  wants to reach to its top. Design a recursive algorithm to count 
// the number of ways the person the reach the nth step  i.e.  ladder's top 
// from its bottom such that at each step the person can take a jump of size 
// ranging b/w  one to k steps. 

#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<int>> &ans, vector<int> temp, int n, int k){
    if(n==0){
        if(n==0){
            ans.push_back(temp);
        }
        return;
    }

    for(int j=1 ; j <= k; j++){
        if(j<=n){
            temp.push_back(j);
            f(ans,temp,n-j,k);
            temp.pop_back();
        }
    }
    return;
}

// iteration 1:
    // temp = 1
    // iteration 1:
        // temp = 1,1
        // iteration 1:
            // temp = 1,1,1
            // iteration 1:
                // temp = 1,1,1,1 ----------------> ans[0]
            // iteration 2,3 but no answer
            // returns

        // iteration 2:
            // temp = 1,1,2 ----------------------> ans[1]
        // iteration 3 no answer
        //returns

    // iteration 2:
        // temp = 1,2
        // iteration 1:
            // temp = 1,2,1 ----------------------> ans[2]
        // iteration 2 and 3 but no answer
        // returns
    
    // iteration 3:
        // temp = 1,3 ----------------------------> ans[3]
    
    //returns

// iteration 2 and so on 



int main(){
    int n; int k;
    cin>>n>>k;
    vector<vector<int>> ans;
    vector<int> temp;
    f(ans,temp,n,k);
    for(auto &x:ans){
        for(auto y:x){
            cout<<y<<' ';
        }
        cout<<endl;
    }

}