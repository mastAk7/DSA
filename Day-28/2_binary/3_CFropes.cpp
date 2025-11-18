// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B

#include <bits/stdc++.h>
using namespace std;

bool check(double x, int k, const vector<double> &f) {
    long long sum = 0;
    for (auto i : f)
        sum += (long long)(i / x);
    return sum >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> f(n);
    double r = 0;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        r = max(r, f[i]);
    }

    double l = 0, ans = 0;

    for (int i = 0; i < 100; i++) {  // 100 iterations ensure ~1e-6 precision
        double m = (l + r) / 2.0;
        if (check(m, k, f)) {
            ans = m;
            l = m;
        } else {
            r = m;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
}
