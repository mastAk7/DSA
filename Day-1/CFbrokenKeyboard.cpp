#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t){
        string s; cin>>s;
        vector<int> v(26,0);
        int i=0;
        while(i< (int)s.size()){
            if(s[i]>='a' && s[i]<='z'){
                int c=0;
                int j=i;
                while(j< (int)s.size() && s[i]==s[j]){
                    j++;
                    c++;
                }
                if(c%2!=0){
                    v[s[i]-'a'] = 1;
                }
                i=j;
            } else{
                i++;
            }
        }
        string ans = "";
        for(int i=0; i<26; i++){
            if(v[i]==1){
                ans += 'a' + i;
            }
        }

        cout<<ans<<endl;
        t--;
    }
}