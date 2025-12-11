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
        int n; cin>>n;
        vi e;
        int o = 0;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            if(x%2) o = max(x,o);
            else e.push_back(x); 
        }
        if(o==0){
            for(int i=0; i<n; i++) cout<<0<<' ';
        } else{
            sort(rall(e));
            cout<<o<<' ';
            for(auto x:e){
                o += x;
                cout<<o<<' ';
            }
            int r = (n-e.size()-1), l = o;
            if(sz(e)) l = e.back();
            for(int i=0; i<r; i++){
                if(i==r-1 && r%2==1){
                    cout<<0<<' ';
                    break;
                }
                if(i%2==0) cout<<o-l<<' ';
                else cout<<o<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}