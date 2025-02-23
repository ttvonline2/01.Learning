#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/05.Learning/01.Algorithm/01.Algorithms/debug.h"
#endif
using namespace std;
//*** define ***//
#define int long long
#define INF LONG_LONG_MAX
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#endif
//**************************** CODING SPACE ****************************//

// target = 3 --> { 1, 2, [2], 4, 5 }
// target = 2 --> { 1, 2, [2], 4, 5 }
int bs_k_lon_nhat__NHO_hon_target(vector<int>& A, int target, int st, int en) {
    if(A[st] > target) return -1ll; // tất cả giá trị [st,en] điều LỚN HƠN target;
    int _n = en - st + 1, _k = st;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k + b <= en && A[_k + b] <= target) _k += b;
    return _k;
}

// target = 3 --> { 1, 2, 2, [4], 5}
// target = 2 --> { 1, [2], 2, 4, 5}
int bs_k_nho_nhat__LON_hon_target(vector<int>& A, int target, int st, int en) {
    if(A[en] < target) return -1ll; // tất cả giá trị [st,en] điều NHỎ HƠN target;
    int _n = en - st + 1, _k = en;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k - b >= st && A[_k - b] >= target) _k -= b;
    return _k;
}


void solve() {
    int n; cin >> n; vi A(n); FOR(i,0,n) cin >> A[i];
    debug(A);
    debug(bs_k_nho_nhat__LON_hon_target(A,3,0,4));
    debug(bs_k_nho_nhat__LON_hon_target(A,2,0,4));
    debug(bs_k_nho_nhat__LON_hon_target(A,0,0,4));
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }