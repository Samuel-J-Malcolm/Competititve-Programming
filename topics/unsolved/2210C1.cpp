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

using str = string;


// Constants
const ll INF  = 1e18;
const int INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

ll nfac(auto n){
    ll facs = 1;
    ll facCur = 3;
    ll cVal = 0;
    while(n % 2 == 0){
        facs++;
        n /= 2;
    }
    while(n > facCur * facCur){
        cVal = 1;
        while(n % facCur == 0){
            cVal++;
            n /= facCur;
        }
        facs *= (cVal);
        facCur += 2;
    }
    if(n != 1){
        facs *= 2;
    }
    return facs;
    
}


void solve()
{
    int l = 0;
    cin >> l;
    vi v(l);
    vi v1(l);
    for(auto& i: v){
        cin >> i;
    }
    for(auto& i: v1){
        cin >> i;
    }
    ll cur = 0;

    rep(i,0,l){
        int g = 1;
        int a,b,c = 0;
        a = v[max(0,i-1)];
        b = v[i];
        c = v[min(l-1,i+1)];
        g=gcd(a,b);
        g=gcd(b,c);
        int p = 2;
        cout << g << "! ";
        if(g != b){
            cur++;
        }
        

    }

    cout << cur << "\n";


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
