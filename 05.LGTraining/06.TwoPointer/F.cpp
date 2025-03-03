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
int getRes(int n){
    assert(n>0);
    if(n == 1) return 0;
    n--;
    if(n&1) return (n+1)*(n-1)/2 + (n+1)/2;
    else return (n+1)*n/2;
}
void solve() {
    int n, m, en = INT_MAX, ans = 0; cin >> n >> m; map<int,set<int>> NoFriend; vi AE(n+2); // array end
    FOR(i,0,m){
        int a, b; cin >> a>>b; if(a > b) swap(a,b); NoFriend[a].insert(b);
        AE[b]++; en = min(en,b);
    }
    for(auto s: NoFriend) debug(s);
    debug(en);
    int i = 1;
    FOR(i,1,n+1){
        ans += en - i;
        debug(ans);
        assert(en - i > 0);
        // remove pair
        if(NoFriend.count(i) == 1){
            for(auto f: NoFriend[i]) AE[f]--;
        }
        // try increase en;
        while(en <= n && AE[en] == 0) en++;
        debug(en);
    }
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }