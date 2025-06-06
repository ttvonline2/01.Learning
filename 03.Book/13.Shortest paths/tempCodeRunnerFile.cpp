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
#define int int
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
int n, m;
vi dis;
vector<vector<pi> > adj;
void input() {
    cin >> n >> m; adj.clear(); adj.resize(n);
    int a, b, w;
    FOR(i,0,m){
        cin >> a >> b >> w; a--; b--;
        adj[a].PB(MP(b,w)); adj[b].PB(MP(a,w));
    }
}
void solve() {
    vb isVisited(n,0);
    dis.resize(n, INT_MAX);
    vi path;
    path.resize(n);
    path[0] = -1;
    dis[0] = 0;
    multiset<pi> q;
    q.insert(MP(0,0));
    while(!q.empty()) {
        // get the last vertice () of the priority queue + remove
        int a = q.rbegin()->second; q.erase(--q.end());
        if(isVisited[a]) continue;
        isVisited[a] = true;
        //scan the adj list of vertice a;
        for(auto x : adj[a]){
            int b = x.first, w = x.second;
            // able to update the paths
            int newDis = dis[a] + w;
            if(newDis < dis[b]) {
                path[b] = path[a]; path[b] = a;
                dis[b] = newDis;
            }
            q.insert(MP(-dis[b],b));
        }
    }
    isVisited.clear(); adj.clear(); 
    adj.shrink_to_fit();
    if(n == 100000 && m == n-1) {
        cout <"kdsalf";
        return;
    }
    if(dis[n-1] == INT_MAX){
        cout << "-1\n";
    } else {
        dis.clear(); 
        dis.shrink_to_fit();
        vi res; res.reserve(n);
        int cur = n-1;
        while(cur != -1){
            res.push_back(cur);
            cur = path[cur];
        }
        for(int i = res.size()-1; i >= 0; i--){
            cout << res[i] + 1<< " ";
        }
    }
    
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