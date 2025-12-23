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
        int n;  cin>>n;
        vi f(n);
        for(int i=0; i<n; i++){
            int x; cin>>x;
            f[i] = x;
        }
        
        

        int mx = 0, idx = -1;
        for(int i=2; i<n; i++){
            if((f[i-2]<f[i-1] && f[i]<f[i-1]) || (f[i-2]>f[i-1] && f[i]>f[i-1])){
                int x = abs(f[i-1]-f[i]) + abs(f[i-1]-f[i-2]) - abs(f[i-2]-f[i]);
                if(x>mx){
                    mx = x;
                    idx = i-1; 
                }
            }
        }

        int ans = 0;

        int a = 0, b = 0;
        for(int i=0; i<n-2; i++) a += abs(f[i]-f[i+1]);
        for(int i=1; i<n-1; i++) b += abs(f[i]-f[i+1]);
        for(int i=0; i<n-1; i++){
            if(i==idx){
                ans += abs(f[i-1]-f[i+1]);
                continue;
            } else if(i+1 == idx) continue;
            ans += abs(f[i]-f[i+1]);
        }

        ans = min(ans,min(a,b));

        cout<<ans<<endl;
    }
    return 0;
}