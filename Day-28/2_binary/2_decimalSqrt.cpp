#include <bits/stdc++.h>
using namespace std;

// we need to find 1e-6 precision -> 1e-7 we will take for safer side

bool assistant(double m, int x){
    return m*m <= x;
}
double mySqrt(int x) {
    double  l = 0, r = x, ans = 0;

    double precision = 1e-7;
    while(r - l >= precision){
        double m = (r-l)/2.0 + l;
        if(assistant(m,x)){
            ans = m;
            l = m + precision;
        } else r = m - precision;
    }
    return ans;
}

int main() {
    int x;
    cin >> x;
    cout << fixed << setprecision(6) << mySqrt(x) << endl;
    return 0;
}