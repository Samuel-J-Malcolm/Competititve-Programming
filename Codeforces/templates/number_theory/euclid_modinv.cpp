/*

    Extended Euclidean Algorithm
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int modinv(int r0,int r1,int s0=0, int s1=1){
    int q = r0/r1;
    int r2 = r0-q*r1;
    int s2 = s0-q*s1;
    if(r2 == 0){
        if(r1 != 1){
            return -1;
        }
        else{
            return modinv(r1,r2,s1,s2);
        }
    }
}

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

ll modinvprime(ll a, ll mod) { return power(a, mod - 2, mod); } // mod must be prime
