#include <bits/stdc++.h>
using namespace std;

void f(string &pattern, vector<int> &temp, vector<int> &fr, int i){
    if(i==pattern.size()){
        return;
    }

    if(i==-1){
        for(int j=1; j<=pattern.size()+1; j++){
            temp.push_back(j);
            f(pattern, temp, fr, i+1);
            if(temp.size()==pattern.size()+1){
                break;
            }
            temp.pop_back();
        }
    } else{
        if(pattern[i]=='I'){
            for(int j=temp[i]+1; j<=pattern.size()+1; j++){
                if(!fr[j]){
                    temp.push_back(j);
                    fr[j]++;
                    f(pattern,temp,fr,i+1);
                    if(temp.size()==pattern.size()+1){
                        break;
                    }
                    fr[j]--;
                    temp.pop_back();
                }
            }
        } else{
            for(int j=temp[i]-1; j>=1; j--){
                if(!fr[j]){
                    temp.push_back(j);
                    fr[j]++;
                    f(pattern,temp,fr,i+1);
                    if(temp.size()==pattern.size()+1){
                        break;
                    }
                    fr[j]--;
                    temp.pop_back();
                }
            }
        }
    }

    return;
}
string smallestNumber(string pattern) {
    vector<int> temp, fr(10,0);
    f(pattern,temp,fr,-1);
    string s="";
    for(int x:temp){
        s += ('0'+x);
    }

    return s;
}

int main(){
    cout<<smallestNumber("DDD")<<endl;
}