#define ON_DEBUG 1
#if 1
#ifdef ONLINE_JUDGE
#include<bits/stdc++.h>
#else
#include "/Users/vangtruong/Documents/01.Learning/bits/stdc++.h"
#endif
using namespace std;

#if ON_DEBUG
//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
#else
#define debug(x) //*** debug ***//
#endif

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}

//*** define ***//
#define int long long
#define PB push_back
#define MP make_pair
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pi = pair<int,int>;
using vvp = vector<vector<pi> >;
#endif
//**************************** CODING SPACE ****************************//
int n;
vvp adj;
vi mark;
void input() {
    cin >> n; adj.clear(); adj.resize(n+1); mark.clear(); mark.resize(n+1,-1);
    FOR(i,0,n-1){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back(MP(b,w));
        adj[b].push_back(MP(a,w));
    }
}
int dfs(int u) {
    if(mark[u] != -1) return 0;
    mark[u] = max(0ll, mark[u]);
    for(auto p: adj[u]){
        // if(mark[p.first] != -1) continue;
        if(p.second == 2) mark[u]++;
        mark[u] += dfs(p.first);
    }
    return mark[u];
}
void solve() {
    mark[1] = dfs(1);
    vi ans;
    FOR(i,1,n+1){
        if(mark[i] == 1) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
    // debug(mark);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 1;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}