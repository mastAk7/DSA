```cpp
class Solution {
public:
    long long limit = pow(2,31) -1;
    long long mlimit = -pow(2,31);
    int reverse(int x) {
        if(x==mlimit) return 0;
        bool ne = false;
        if(x<0) ne = true;
        x = abs(x);
        long long n = 0;
        while(x){
            n = n*10 + (long long)x%10;
            x/=10;
        }
        if(ne && n<=limit+1) return -n;
        if(!ne && n<=limit) return n;
        return 0;
    }
};
```