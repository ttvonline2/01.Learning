#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
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
int getCong(vi& pre, int st, int en){
    if(en < st) return 0;
    return pre[en] - pre[st-1];
}
void solve() {
    int n,d,k; cin >> n >> d >> k;
    vi v(n+2), cur(n+2), b(n+2), pre(n+2);
    FOR(i,0,k){
        int l,r; cin >> l >> r;
        v[l]++; v[r+1]--;
        b[l]++;
    }
    FOR(i,1,n+1) cur[i] = cur[i-1] + v[i];
    FOR(i,1,n+1) pre[i] = pre[i-1] + b[i];
    int mi = INT_MAX, ma = 0, anh, me;
    FOR(i,1,n+2-d){
        int event = cur[i] + getCong(pre,i+1,i+d-1); // cur[i] va tat ca event+ tu [i+1, i+d]
        if(event > ma) anh = i, ma = event;
        if(event < mi) me = i, mi = event;
    }
    cout << anh << " " << me << "\n";

}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }