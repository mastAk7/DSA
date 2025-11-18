#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long
#define mi map<int,int>
#define l(n) for(int i=0; i<n; i++)

void f(){
    string s; cin>>s;
    for(int i=0; i<s.size()-1; i++){
        if((s[i]=='*' && (s[i+1]=='*' || s[i+1]=='<')) || (s[i]=='>' && (s[i+1]=='*' || s[i+1]=='<'))){
            cout<<-1<<endl;
            return;
        }
    }
    int a = 0, b = 0, x = 0;
    int i = 0;
    while(i<s.size() && s[i]=='<'){
        a++;
        i++;
    }
    if(s[i]=='*'){
        x++;
        i++;
    }
    while(i<s.size() && s[i]=='>'){
        b++;
        i++;
    }
    cout<<max(a,b)+x<<endl;
    return;
}

int main(){
    int k; cin>>k;
    while(k--){
        f();
    }
}