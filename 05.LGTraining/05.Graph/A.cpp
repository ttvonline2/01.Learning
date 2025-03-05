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
int n; vvi adj; vi G;
void dfs(int u, bool isGroupA){
    if(G[u] != 0) return;
    G[u] = isGroupA ? 1 : 2;
    for(auto v: adj[u]){
        if(G[v] != 0) continue;
        dfs(v,!isGroupA);
    }
}
void solve() {
    cin >> n; adj.resize(n+1); G.resize(n+1);
    FOR(i,0,n-1) {
        int a,b; cin>>a>>b; adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1,true);
    int a = 0, b = 0;
    DB(G);
    for(auto x: G) {
        if(x == 1) a++;
        if(x == 2) b++;
    }
    cout << (a-1)*(b-1) << "\n";

}

int32_t main() {
    vangtruong; int tcs = 1; 
    while (tcs--) {solve();} hihihaha; return 0; }