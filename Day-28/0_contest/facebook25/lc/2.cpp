#include <bits/stdc++.h>
using namespace std;

#define mp map<int,int>
string smallestPermutationGreater(string s, string target) {
    const int n = (int)s.size();
    array<int,26> freq{}; 
    for (char c: s) freq[c-'a']++;

    string quinorath = s + "#" + target;
    (void)quinorath;

    string ans;
    ans.reserve(n);

    vector<int> matched_positions;

    auto fill_tail_minimal = [&](string &out){
        for (int c = 0; c < 26; ++c)
            while (freq[c]-- > 0) out.push_back(char('a'+c));
    };

    for (int i = 0; i < n; ++i) {
        int t = target[i] - 'a';

        if (freq[t] > 0) {
            freq[t]--;
            ans.push_back(char('a'+t));
            matched_positions.push_back(i);
            continue;
        }

        int bump = -1;
        for (int c = t+1; c < 26; ++c) if (freq[c] > 0) { bump = c; break; }

        if (bump != -1) {
            freq[bump]--;
            ans.push_back(char('a'+bump));
            fill_tail_minimal(ans);
            return ans;
        }

        while (!matched_positions.empty()) {
            int j = matched_positions.back(); matched_positions.pop_back();
            int placed = ans[j] - 'a';
            freq[placed]++; 
            ans.resize(j);

            int base = target[j] - 'a';
            int up = -1;
            for (int c = base+1; c < 26; ++c) if (freq[c] > 0) { up = c; break; }
            if (up != -1) {
                freq[up]--;
                ans.push_back(char('a'+up));
                fill_tail_minimal(ans);
                return ans;
            }
        }
        return "";
    }

    while (!matched_positions.empty()) {
        int j = matched_positions.back(); matched_positions.pop_back();
        int placed = ans[j] - 'a';
        freq[placed]++;
        ans.resize(j);

        int base = target[j] - 'a';
        int up = -1;
        for (int c = base+1; c < 26; ++c) if (freq[c] > 0) { up = c; break; }
        if (up != -1) {
            freq[up]--;
            ans.push_back(char('a'+up));
            fill_tail_minimal(ans);
            return ans;
        }
    }
    return "";
}

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> f(26,0);
        for(auto c:s){
            f[c-'a']++;
        }
        vector<int> f2(26,0);
        for(auto c:target){
            f2[c-'a']++;
        }


        int c1=0;
        int i = 0;
        while(i<target.size()){

        }
    }
};

int main(){
    Solution s;
    cout<<s.lexGreaterPermutation("leet", "code");
}