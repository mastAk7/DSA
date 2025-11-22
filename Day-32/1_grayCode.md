```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> f = {0,1};
        for(int i=1; i<n; i++){
            int p = pow(2,i);
            for(int i=p-1; i>=0; i--){
                f.push_back(f[i]+p);
            }
        }
        return f;
    }
};
```