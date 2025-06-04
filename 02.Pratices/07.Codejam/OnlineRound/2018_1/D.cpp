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
using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>;
using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = "";
#else
#include "D:/01.Learning/01.Algorithms/debug.h"
#endif
//**************************** CODING SPACE ****************************//
struct D {
    int u, c,t;
    D(int _u, int _c, int _t) {
        u = _u; c = _c ; t = _t;
    }
};
int n,m,k;
vector<vector<D>> adj; // [Dinh][{a,,c}]

int getCost(int P, int c, int t){
    if(P <= t) return 0;
    return c*(P-t)*(P-t);
}
bool check(int P) {
    // tim duong di ngan nhat tu 1 --> n;
    vb isVisited(n+1,0);
    vi dis(n+1,oo);
    dis[1] = 0;
    multiset<pi> q;
    q.insert(MP(getCost(P,0,0), 1));
    while (!q.empty()) {
        // get the last vertice () of the priority queue + remove
        int a = q.rbegin()->second; q.erase(--q.end());
        if (isVisited[a]) continue;
        isVisited[a] = true;
        //scan the adj list of vertice a;
        for (auto x : adj[a]) {
            int b = x.u, w = getCost(P,x.c, x.t);
            int newDis = dis[a] + w;
            if (newDis < dis[b]) {
                dis[b] = newDis;
            }
            q.insert(MP(-dis[b], b));
        }
    }
    debug(dis);
    return dis[n] <= k;
}

// target = 3 --> { 1, 2, [2], 4, 5 }
// target = 2 --> { 1, 2, [2], 4, 5 }
int bs_k_lon_nhat__NHO_hon_target(int st, int en) {
    int _n = en - st + 1, _k = st;
    for (int b = _n / 2; b >= 1; b /= 2) while (_k + b <= en && check(_k + b)){debug(_k); _k += b;}
    return _k;
}


void solve() {
    cin >> n >> m >> k; adj.clear(); adj.resize(n+1); D d = D(0,0,0);
    FOR(i,0,n) {
        int a,b,c,t; cin >> a >> d.u >> d.c >> d.t; adj[a].push_back(d);
    }
    FOR(i,1,11) check(i);
    // int res = bs_k_lon_nhat__NHO_hon_target(1, 9);
    // debug(res);
}



int32_t main() {
    vangtruong; int tcs = 1;
    while (tcs--) {solve();} hihihaha; return 0; }