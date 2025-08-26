#include <bits/stdc++.h>
using namespace std;

void change(vector<vector<string>> &ans, vector<int> &temp, int n)
{
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        string s(n, '.');
        s[temp[i]] = 'Q';
        arr.push_back(s);
    }

    ans.push_back(arr);

    return;
}

bool check(int i, int j, int n, vector<int> &r, vector<int> &r1, vector<int> &r2)
{
    if (r[i] && r1[i + j] && r2[i - j + n - 1])
    {
        r[i] = r1[i + j] = r2[i - j + n - 1] = 0;
        return true;
    }
    return false;
}

void f(vector<vector<string>> &ans, vector<int> &temp, vector<int> &r, vector<int> &r1, vector<int> &r2, int n, int j = 0)
{
    if (j == n)
    {
        change(ans, temp, n);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (check(i, j, n, r, r1, r2))
        {
            temp.push_back(i);
            f(ans, temp, r, r1, r2, n, j + 1);
            temp.pop_back();
            r[i] = r1[i + j] = r2[i - j + n - 1] = 1;
        }
    }

    return;
}

vector<vector<string>> solveQueens(int n)
{
    vector<int> temp, r(n, 1), r1(n * 2 - 1, 1), r2(n * 2 - 1, 1);
    vector<vector<string>> ans;
    f(ans, temp, r, r1, r2, n);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> ans = solveQueens(n);
    for (auto &x : ans)
    {
        for (auto y : x)
        {
            cout << y << endl;
        }
        cout << endl;
    }
}