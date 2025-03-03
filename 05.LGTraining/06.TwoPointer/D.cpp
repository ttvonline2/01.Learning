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
const int MAXN = 2e5+5;
void solve() {
    int n; cin >> n ; vector<pi> A(MAXN,MP(INT_MAX, -1)); // min, last
    FOR(i,0,n) {
        int x; cin >> x;
        if(A[x].second == -1) A[x].second = i;
        else {
            A[x].first = min(A[x].first, i - A[x].second); A[x].second = i;
        }
    }
    //
    int ans = INT_MAX;
    FOR(i,0,MAXN) {
        if(A[i].first == INT_MAX) continue;
        ans = min(ans, A[i].first);
    }
    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans+1 << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }