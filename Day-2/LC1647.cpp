#include <bits/stdc++.h>
using namespace std;

int minDeletions(string s) {
    vector<int> freq(26,0);
    for(char c:s){
        freq[c-'a']++;
    }
    vector<int> track(s.size(),0);
    for(int x:freq){
        if(!x){
            continue;
        }
        track[x-1]++;
    }
    int ans = 0;
    int i=s.size()-1, j = s.size()-1;
    while(i>=0){
        if(track[i]!=1 && track[i]!=0){
            while(track[i]!=1){
                while(j>=0){
                    if(j<i && track[j]==0){
                        break;
                    }
                    j--;
                }
                if(j<0){
                    ans+=i+1;
                } else{
                    ans+=(i-j);
                    track[j]++;
                }
                track[i]--;
            }
        }
        i--;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<minDeletions(s)<<endl;
}