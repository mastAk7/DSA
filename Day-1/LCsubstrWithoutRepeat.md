## Solution 1 
- Time complexity : n
- Space complexity : 1

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128,0);
        int j=0, i=0, ans=0;
        while(i<s.size() && v[s[i]-'\0']==0){
            v[s[i]-'\0']++;
            ans++;
            i++;
        }

        int c = ans;

        while(i<s.size()){
            while(v[s[i]-'\0']!=0){
                v[s[j]-'\0']--;
                c--;
                j++;
            }

            while(i<s.size() && v[s[i]-'\0']==0){
                c++;
                v[s[i]-'\0']++;
                i++;
            }

            ans = max(c,ans);
        }
        return ans;
    }
}; 
```

---

## Solution 2
- Time complexity : n -> (nlogm but m is constant)
- Space complexity : 1

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        map<char,int> v;
        int j=0, i=0, ans=0;
        while(i<s.size() && v[s[i]]==0){
            v[s[i]]++;
            ans++;
            i++;
        }

        int c = ans;

        while(i<s.size()){
            while(v[s[i]]!=0){
                v[s[j]]--;
                c--;
                j++;
            }

            while(i<s.size() && v[s[i]]==0){
                c++;
                v[s[i]]++;
                i++;
            }

            ans = max(c,ans);
        }
        return ans;
    }
};
```