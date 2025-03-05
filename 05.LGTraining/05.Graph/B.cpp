#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(x) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define oo 9e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int n, m; cin >> n >> m; vvi adj(n+1);
    FOR(i,0,m) {
        int a,b; cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    vi G(n+1);
    FOR(i,1,n+1){
        if(G[i] != 0) continue;
        G[i] = 1;
        for(auto x: adj[i]){
            if(G[x] == 0) G[x] = 2;
        }
    }
    vi ans;
    FOR(i,1,n+1) if(G[i] == 1) ans.push_back(i);
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
    cout << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }