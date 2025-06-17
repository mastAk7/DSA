#include <bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    while (k--) {
        int n, s; cin >> n >> s;
        if (n == 1) {
            int x;
            cin >> x;
            cout << abs(x - s) << endl;
        } else {
            int l, r;
            for (int i = 0; i < n; i++) {
                int x; cin >> x;
                if (i == 0) l = x;
                if (i == n - 1) r = x;
            }
            int x = 0;
            if (s > l && s < r) {
                if (s - l > r - s) {
                    x += (r - s);
                    x += r - l;
                } else {
                    x += (s - l);
                    x += r - l;
                }
            } else if (s <= l) {
                x = r - s;
            } else if (s >= r) {
                x = s - l;
            }
            cout << x << endl;
        }
    }
}
