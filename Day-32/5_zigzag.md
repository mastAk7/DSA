```cpp
class Solution {
public:
    string convert(string s, int m) {
        int n = s.size();
        if(n==1 || m==1) return s;
        string ans = "";
        for(int i=0; i<n; i+=((m-1)*2)) ans += s[i];
        for(int i=0; i<m-2; i++){
            for(int j=0; j<n; j+=((m-1)*2)){
                int i1 = j + i + 1;
                int i2 = j + (m-1)*2 - i - 1;
                if(i1<n) ans+=s[i1];
                if(i2<n) ans+=s[i2];
            }
        }
        for(int i=m-1; i<n; i+=((m-1)*2)) ans += s[i];
        return ans;
    }
};
```