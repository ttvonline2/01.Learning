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
void solve() {
    int n, h; cin >> n >> h; vi A(n,0); FOR(i,0,n) cin >> A[i]; sort(A.begin(), A.end());
    vi G = {2,2,3}; int ans = 0;
    do {
        int a = 0, i = 0, curr = h;
        while(a < 3 && i < n) {
            if(curr > A[i]) curr += A[i++]/2;
            else curr*= G[a++];
        }
        while(i < n) {
            if(curr > A[i]) curr += A[i++]/2;
            else break;
        }
        ans = max(ans,i);
    } while (next_permutation(G.begin(), G.end()));
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }