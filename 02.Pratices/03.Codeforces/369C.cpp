#define ON_DEBUG 1
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
int n;
vi isVisited, mark;
vector<vector<pi> >  adj;
vvi allLevel;
vi ans;
void input() {
    cin >> n;
    adj.resize(n+1); isVisited.resize(n+1,0);
    mark.resize(n+1,-1);
    allLevel.resize(n+1);
    FOR(i,0,n-1){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back(MP(b,w));
        adj[b].push_back(MP(a,w));
    }
}
void dfs(int u, int level){
    if(isVisited[u]) return;
    isVisited[u] = 1;
    allLevel[level].push_back(u);
    for(auto x: adj[u]) {
        int b = x.first;
        if(isVisited[b]) continue;
        dfs(b,level+1);
    }
}

void solve() {
    dfs(1,0);
    isVisited.clear(); isVisited.resize(n+1);
    for(int i = n ; i >= 1 ; i --){
        for(auto u: allLevel[i]){
            if(mark[u]> 0) { // da duoc tham boi thang duoi, forward len level tiep theo
                for(auto x: adj[u]){
                    int b = x.first;
                    if(mark[b] != -1) continue;
                    mark[b] = mark[u]; // chia se diem cho level tren
                    mark[u] = 0;
                }
            } else { // chua xu ly ->> duyet len tren, 
                for(auto x: adj[u]){
                    int b = x.first;
                    if(mark[b] == 0) continue;
                    if(x.second == 2) {
                        mark[u] = 0; ans.push_back(u);
                        mark[b] = max(mark[b]+1, 1ll);
                    } else {
                        mark[u] = 0;
                    }
                }

            }
        }
    }
    // debug(allLevel);
    // debug(ans);
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
    
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