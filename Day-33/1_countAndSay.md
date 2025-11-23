```cpp
class Solution {
public:
    string f1(int c){
        string s = "";
        while(c){
            s += (char)('0'+c%10);
            c/=10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    void f(string &s){
        int n = s.size();
        string temp;
        for(int i=0; i<n; i++){
            int c = 1;
            while(i<n-1 && s[i]==s[i+1]){
                c++;
                i++;
            }
            temp += f1(c);
            temp += s[i];
        }
        s = temp;
        return;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int i=1; i<n; i++){
            f(s);
        }
        return s;
    }
};
```