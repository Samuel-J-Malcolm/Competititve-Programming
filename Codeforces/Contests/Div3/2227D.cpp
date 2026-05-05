/*


*/

#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;

using vi  = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

// Macros
#define pb    push_back
#define eb    emplace_back
#define mp    make_pair
#define fi    first
#define se    second
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

// Constants
const ll INF  = 1e18;
const int INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    int l;
    cin >> l;
    l*=2;
    vi n(l);
    rep(i,0,l){
        cin >> n[i]; 
    }
    int mex = 1;
    rep(i,0,l){
        priority_queue<int> p;
        int idx = 0;
        if(!(i+1 == l) && n[i] == n[i+1]){
            idx = 1;
        }
        rep(j,0,min(i+1,l-i-idx)){
            if(n[i-j] != n[i+j+idx]){
                break;
            }
            p.emplace(-n[i-j]);
        }
        int k = 0;
        while(p.top() == k && sz(p) > 0){
            k--;
            p.pop();
        }
        while(sz(p) > 0){
            p.pop();
        }
        mex = max(mex,-k);
    }
    cout << mex << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
