#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugVvi(x) //*** debug ***//
#else
#include "D:/05.Learning/01.Algorithm/01.Algorithms/debug.h"
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

//*** custom using ***//
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>;
using pi = pair<int,int>;
int itemp = 0; string stemp = "";

#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int n,m; cin >> n >> m; 
    vi A(n), B(n);
    vvi dp(2,vi(n,LONG_LONG_MAX));
    FOR(i,0,n) cin >> A[i];
    FOR(i,0,n) cin >> B[i];
    for(int i = n-1; i >= 0; i --) {
        if(i == n-1){
            dp[0][i] = A[i]; dp[1][i] = B[i];
            continue;
        }
        dp[0][i] = min(dp[0][i+1],dp[1][i+1]) + A[i];
        dp[1][i] = min(dp[0][i+1],dp[1][i+1]) + B[i];
    }
    int ans = LONG_LONG_MAX;
    debugVvi(dp);
    FOR(i,0,m){
        ans = min(ans, dp[0][i]);
    }
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; 
    int tcs = 1; cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}