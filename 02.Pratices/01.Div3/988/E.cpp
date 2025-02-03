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
int n, m1,m2;
vvi adjG; 
vi isVisited;
vector<set<int>> adjF;
void input() {
    cin >> n >> m1 >> m2;
    adjG.clear(); adjG.resize(n+1); isVisited.clear(); isVisited.resize(n+1);
    adjF.clear(); adjF.resize(n+1);
    int a, b;
    FOR(i,0,m1){
        cin >> a >> b; 
        adjF[a].insert(b);
        adjF[b].insert(a);
    }

    FOR(i,0,m2){
        cin >> a >> b;
        adjG[a].push_back(b); adjG[b].push_back(a);
    }
}
void dfsG(int u, set<int>& dsuG){
    if(isVisited[u] == 1) return;
    isVisited[u] = 1; dsuG.insert(u);
    for(auto v: adjG[u]) dfsG(v,dsuG);
}

void dfsF(int u) {
    if(isVisited[u] == 1) return;
    isVisited[u] = 1;
    for(auto v: adjF[u]){
        dfsF(v);
    }
}
void solve() {
    // count dsu set of G
    vector<set<int>> oriDsu;
    FOR(i,1,n+1){
        if(isVisited[i] == 0){
            set<int> dsuG;
            dfsG(i, dsuG);
            oriDsu.push_back(dsuG);
        }
    }
    // debug(oriDsu);
    // Duyet tung set dsuG --> remove cac canh connect outsize of set dsuG;
    int ans = 0;
    for (auto dsu : oriDsu) {
        for (auto u : dsu) {
            for (auto it = adjF[u].begin(); it != adjF[u].end();) {
                int v = *it;
                if (dsu.find(v) == dsu.end()) {
                    ans++;
                    it = adjF[u].erase(it); 
                    adjF[v].erase(u);
                    continue;
                }
                it++;
            }
        }
    }
    // xoa
    // debug(ans);
    // noi
    isVisited.clear(); isVisited.resize(n+1,0);
    for(auto dsu : oriDsu) {
        int cnt = 0;
        for(auto u: dsu){
            if(isVisited[u] == 1) continue;
            cnt++;
            dfsF(u);
        }
        ans += (cnt - 1);
    }
    // debug(ans);
    cout << ans << "\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("D:/05.Learning/01.Algorithm/00.Ultility/input.txt", "r", stdin); freopen("D:/05.Learning/01.Algorithm/00.Ultility/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int tcs = 1; cin >> tcs;
    while (tcs--) {
        input();
        solve();
    }
    return 0;
}