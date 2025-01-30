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
const int MOD = 998244353;
#endif
//**************************** CODING SPACE ****************************//
vi isVisited;
vvi adj;
int n,m;
bool flag = true;
vi cols;
int ans;
vi mu2;
void input() {
    cin >> n >> m;
    adj.clear(); adj.resize(n+1); isVisited.clear(); isVisited.resize(n+1);
    cols.clear(); cols.resize(4); 
    ans = 1; flag = true;
    FOR(i,0,m){
        int a, b; cin >> a >> b;
        adj[a].PB(b); adj[b].PB(a);
    }
}

void dfs(int u, int c){
    if(adj[u].size() == 0) {
        isVisited[u] = 1;
        cols[1]++;
        return;
    }
    if (isVisited[u] > 0) {
        // debug(u); debug(isVisited[u]); debug(c);
        if (isVisited[u] != c) flag = false;
        return;
    }
    isVisited[u] = c;
    cols[c]++;

    int newColor = c == 1? 2 : 1;
    for(auto v: adj[u]){
        dfs(v, newColor);
    }
}

void updateAns() {
    if(cols[1] + cols[2] == 0) return;
    if(cols[1] + cols[2] == 1) {
        ans = ans*3 %MOD;
        cols[1] = cols[2] = 0;
        return;
    } 
    debug(cols);
    // --> so cach chon = 2^ (max+1);
    ans = ans* ((mu2[cols[1]] % MOD) + (mu2[cols[2]] % MOD))%MOD ;
    // ans = ans* (mu2[cols[2]] % MOD)%MOD;
    cols[1] = cols[2] = 0;
}

void solve() {
    FOR(u,1,n+1){
        if(isVisited[u]) continue;
        updateAns();
        dfs(u,1);
        debug(cols);
    }
    updateAns();
    if(flag == false) {
        cout << "0\n"; return;
    }
    cout << ans%MOD << "\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/input.txt", "r", stdin); freopen("/Users/vangtruong/Documents/01.Learning/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs; cin>> tcs;
    // precaculate
    mu2.clear(); mu2.resize(3e5+5);
    mu2[0] = 1;
    for(int i = 1 ; i < 3e5 + 5; i++){
        mu2[i] = 2*mu2[i-1]% MOD;
    }
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}