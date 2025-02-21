#if 1
#ifdef ONLINE_JUDGE
#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete
#define debug(x) //*** debug ***//
#define debugVi(x) //*** debug ***//
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
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#endif
//**************************** CODING SPACE ****************************//
bool cmp(pi a,  pi b){
    return a.first > b.first;
}
int getAns(pi a, vvi& adj, vi D){
    int res = D[a.second];
    D[a.second] = 0;
    for(auto u: adj[a.second]){
        D[u]--;
    }
    vector<pi> L(D.size());
    FOR(i,1,D.size()) L[i] = MP(D[i],i);
    sort(L.begin(), L.end(), cmp);
    // for(auto x : L) debug(x);
    res += L[0].first - 1ll;
    return res;
}
void solve() {
    int n; cin >> n;
    vector<pi> L(n+1);
    vvi adj(n+1);
    vi D(n+1,0);
    FOR(i,0,n-1){
        int a, b; cin >> a >> b;
        D[a]++; D[b]++;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    // make pi
    FOR(i,1,n+1) L[i] = MP(D[i],i);
    sort(L.begin(), L.end(), cmp);
    if(n == 2) {
        cout << "0\n"; return;
    }
    pi a = L[0], b = L[1], c = L[2];
    int ans = -INF;
    ans = max(ans, getAns(a, adj, D));
    ans = max(ans, getAns(b, adj, D));
    ans = max(ans, getAns(c, adj, D));
    cout << ans << "\n";
}

int32_t main() {
    vangtruong; int tcs = 1; cin >> tcs;
    while (tcs--) {solve();}return 0; }