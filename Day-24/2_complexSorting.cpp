#include <bits/stdc++.h>
using namespace std;

bool srtFnc(string &a, string &b){
    if(a.size()==b.size()){          //  if same size, to be sorted in descending order
        return a>b;
    } 
    return a.size()<b.size();        //  else the short first
}

int main(){
    string s[] = {"aryan","mohan","mohak", "ark","arr", "ar","te", "c","d"};

    sort(s, s+sizeof(s)/sizeof(string), srtFnc); // boolean function passed

    for(int i=0; i<sizeof(s)/sizeof(string); i++){
        cout<<s[i]<<endl;
    }
}