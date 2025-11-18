#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int mn = min({a, b, c});
    int mx = max({a, b, c});

    if (mx - mn >= 10) {
        cout << "check again\n";
    } else {
        int arr[3] = {a, b, c};
        sort(arr, arr+3);
        cout << "final " << arr[1] << "\n";
    }
}
