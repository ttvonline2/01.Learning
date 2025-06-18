#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define hihihaha //*** debug ***//
#define debug(...) //*** debug ***//
#define DB(...) //*** debug ***//
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
#define int long long
#define oo 4e18
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)
#define all(x) (x).begin(), (x).end()
#define CR(_x,_n) (_x).clear(); (_x).resize((_n))
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>; using vpi = vector<pair<int,int>>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = ""; using vvpi = vector<vector<pair<int,int>>>;
template <typename T, typename Comp>
using ordered_set_custom = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>; // Comp = less<int>, less_equal<int>, greater<int>, StructComp
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
#endif
//**************************** CODING SPACE ****************************//

void solve() {
    int n,m,l; cin >> n >> m >> l;
    int S = 0; 
    for(int i = 0, x; i < l; i++) {cin >> x; S += x;}
    vvi g(n+1);
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi dist(n+1, -1), kernel(n+1,-1);
    queue<int> q; q.push(1); dist[1] = 0; kernel[1] = 0;
    bool bip = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: g[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u]+1;
                kernel[v] = kernel[u]^1;
                q.push(v);
            } else if(kernel[v] == kernel[u]) bip = false;
        }
    }
    string ans(n,'0'); 
    if(bip) {
        for(int i = 1; i <= n ; i++)
            if(dist[i] <= S && ((S-dist[i])&1) == 0) ans[i-1]='1';
    } else {
        for(int i=2; i<=n;i++)
            if(dist[i]<=S) ans[i-1]='1';
        if(S!=1) ans[0] = '1';
    }
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();} hihihaha; return 0; }