#define ON_DEBUG 1
#if 1
#ifdef ONLINE_JUDGE
#include<bits/stdc++.h>
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
using namespace std;

#if ON_DEBUG
//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
#else
#define debug(x) //*** debug ***//
#endif

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

//*** define ***//
#define int long long
#define PB push_back
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pi = pair<int,int>;
using vvp = vector<vector<pi> >;

#endif
//**************************** CODING SPACE ****************************//
vi arr(2);
void preCaculate(){
    arr[0] = 1; arr[1] = 4;
    for(int i = 2; i < 100 ; i ++){
        arr.push_back(2*(arr[i-1]+1));
        if(arr[i] > 10e6) break;
    }
    // debug(arr);
}
int BinarySearch_Smallest_k(vector<int>& A, int target) {
    int n = A.size();
    int k = n - 1;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k - b >= 0 && A[k - b] >= target) k -= b;
    }
    return k;
}
void input() {
    // arr[0]
    int value; cin >> value;
    cout << BinarySearch_Smallest_k(arr, value) + 1 << "\n";
}

void solve() {
    
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    preCaculate();
    int tcs; cin >> tcs;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}