#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> reports(n);
        for (int i = 0; i < n; i++) {
            cin >> reports[i];
        }
        
        // Count winners and losers from reports
        int winners = 0;
        for (int i = 0; i < n; i++) {
            if (reports[i] == 1) {
                winners++;
            }
        }
        
        // In n-1 matches, there must be exactly n-1 losses and n-1 wins total
        // So there must be at least n-1 players reporting a win (value 1)
        // Or, at most 1 player can report no wins (value 0)
        
        int zeros = n - winners;
        
        // If there are more than 1 player reporting 0, someone must be lying
        if (zeros > 1) {
            cout << "YES" << endl; // There's a liar
        } else if (zeros == 0) {
            // If everyone reports winning at least one match
            // This is impossible since n-1 matches means at least one person must have lost all matches
            cout << "YES" << endl; // There's a liar
        } else {
            // Exactly one player reports 0 - this could be consistent
            cout << "NO" << endl; // No proven liar
        }
    }
    
    return 0;
}