#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define loopD(i, a, n) for (lli i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(a) ((int)a.size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define endl '\n'
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define fi first
#define si second
#define v(a) vector<int>(a)
#define vv(a) vector<vector<int>>(a)
#define present(c, x) ((c).find(x) != (c).end())
#define set_bits __builtin_popcountll
#define MOD 1000000007
#define int long long

typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umpi;
typedef map<int, int> mpi;
typedef vector<pii> vp;
typedef vector<lli> vll;
typedef vector<vll> vvll;

using ll = long long;

void solve()
{
    int n, a, b, ca = 0, cb = 0, x = 0;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vi fa(n), fb(n);

    for (auto c : s)
    {
        if (c - '0')
            cb = 1;
        else
            ca = 1;
        if (ca && cb)
            break;
    }

    int za = 0, zb = 0;
    int e = 0, o = 0;
    int xa = 0, xb = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 2 == 0)
        {
            e = 1;
            if (s[i] == '0')
            {
                zb++;
                fa[i] = x / 2 + 1;
                fb[i] = x / 2 - 1;
            }
            else
            {
                za++;
                fa[i] = x / 2 - 1;
                fb[i] = x / 2 + 1;
            }
        }
        else
        {
            o=1;
            if (s[i] == '0')
            {
                fa[i] = x / 2 + 1;
                fb[i] = x / 2;
            }
            else
            {
                fa[i] = x / 2;
                fb[i] = x / 2 + 1;
            }
        }
        xa += fa[i];
        xb += fb[i];
    }
    
    if (xa > a || xb > b){
        NO
        return;
    }
    

    if(ca && cb){
        YES
        return;
    }
    
    if(ca==0 && xa < a - za){
        if(a-za-xa<b-xb){
            YES
            return;
        }
    }
    
    if(cb==0 && xb < b - zb){
        if(b-zb-xb<a-xa){
            YES
            return;
        }
    }
    
    NO
    return;
}

int32_t main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}