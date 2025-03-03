#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define debugVvi(x) //*** debug ***//
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
#include<bits/stdc++.h>
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
int bs_k_nho_nhat__LON_hon_target(vector<int>& A, int target, int st, int en) {
    if(A[en] < target) return -1ll; // tất cả giá trị [st,en] điều NHỎ HƠN target;
    int _n = en - st + 1, _k = en;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k - b >= st && A[_k - b] >= target) _k -= b;
    if(A[_k] != target) return -1;
    return _k;
}

void solve() {
    int n, target; cin >> n >> target; vector<int> A(n+1); 
    FOR(i,1,n+1) cin>> A[i], A[i] += A[i-1]; 
    int res = 0;
    FOR(i,0,n){
        int pos = bs_k_nho_nhat__LON_hon_target(A, target + A[i], i+1, n);
        if(pos != -1) res++;
    }
    cout << res;
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }