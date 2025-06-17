#include <bits/stdc++.h>
using namespace std;


void f(vector<int>& arr, vector<vector<int>> &ans, int x) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            ans.push_back({x,j});
            j--;
        }
    }
}

int main(){
    int k; cin>>k;
    while(k--){
        vector<vector<int>> ans1;
        vector<vector<int>> ans2;
        vector<vector<int>> ans3;
        int n; cin>>n;
        vector<int> a1(n),b1(n);
        for(int i=0; i<n; i++){
            cin>>a1[i];
        }
        for(int i=0; i<n; i++){
            cin>>b1[i];
        }
        vector<int> a2 = a1, a3 = a1, b2=b1, b3=b1;
        for(int i=0; i<n; i++){
            if(a1[i]>b1[i]){
                swap(a1[i],b1[i]);
                ans1.push_back({3,i+1});
            }
        }
        f(a1,ans1,1);
        f(b1,ans1,2);
        f(a3,ans3,1);
        f(b3,ans3,2);
        for(int i=0; i<n; i++){
            if(a3[i]>b3[i]){
                swap(a3[i],b3[i]);
                ans3.push_back({3,i+1});
            }
        }

        if(ans1.size()>ans3.size()){
            ans1 = ans3;
        }
        cout<<ans1.size()<<endl;

        for(auto &x:ans1){
            for(auto y:x){
                cout<<y<<' ';
            }
            cout<<endl;
        }
    }
}