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
using pli = pair<ll,int>;

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
    ll l = 0;
    cin >> l;
    vll v(l);
    vector<pli> v1(l);
    ll sum = 0;
    rep(i,0,l){
        cin >> v[i];
        v1[i] = pair(v[i],i);
    }
    sort(all(v1));
    ll minl = v[l-1];
    ll max_add = 0;
    vi sums(l+1);
    for(ll i = l-1;i>= 0;i--){
        ll x = v[i];
        ll cAdd = 0;
        sum -= x*i;

        if(i+cAdd >= max_add){
            for(ll j=i-1;j >= 0;j--){
            if(x <= v[j]){
                cAdd++;
            }
            }
        }
        max_add = max(cAdd,max_add);

    }
    sort(all(v));
    rep(i,0,l){
        sum += v[i]*i;
    }
    cout <<(sum+max_add)<< "\n";
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
