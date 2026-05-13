/*

    Rating: 1500+
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
const ll  MOD = 998244353;

ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        //exp & 1 means that 
        if (exp & 1) result = result * base % mod;
        base = (base * base) % mod; //
        exp >>= 1; //divides by 2
    }
    return result;

}


bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
ll modinvprime(ll a, ll mod) { return power(a, mod - 2, mod); } // mod must be prime


void solve()
{
    int l;
    cin >> l;
    vi v(2*l);
    map<int,int> freq_prime;
    map<int,int> freq_composite;
    set<int> p;
    set<int> c;
    ll count = 1;
    int nPrimes = 0;
    rep(i,0,2*l){
        int x;
        cin >> x;
        if(p.count(x) || (!c.count(x) && isPrime(x)) ){
            freq_prime[x]++;
            nPrimes++;
            p.emplace(x);
        }
        else{
            freq_composite[x]++;
            c.emplace(x);
        }
    }
    if(sz(p) < l){
        cout << 0;
        return;
    }
    rep(i,l,sz(p)){
        count *= i;
        count %= MOD;
    }
    rep(i,1,sz(p)-l+1){
        count *= modinvprime(i,MOD);
        count %= MOD;
    }
    


    cout << count;




}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
