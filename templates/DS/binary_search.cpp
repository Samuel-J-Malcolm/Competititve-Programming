#include <bits/stdc++.h>
using namespace std;

template <typename T, typename F>
int binSearch(vector<T>& ls,F check){
    int sz = size(ls);
    int l = 0;
    int r = sz;
    while(r>l){
        int m = (l+r)/2;
        if(check(ls[m])){
            r = m
        }
        else{
            l = m+1;
        }
    }
    if(l == sz){
        return -1;
    }
    return l;
}

auto check = [&](int x) {
    int i;
    return (x) > i;
};