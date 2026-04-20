/*

    Extended Euclidean Algorithm
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int invert(int r0,int r1,int s0=0, int s1=1){
    int q = r0/r1;
    int r2 = r0-q*r1;
    int s2 = s0-q*s1;
    if(r2 == 0){
        if(r1 != 1){
            return -1;
        }
        else{
            return invert(r1,r2,s1,s2);
        }
    }
}