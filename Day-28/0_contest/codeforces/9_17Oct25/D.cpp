#include <bits/stdc++.h>
using namespace std;

struct QueryLimiter {
    int used = 0;
    void count() {
        ++used;
    }
    void reset() { used = 0; }
} qlim;

inline void flush_now() {
    cout << endl;
    cout.flush();
}

long long askP(int l, int r) {
    if (l > r) swap(l, r);
    cout << "1 " << l << " " << r;
    flush_now();
    long long x;
    if (!(cin >> x)) exit(0);
    qlim.count();
    return x;
}

long long askA(int l, int r) {
    if (l > r) swap(l, r);
    cout << "2 " << l << " " << r;
    flush_now();
    long long y;
    if (!(cin >> y)) exit(0);
    qlim.count();
    return y;
}

void submit(int l, int r) {
    cout << "! " << l << " " << r;
    flush_now();
}

pair<int,int> solve_case(int n) {
    long long totalP = askP(1, n);
    long long totalA = askA(1, n);
    long long k = totalA - totalP;
    if (k <= 0) {
        return {1, 1};
    }
    int lo = 1, hi = n, lpos = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        long long prefP = askP(1, mid);
        long long prefA = askA(1, mid);
        long long diff = prefA - prefP;
        if (diff > 0) {
            lpos = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    int L = lpos;
    int R = L + (int)k - 1;
    R = min(R, n);
    return {L, R};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n; 
        cin >> n;
        qlim.reset();

        auto [L, R] = solve_case(n);
        submit(L, R);
    }
    return 0;
}
