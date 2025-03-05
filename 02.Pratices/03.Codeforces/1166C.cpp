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
    if(st < 0 || en >= A.size()) return -1ll;
    if(A[en] < target) return -1ll; // tất cả giá trị [st,en] điều NHỎ HƠN target;
    int _n = en - st + 1, _k = en;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k - b >= st && A[_k - b] >= target) _k -= b;
    return _k;
}

int bs_k_lon_nhat__NHO_hon_target(vector<int>& A, int target, int st, int en) {
    if(st < 0 || en >= A.size()) return -1ll;
    if(A[st] > target) return -1ll; // tất cả giá trị [st,en] điều LỚN HƠN target;
    int _n = en - st + 1, _k = st;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k + b <= en && A[_k + b] <= target) _k += b;
    return _k;
}

void solve() {
    int n; cin >> n; vi A(n); FOR(i,0,n) cin >> A[i]; sort(A.begin(),A.end());
    int ans = 0;
    FOR(i,0,n-1){
        if(A[i] == 0 ) continue;
        int target = (abs(A[i])-1 )/ 2; 
        int pos1 = bs_k_nho_nhat__LON_hon_target(A, -target, i+1, n - 1);
        int pos2 = bs_k_lon_nhat__NHO_hon_target(A, target, i+1, n - 1);
        debug(A[i]); debug(target); debug(pos1); debug(pos2); 
        // if(pos2 < pos1) continue;
        if(abs(A[pos1]) > target && abs(A[pos2]) > target) {
            ans += (n - 1) - (i+1) + 1;
        } else {
            ans += (n - 1) - (i+1) + 1 - (pos2 - pos1 + 1);
        }
        assert(pos1 != -1 || pos2 != -1);
        debug(ans);
    }
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }