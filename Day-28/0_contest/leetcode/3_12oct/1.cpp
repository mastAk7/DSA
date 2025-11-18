#include <bits/stdc++.h>
using namespace std;

int sumDivisibleByK(vector<int> &nums, int k)
{
    vector<int> f(100, 0);
    for (auto x : nums)
    {
        f[x - 1]++;
    }
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        if (f[i] % k == 0)
        {
            sum += f[i] * (i + 1);
        }
    }
    return sum;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    int k = 5;
    cout<<sumDivisibleByK(nums,k);
}