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

void solve()
{
    ll l;
    cin >> l;
    vll v;
    set<ll> s;
    ll dupes = 0;
    ll input;
    ll maxi = 0;
    rep(i,0,l){
        cin >> input;
        if(s.count(input)){
            dupes++;
        }
        else{
            maxi = max(input,maxi);
            v.push_back(input);
            s.emplace(input);
        }
    }
    ull mex = 0;
    ll sum = 0;
    ll s1 = sz(v);
    sort(all(v));
    rep(i,0,s1){
        input = v[i];
    //    cout << input << " ";
        if(mex == input){
            mex++; 
        }
        else{
            break;
        }
    }
    sum += (mex*(mex+1))/2;
    if(maxi == mex){
        mex++;
    }
    sum += mex * (l-mex);
    sum += l*maxi;
    if(mex == 2){
        sum--;
    }
    cout << sum;
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
