#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long
#define mi map<int,int>
#define l(n) for(int j=0; j<n; j++)

bool reachable(const vector<ll>& A, ll h) {
    int n = (int)A.size();
    ll blockMin = A[0];
    for(int i = 1; i < n; i++) {
        if (abs(A[i] - A[i-1]) <= h) {
            blockMin = min(blockMin, A[i]);
        } else {
            if (blockMin > h) return false;
            blockMin = A[i];
        }
    }
    return blockMin <= h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    l(t) {
        int n; cin >> n;
        vector<ll> A(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        ll hi = 0;
        for(int i = 0; i < n; i++) hi = max(hi, A[i]);
        for(int i = 1; i < n; i++) hi = max(hi, abs(A[i] - A[i-1]));
        ll lo = 0;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            if (reachable(A, mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << "Case #" << j + 1 << ": " << lo << "\n";
    }
}
