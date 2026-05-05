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
    int l = 0;
    cin >> l;
    vi m6;
    vi m2;
    vi m3;
    vi m1;
    rep(i,0,l){
        int input;
        cin >> input;
        if(input % 6 == 0){
            m6.push_back(input);
        }
        else if(input % 3 == 0){
            m3.push_back(input);
        }
        else if(input % 2 == 0){
            m2.push_back(input);
        }
        else{
            m1.push_back(input);
        }
    }
    for(int i: m6){
        cout << i << " ";
    }
    for(int i: m3){
        cout << i << " ";
    }
    for(int i: m1){
        cout << i << " ";
    }
    for(int i: m2){
        cout << i << " ";
    }
    cout << "\n";
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
