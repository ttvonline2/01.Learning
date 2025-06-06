#define ON_DEBUG 0
#if 1
#ifdef ONLINE_JUDGE
#include<bits/stdc++.h>
#else
#include "D:/01.Learning/01.Algorithms/debug2.h"
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

#endif
//**************************** CODING SPACE ****************************//
vi isVisited;
vvi adj;
int n,m;
bool flag = true;
vvi  ans;
void input() {
    cin >> n >> m;
    adj.clear(); adj.resize(n+1); isVisited.clear(); isVisited.resize(n+1);
    ans.resize(2);
    FOR(i,0,m){
        int a, b; cin >> a >> b;
        adj[a].PB(b); adj[b].PB(a);
    }
}

void dfs(int u, int c){
    debug(u); debug(c);
    if(adj[u].size() == 0) {
        isVisited[u] = 3;
        return;
    }
    if (isVisited[u] > 0) {
        // debug(u); debug(isVisited[u]); debug(c);
        if (isVisited[u] != c) flag = false;
        return;
    }
    isVisited[u] = c;
    ans[c-1].push_back(u);

    int newColor = c == 1? 2 : 1;
    for(auto v: adj[u]){
        dfs(v, newColor);
    }
}
void solve() {
    FOR(u,1,n+1){
        if(isVisited[u]) continue;
        dfs(u,1);
    }
    if(flag == false) {
        cout << "-1\n"; return;
    }
    cout << ans[0].size() << "\n";
    for(auto x: ans[0]) cout << x << " ";
    cout << "\n" << ans[1].size() << "\n";
    for(auto x: ans[1]) cout << x << " ";
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