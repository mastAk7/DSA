- time complexity : n
- space complexity : 1

```cpp
class Solution {
public:
    bool f(int n){
        if(n%2==1){
            return 1;
        }
        return 0;
    }
    bool threeConsecutiveOdds(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }

        int c1 = f(nums[0]), c2 = f(nums[1]), c3 = f(nums[2]);
        if(c1+c2+c3 == 3){
            return true;
        }

        int i=3;
        while(i<nums.size()){
            c1 = c2;
            c2 = c3;
            c3 = f(nums[i]);
            if(c1+c2+c3 == 3){
                return true;
            }
            i++;
        }


        return false;
    }
};
```