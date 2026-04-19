/*
    Rating: 1300
    Solved: False

*/ 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    size_t n = 1;
    cin >> n;
    vector<int> v;
    int x, y;
    cin >> y;
    while (y--){
        cin >> x;
        v.push_back(x);
    }
    vector<int> even,odd;
    int N_E = 0,N_O = 0;
    for(int i: v){
        if(i % 2 == 0){
            even.push_back(i);
            N_E++;
        }
        else{
            odd.push_back(i);
            N_O++;
        }        
    }
    sort(even.rbegin(), even.rend());
    sort(odd.begin(),odd.end());
    vector<int> even_S;
    int eS = 0, oS = 0;
    even_S.push_back(0);
    for(int i = 0;i<N_E;i++){
        eS += even[i];
        even_S.push_back(eS);
    }
    int oMax = 0;
    if(N_O != 0){
        oMax = odd.back();
    
    }
    int sum = 0;
    for(int i = 1;i<=n;i++){
        if(N_O == 0){
            cout << "0";
        }
        else if(N_E == 0){
            if(i % 2 == 1){
                sum = oMax;
                cout << sum;
            }
            else{
                cout << "0";
                
            }
        }
        else if(i <= N_E+1){
            sum = oMax+even_S[i-1];
            cout << sum;
        }
        else{
            if(i-N_E % 2 == 0){
                cout << 0;
                continue;
            }
            int no = i - N_E;
            if(no % 2 == 0){
                sum = even_S[N_E-1]+oMax;
            }
            else{
                sum = even_S[N_E]+oMax;
            }
            cout << sum;
        }
        if(i != n){
            cout << " ";
        }
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
