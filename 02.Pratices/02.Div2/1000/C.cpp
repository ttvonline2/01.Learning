#define ON_DEBUG 0
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

#endif
//**************************** CODING SPACE ****************************//
vvi adj;
vb isVisited;
int n;

void debugGraph(vvi& adjecentEdges) {
    return;
    cout << "Debug Graph:\n";
    FOR(i,0,n){
        for(auto u: adj[i]){
            cout << i << " " << u <<"\n";
        }
    }
}
void input() {
    cin >> n;
    adj.clear(); adj.resize(n);
    isVisited.clear(); isVisited.resize(n,false);
    for(int i = 0 ; i < n - 1; i ++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }

}
void dfs(int u) {
    if(isVisited[u]) return;
    isVisited[u] = true;
    for(auto x: adj[u]) {
        dfs(x);
    }
}
void maxLevel(int& mv, int& v){
    FOR(i,0,n){
        if(adj[i].size() > mv){
            mv = adj[i].size();
            v = i;
        }
    }
}
void solve() {
    if(n < 3) {
        cout << "0\n"; return;
    }
    auto backupAdj = adj;
    debugGraph(adj);
    int mv = 0, v = 0;
    maxLevel(mv,v);

    for(auto u: adj[v]){
        // tim canh maxVetex de remove trong adj
        FORE(it,adj[u]){
            if(*it == v) {
                adj[u].erase(it);
                break;
            }
        }
    }
    debug(v);
    // clear edge
    adj[v] = vi(0);
    debugGraph(adj);
    mv = 0; v = 0;
    maxLevel(mv,v);
    for(auto u: adj[v]){
        FORE(it,adj[u]){
            if(*it == v) {
                adj[u].erase(it);
                break;
            }
        }
    }
    adj[v] = vi(0);
    // dfs tinh connected
    int cnt1 = 0;
    debug(v);
    debugGraph(adj);
    
    FOR(i,0,n){ 
        if(!isVisited[i]) {
            cnt1++;
            dfs(i);
        }
    }
    // need to remove the second node first?
    adj = backupAdj;
    debug(adj);
    debug(v);
    for(auto u: adj[v]){
        FORE(it,adj[u]){
            if(*it == v) {
                adj[u].erase(it);
                break;
            }
        }
    }
    adj[v] = vi(0);

    mv = 0; v = 0;
    maxLevel(mv,v);
    for(auto u: adj[v]){
        FORE(it,adj[u]){
            if(*it == v) {
                adj[u].erase(it);
                break;
            }
        }
    }
    adj[v] = vi(0);

    // count again
    int cnt2 = 0;  
    isVisited.clear(); isVisited.resize(n,false);
    FOR(i,0,n){ 
        if(!isVisited[i]) {
            cnt2++;
            dfs(i);
        }
    }
    int ans = max(cnt1,cnt2);
    cout << ans - 2 << "\n";
    debugGraph(adj);
}   

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs; cin >> tcs;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}