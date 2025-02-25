#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define debugv(x) //*** debug ***//
#include<bits/stdc++.h>
#else
#include "D:/01.Algorithm/01.Algorithms/debug.h"
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
const int MAXP = 450;
vi P(MAXP, 0);
int bs_k_lon_nhat__NHO_hon_target(vector<int>& A, int target, int st, int en) {
    if(A[st] > target) return -1ll; // tất cả giá trị [st,en] điều LỚN HƠN target;
    int _n = en - st + 1, _k = st;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k + b <= en && A[_k + b] <= target) _k += b;
    return _k;
}
void precaculate(){
    P[0] = 1;
    FOR(i,1,MAXP) P[i] = P[i-1]+i+1;
    // debug(P);
}
void solve() {
    int k; cin >> k;
    // tim so dinh
    if(k == 0) { cout << "2\n2 2\n1 1\n"; return; }
    int y = 1, x = 1;
    vector<pi> ans;
    while(k > 0){
        int pos = bs_k_lon_nhat__NHO_hon_target(P, k, 0, 449); 
        k -= P[pos];
        debug(P[pos]);
        // xay dung Pos + 1 dinh
        FOR(i,0,pos + 2) ans.push_back(MP(y,x++));
        y++;
    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x.first << " " << x.second  << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    precaculate();
    while (tcs--) {solve();} hihihaha; return 0; }