#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

long long sumOfLargestPrimes(string s) {
    set<int> uniquePrimes;

    for (int len = 1; len <= s.size(); len++) {
        for (int start = 0; start <= s.size() - len; start++) {
            string temp = s.substr(start, len);
            int c = stoi(temp);
            if (isPrime(c)) {
                uniquePrimes.insert(c);
            }
        }
    }

    // Get 3 largest
    vector<int> primes(uniquePrimes.begin(), uniquePrimes.end());
    sort(primes.rbegin(), primes.rend());

    long long ans = 0;
    for (int i = 0; i < min((int)3, (int)primes.size()); i++) {
        ans += primes[i];
    }

    return ans;
}


int main(){
    cout<<sumOfLargestPrimes("6735992919");
}