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

int solvearr(vi arr,int m){
    int e_below = 0;
    int e_above = 0;
    int margin = 0;
    int best_sub = 0;
    int n = 0;
    int n_best = 0;
    vi sols;
    rep(i,0,arr.size()){
        int num = arr.back();
        arr.pop_back();
        if(num > m){
            e_above++;
        }
        else if(num == m){
            margin++;
        }
        else{
            e_below++;
        }
        if(i % 2 == 0){
            n++;
            if(abs(e_above-e_below) < margin){
                n_best = max(n_best,solvearr(arr,m)+n);
            }
        }
    }
    cout << e_above << " " << e_below << " "<< m <<"!\n";
    if(abs(e_above-e_below) >= margin){
        return 0;
    }
    return n_best;

}

void solve()
{
    int l =0;
    cin >> l;
    vi arr;
    vi med;
    int input = 0;
    rep(i,0,l){
        cin >> input;
        arr.push_back(input);
        med.push_back(input);
    }
    sort(all(med));
    int m = med[(l-1)/2];
    cout << m <<"\n";
    int i = 0;
    i = solvearr(arr,m);
    cout <<  i << "\n";
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
