#pragma once
#include<bits/stdc++.h>
using namespace std;

//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#define vangtruong  freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout)
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}

void debugVvi(vector<vector<long long>>& _arr) {
    int _maxSize = 0;
    for (auto x : _arr) _maxSize = _maxSize > x.size() ? _maxSize : x.size();
    cout << "Array size[R][C]: [" << _arr.size() << "][" << _arr[0].size() << "]\n";
    //print the index:
    cout << "   [R]   \t";
    for (int i = 0;i < _maxSize; i++) cout << i << "   \t";
    for (int r = 0; r < _arr.size(); r++) {
        cout << "\n   [" << r << "]   \t";
        for (int c = 0; c < _arr[r].size(); c++) {
            cout << _arr[r][c] << "   \t";
        }
    }
    cout << "\n--- END Array debug ---\n";
}
