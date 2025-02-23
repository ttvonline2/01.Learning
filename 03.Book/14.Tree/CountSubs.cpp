#if 1
#define ON_DEBUG 0
#include<bits/stdc++.h>
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
vi cnt;
void dfs(int u, int e){
    cnt[u] = 1;
    for(auto x: adj[u]){
        if(x == e) continue;
        dfs(x,u);
        cnt[u] += cnt[x];
    }
}
void input() {
    int n; cin >> n;
    adj.resize(n+1);
    // int temp; cin >> temp;
    FOR(i,2,n+1){
        int b; cin >> b;
        adj[b].push_back(i);
        adj[i].push_back(b);
    }
    debug(adj);
    if(n == 1) {
        cout << "1" ; return;
    }
    // duyet dfs(1,0)
    cnt.resize(n+1);
    dfs(1,0);
    FOR(i,1,n+1) cout << cnt[i]-1 << " ";
}

void solve() {
    
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 1; 
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}